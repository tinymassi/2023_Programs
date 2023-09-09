/**
 * @file cs19_compact_string_set.h
 *
 * A first-draft interface of our specialized string set. No destructor yet.
 *
 * @author Jeffrey Bergamini for CS 19, jeffrey.bergamini@cabrillo.edu
 */
#ifndef CS19_COMPACT_STRING_SET_H_
#define CS19_COMPACT_STRING_SET_H_

#include <memory>
#include <queue>
#include <string>
#include <utility>
#include <vector>

namespace cs19 {

class CompactStringSet {
  struct Node {
    char letter;
    bool terminal = false;
    std::unique_ptr<Node> sibling = nullptr;
    std::unique_ptr<Node> child = nullptr;
  };

  struct Iterator {
    using iterator_category = std::input_iterator_tag;
    using value_type = std::string;
    using difference_type = int;
    using pointer = std::string*;
    using reference = std::string&;
    std::queue<std::pair<const Node *, std::string>> Q;

    Iterator() {}

    Iterator(Node *n, std::string str) { Q.emplace(n, str); }

    // prefix increment: moves forward in the range object
    Iterator &operator++() {
      const Node *cur = nullptr;
      do {
        cur = Q.front().first;
        std::string str = Q.front().second;
        Q.pop();
        if (cur->child) {
          Node *temp = cur->child.get();
          while (temp) {
            Q.emplace(temp, str + temp->letter);
            temp = temp->sibling.get();
          }
        }
      } while (Q.size() && !Q.front().first->terminal);
      return *this;
    }

    // postfix increment: moves forward in the range object (evaluates to
    // previous state) returns state b4 increment
    Iterator operator++(int) {
      Iterator tmp(*this);
      this->operator++();
      return tmp;
    }

    // equality: LHS and RHS represent the same position in the same range
    bool operator==(Iterator that) const {
      if (Q.size() == that.Q.size()) {
        if (Q.size() > 0 && Q.front().second == that.Q.front().second) {
          return true;
        }
        return true;
      } else {
        return false;
      }
    }

    // inequality: LHS and RHS don't represent the same position in the same
    // range
    bool operator!=(Iterator that) const { return !(*this == that); }

    // rvalue dereference: returns the value indicated by this iterator's
    // position in its range
    std::string operator*() { return Q.front().second; }
  };

 public:
  /**
   * Inserts a string into this set, if not already present.
   *
   * @param value the string to insert
   * @return whether the string was inserted (i.e., whether it was a new
   * addition to the set)
   */
  bool insert(const std::string &value);

  /**
   * Searches this set for a given string.
   *
   * @param the string to search for
   * @return whether the string exists in this set
   */
  bool contains(const std::string &value) const;

  /**
   * Removes a string from this set, if present. Deleting subsequently unused
   * nodes is optional.
   *
   * @param value the string to remove
   * @return whether the string had been present in the set
   */
  bool erase(const std::string &value);

  /**
   * Returns the number of strings in this set.
   */
  std::size_t size() const;

  /**
   * Returns an iterator to the first element of the set. A CompactStringSet
   * makes no guarantees as to which specific string is considered its first
   * element. But, in any case, the range begin() to end() covers all the
   * strings in the set. If the set is empty, the returned iterator will be
   * equal to end().
   */
  // Iterator begin();  // check the range example in week 12
  Iterator begin();

  /**
   * Returns an iterator to the element following the last element of the set.
   * This element acts as a placeholder; attempting to access it results in
   * undefined behavior.
   */
  // Iterator end();
  Iterator end();

  /**
   * Returns the closest n strings to the given string, in "autocomplete"
   * fashion. Proximity shall be measured as follows: A child node is the
   * closest to a given node, and any of its siblings are the next closest, in
   * order of their sibling links.
   *
   * @param base the string from which to suggest autocompletions
   * @param n the maximum number of autocompletions to return
   * @return at most n autocompletions of the base, in descending order of
   * proximity from the base
   */
  std::vector<std::string> autocomplete(const std::string &base,
                                        std::size_t n) const;

 private:
  Node root_{0};  // A dummy node for the starting point of the set
  std::size_t num_strings_ = 0;  // The number of strings in the set
  Node *find_next(const Node *base,
                  char to_find) const;  // Returns matching child or sibling node
};

}  // namespace cs19

#endif