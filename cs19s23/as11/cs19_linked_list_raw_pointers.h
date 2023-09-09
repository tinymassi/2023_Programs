#include <iostream>
#include <utility>

#ifndef _CS19_LINKED_LIST_RAW_POINTERS_H
#define _CS19_LINKED_LIST_RAW_POINTERS_H

namespace cs19 {

template <typename T> class LinkedList {
  struct Node;

 public:
  // Default constructor. **WRITTEN**
  LinkedList() {
  }

  // Constructs a list with a copy of each of the elements in init_list, in the
  // same order. **WRITTEN**
  LinkedList(std::initializer_list<T> init_list) {
    for (auto i : init_list) {
      push_back(i);
    }
  }

  // Constructs a container with a copy of each of the elements in another, in
  // the same order. **WRITTEN**
  LinkedList(const LinkedList &another) {
    Node *current = another.head;
    while (current != nullptr) {
      push_back(current->value);
      current = current->next;
    }
  }

  // Destroys each of the contained elements, and deallocates all memory
  // allocated by this list. **WRITTEN**
  ~LinkedList() {
    while (head != nullptr) {
      pop_back();
    }
  }

  // Inserts this list into an ostream, with the format [element1, element2,
  // element3, ...]. **WRITTEN**
  friend std::ostream &operator<<(std::ostream &out, const LinkedList &list) {
    out << "[";
    Node *current = list.head;
    while (current != nullptr) {
      if (current->next != nullptr) {
        out << current->value << ", ";
      } else {
        out << current->value;
      }
      current = current->next;
    }
    out << "]";
    return out;
  }

  // Replaces the contents of this list with a copy of each element in
  // init_list, in the same order. **WRITTEN**
  LinkedList &operator=(std::initializer_list<T> init_list) {
    if (size() > 0) {
      for (int i = 0; i < size(); i++) {
        pop_back();
      }
    }
    for (auto i : init_list) {
      push_back(i);
    }
    return *this;
  }

  // Replaces the contents of this list with a copy of each element in another,
  // in the same order. **WRITTEN**
  LinkedList &operator=(const LinkedList &another) {
    if (this != another) {
      if (size() > 0) {
        for (int i = 0; i < size(); i++) {
          pop_back();
        }
      }
      for (auto i : another) {
        push_back(i);
      }
    }
    return *this;
  }

  // Compares this list with another for equality. **WRITTEN**
  bool operator==(const LinkedList &another) {
    // **FIRST SCENARIO**
    // return !(this->operator!=(another));
    
    Node *current = head;
    Node *current_another = another.head;
    int similar_count = 0;
    if (size() == another.size()) {
      for (int i = 0; i < size(); i++) {
        if (current->value == current_another->value) {
          similar_count++;
        } else {
          break;
        }
        current = current->next;
        current_another = current_another->next;
      }
    }

    if (similar_count == size() && size() == another.size()) {
      return true;
    } else {
      return false;
    }

    // **SECOND SCENARIO**

    // if (size() != another.size()) {
    //   return false;
    // }
    // Node* current  = head;
    // Node* current_another = another.head;
    // while (current != nullptr && current_another != nullptr) {
    //   if (current->value != current_another->value) {
    //     return false;
    //   }
    //   current = current->next;
    //   current_another = current_another->next;
    // }
    // return true;
  }

  // Compares this list with another for inequality. **WRITTEN**
  bool operator!=(const LinkedList &another) {
    Node *current = head;
    Node *current_another = another.head;
    int difference_count = 0;
    if (size() == another.size()) {
      for (int i = 0; i < size(); i++) {
        if (current->value != current_another->value) {
          difference_count++;
          break;
        }
        current = current->next;
        current_another = current_another->next;
      }
    }

    if (difference_count == 1) {
      return true;
    } else {
      return false;
    }
  }

  // Returns whether the list container is empty (that is, whether its size is
  // 0) **WRITTEN**
  bool empty() const {
    if (size() > 0) {
      return false;
    } else {
      return true;
    }
  }

  // Returns the number of elements in this list. **WRITTEN**
  std::size_t size() const {
    std::size_t list_size = 0;
    Node *current = head;
    while (current != nullptr) {
      list_size++;
      current = current->next;
    }
    return list_size;
  }

  // Returns a reference to the value in the first element in this list.
  // **WRITTEN**
  T &front() const {
    if (head != nullptr) {
      return head->value;
    }

    throw std::domain_error("First element is nullptr");
  }

  // Returns a reference to the value in the last element in this list.
  // **WRITTEN**
  T &back() const {
    if (tail != nullptr) {
      return tail->value;
    }
    throw std::domain_error("Last element is nullptr");
  }

  // Appends a new element to this list, after its current last element.
  // **WRITTEN**
  void push_back(T val) {
    Node *new_tail = new Node();
    new_tail->value = val;
    new_tail->prev = tail;
    new_tail->next = nullptr;
    if (tail != nullptr) {
      tail->next = new_tail;
    }
    if (head == nullptr) {
      head = new_tail;
    }
    tail = new_tail;
  }

  // Prepends a new element to this list, before its current first element.
  // **WRITTEN**
  void push_front(T val) {
    Node *new_head = new Node();
    new_head->value = val;
    new_head->next = head;
    new_head->prev = nullptr;
    if (head != nullptr) {
      head->prev = new_head;
    }
    if (tail == nullptr) {
      tail = new_head;
    }
    head = new_head;
  }

  // Deletes the first value in this list. **WRITTEN**
  void pop_front() {
    if (head != nullptr) {
      if (tail == head) {
        delete head;
        tail = head = nullptr;
      } else {
        head = head->next;
        delete head->prev;
        head->prev = nullptr;
      }
    } else {
      throw std::domain_error("No elements in linked list hehe");
    }
  }

  // Deletes the last value in this list. **WRITTEN**
  void pop_back() {
    if (tail != nullptr) {
      if (tail == head) {
        delete tail;
        head = tail = nullptr;
      } else {
        tail = tail->prev;
        delete tail->next;
        tail->next = nullptr;
      }
    } else {
      throw std::domain_error("No elements in linked list hehe");
    }
  }

  // Resizes the list so that it contains n elements. **WRITTEN**
  void resize(std::size_t n) {
    if (n > size()) {
      while (n > size()) {
        push_back(T());
      }
    } else {
      while (n < size()) {
        pop_back();
      }
    }
  }

  // Resizes the list so that it contains n elements. **WRITTEN**
  void resize(std::size_t n, const T &fill_value) {
    if (n > size()) {
      while (n > size()) {
        push_back(fill_value);
      }
    } else {
      while (n < size()) {
        pop_back();
      }
    }
  }

  // Deletes all values in this list. **WRITTEN**
  void clear() {
    while (head != nullptr) {
      pop_back();
    }
  }

  // Removes from the container all the elements that compare equal to val.
  // **WRITTEN**
  void remove(const T &val) {
    Node *current = head;
    remove(current, val);
  }

  // Removes all nodes containing val after & including start **WRITTEN**
  void remove(Node *start, const T &val) {
    Node *current = start;
    while (current) {
      if (current->value == val) {
        current = current->next;
        if (current == nullptr) {
          pop_back();
          return;
        } else if (current->prev == head) {
          pop_front();
        } else {
          pop_mid(current->prev);
        }
      } else {
        current = current->next;
      }
      if (current == nullptr) {
        return;
      }
    }
  }

  // Removes duplicate values from this list. **WRITTEN**
  void unique() {
    if (head != nullptr) {
      Node *current = head;
      while (current != nullptr) {
        remove(current->next, current->value);
        current = current->next;
      }
    }
  }

  // Reverses the order of the elements in this list. **WRITTEN**
  void reverse() {
    if (head != nullptr) {
      Node *first = head;
      Node *last = tail;
      for (int i = 0; i < size() / 2; i++) {
        swap(first, last);
        first = first->next;
        last = last->prev;
      }
    }
  }

  // Removes a node from a list assuming it has a next & prev & is not head or
  // tail **WRITTEN**
  void pop_mid(Node *current) {
    if (current->next != nullptr && current->prev != nullptr) {
      Node *current_prev = current->prev;
      Node *current_next = current->next;

      current_prev->next = current->next;
      current_next->prev = current->prev;

      delete current;
    }
  }

  // Swaps two nodes based on if they are head, tail, or middle
  void swap(Node *front, Node *back) {
    auto temp1 = front->value;
    front->value = back->value;
    back->value = temp1;
  }

 private:
  struct Node {
    T value;
    Node *next;
    Node *prev;
  };
  Node *head = nullptr;
  Node *tail = nullptr;
};  // END OF CLASS

}  // namespace cs19

#endif  // _CS19_LINKED_LIST_RAW_POINTERS_H