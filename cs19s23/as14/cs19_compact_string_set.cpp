#include "cs19_compact_string_set.h"
#include <memory>
#include <queue>
#include <string>
#include <utility>
#include <vector>

namespace cs19 {

/**
 * Inserts a string into this set, if not already present.
 *
 * @param value the string to insert
 * @return whether the string was inserted (i.e., whether it was a new addition
 * to the set)
 */
bool CompactStringSet::insert(const std::string &value) {
  Node *cur = &this->root_;       // Start at the dummy "root" node.
  for (auto character : value) {  // For each character...
    Node *search = this->find_next(
        cur, character);  // ... find a child containing the character.
    if (search) {         // If  such a node exists...
      cur = search;       // ... nothing to do. We just move on.
    } else {              // ... otherwise, we need to insert a new node.
      Node *new_node = new Node{character};
      if (cur->child) {          // This node already has a child...
        cur = cur->child.get();  // ... so its child needs a sibling.
        while (cur->sibling)
          cur = cur->sibling.get();  // Find the last sibling...
        cur->sibling =
            std::unique_ptr<Node>(new_node);  // ... and give it a new sibling.
      } else {
        cur->child = std::unique_ptr<Node>(
            new_node);  // This node is childless. Let's give it one.
      }
      cur = new_node;
    }
  }
  if (!cur->terminal) {    // If the stopping point was not already marked as
                           // terminal...
    ++this->num_strings_;  // ... we inserted a new string
    cur->terminal =
        true;  // ... and the stopping point needs to be marked as such.
    return true;
  }
  return false;
}

/**
 * Searches this set for a given string.
 *
 * @param the string to search for
 * @return whether the string exists in this set
 */
bool CompactStringSet::contains(const std::string &value) const {
  const Node *cur = &this->root_;  // Start at the dummy "root" node.
  for (auto character : value) {   // For each character...
    cur = this->find_next(
        cur, character);  // ... find a child of this node containing the char
    if (!cur)
      return false;  // ... otherwise, this string must not be in the set
  }
  return cur->terminal;  // This set contains the string if the last char was
                         // marked as terminal
}

/**
 * Removes a string from this set, if present. Deleting subsequently unused
 * nodes is optional.
 *
 * @param value the string to remove
 * @return whether the string had been present in the set
 */
bool CompactStringSet::erase(const std::string &value) {
  Node *cur = &this->root_;           // starting at the root of the tree...
  bool val_exists = contains(value);  // check if the string is in the tree...

  if (val_exists) {                 // if the string is in the tree,
    for (auto character : value) {  // go through each of its characters
      cur = this->find_next(
          cur, character);  // find the child nodes of each character
    }
  } else {              // if the string is not in the tree
    return val_exists;  // return false as its not there
  }
  cur->terminal = false;
  --num_strings_;  // we have reached the terminal node of value
  return true;  // by setting it to false we have "removed" the string from the
                // tree
}

/**
 * Returns the number of strings in this set.
 */
std::size_t CompactStringSet::size() const { return this->num_strings_; }

/**
 * Returns an iterator to the first element of the set. A CompactStringSet makes
 * no guarantees as to which specific string is considered its first element.
 * But, in any case, the range begin() to end() covers all the strings in the
 * set. If the set is empty, the returned iterator will be equal to end().
 */
CompactStringSet::Iterator CompactStringSet::begin() {
  Iterator it(&this->root_, "");
  ++it;
  return it;
}

/**
 * Returns an iterator to the element following the last element of the set.
 * This element acts as a placeholder; attempting to access it results in
 * undefined behavior.
 */
CompactStringSet::Iterator CompactStringSet::end() { return Iterator(); }

/**
 * Returns the closest n strings to the given string, in "autocomplete" fashion.
 * Proximity shall be measured as follows: A child node is the closest to a
 * given node, and any of its siblings are the next closest, in order of their
 * sibling links.
 *
 * @param base the string from which to suggest autocompletions
 * @param n the maximum number of autocompletions to return
 * @return at most n autocompletions of the base, in descending order of
 * proximity from the base
 */
std::vector<std::string> CompactStringSet::autocomplete(const std::string &base,
                                                        std::size_t n) const {
  std::vector<std::string> word_recs;
  std::queue<std::pair<const Node *, std::string>> node_str_q;
  const Node *cur = &this->root_;
  if (base.length() == 0) {
    return word_recs;
  }
  if (n == 0) {
    return word_recs;
  }
  for (auto character : base) {
    if (cur) {
      cur = this->find_next(cur, character);
    } else {
      break;
    }
  }
  std::string str = base;
  node_str_q.emplace(cur, base);
  if (cur) {
    while (!node_str_q.empty() && word_recs.size() < n) {
      cur = node_str_q.front().first;
      str = node_str_q.front().second;
      node_str_q.pop();
      if (cur->child != nullptr) {  // this is where the fun begins
        Node *temp = cur->child.get();
        while (temp) {
          if (temp->terminal) {
            word_recs.push_back(str + temp->letter);
            if (word_recs.size() >= n) {
              return word_recs;
            }
          }
          node_str_q.emplace(temp, str + temp->letter);
          temp = temp->sibling.get();
        }
      }
    }
  }
  return word_recs;
}

CompactStringSet::Node *CompactStringSet::find_next(
    const Node *base,
    char to_find) const {  // Returns matching child or sibling node
  if (base->child) {
    if (base->child->letter == to_find)
      return base->child.get();
    Node *sibling = base->child.get()->sibling.get();
    while (sibling) {
      if (sibling->letter == to_find)
        return sibling;
      sibling = sibling->sibling.get();
    }
  }
  return nullptr;  // No match found
}

};  // namespace cs19