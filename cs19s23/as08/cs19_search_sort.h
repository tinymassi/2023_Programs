#ifndef CS19_SEARCH_SORT_H_
#define CS19_SEARCH_SORT_H_

/**
 * Namespace cs19 contains functions for our search and sort assignment.
 *
 * @author Some Student for CS 19, somestudent@jeff.cis.cabrillo.edu
 */
namespace cs19 {

/**
 * Returns an iterator to the first element in the range `[first,last)` that
 * compares equal to `val`. If no such element is found, the function returns
 * `last`.
 *
 * @tparam Iterator a position iterator that supports the [standard input
 * iterator
 * operations](http://www.cplusplus.com/reference/iterator/InputIterator/)
 * @tparam Value a value type that supports `operator==`
 *
 * @param first the initial position in the sequence to be sorted
 * @param last one element past the final position in the sequence to be sorted
 * @param val the value for which to search
 * @return an iterator to the first element in the range that compares equal to
 * `val`. If no elements match, the function returns `last`.
 */
template <typename Iterator, typename Value>
Iterator linear_search(Iterator first, Iterator last, const Value &val) {

  for (; first != last;
       ++first) { // not sure if this is valid iterator syntax... i dont
                  // remember how iterators work
    if (*first == val) {
      return first;
    }
  }
  return last; // TODO
}

/**
 * Performs an index-based linear search on an indexable object for a given
 * value.
 *
 * @tparam IndexedContainer must support `operator[]` and `size()`, e.g.
 * `std::vector`. Container elements must be of template type `Value`.
 * @tparam Value a value type that supports `operator==`
 *
 * @param haystack the object to search
 * @param needle the value for which to search
 * @return the first index found via linear search at which `haystack` contains
 * `needle`, or `-1` if `haystack` does not contain `needle`
 */
template <typename IndexedContainer, typename Value>
int linear_search(const IndexedContainer &haystack, const Value &needle) {
  for (int i = 0; i < haystack.size(); ++i) {
    if (haystack[i] == needle) {
      return i;
    }
  }
  return -1; // TODO
}

/**
 * Performs an index-based binary search on an indexable object for a given
 * value.
 *
 * @tparam IndexedContainer must support `operator[]` and `size()`, e.g.
 * `std::vector`. Container elements must be of template type `Value`.
 * @tparam Value a value type that supports `operator==` and `operator<`
 *
 * @param haystack the object to search
 * @param needle the value for which to search
 * @return the first index found via binary search at which `haystack` contains
 * `needle`, or `-1` if `haystack` does not contain `needle`
 */
template <typename IndexedContainer, typename Value>
int binary_search(const IndexedContainer &haystack, const Value &needle) {
  int low = 0;
  int high = haystack.size();
  int mid = 0;

  while (low <= high) {
    mid = (low + high) / 2;
    if (haystack[mid] == needle) {
      return mid;
    } else if (haystack[mid] < needle) {
      low = mid + 1;
    } else {
      high = mid + 1;
    }
  }
  return -1; // TODO
}

/**
 * Performs an index-based bubble sort on any indexable container object.
 *
 * @tparam IndexedContainer must support `operator[]` and `size()`, e.g.
 * `std::vector`. Container elements must support `operator<` and `operator=`.
 *
 * @param values the object to sort
 */
template <typename IndexedContainer>
void bubble_sort(IndexedContainer &values) {
  bool done = false;
  int swap = 0;
  auto temp = values[0];
  while (!done) {
    for (int i = 0; i < values.size() - 1; ++i) {
      if (values[i] > values[i + 1]) {
        temp = values[i];
        values[i] = values[i + 1];
        values[i + 1] = temp;
        swap++;
      }
    }
    if (swap == 0) {
      done = true;
    }
    swap = 0;
  }
}

/**
 * Sorts the elements in the range `[first,last)` into ascending order, using
 * the bubble-sort algorithm. The elements are compared using `operator<`.
 *
 * @tparam Iterator a position iterator that supports the [standard
 * bidirectional iterator
 * operations](http://www.cplusplus.com/reference/iterator/BidirectionalIterator/)
 *
 * @param first the initial position in the sequence to be sorted
 * @param last one element past the final position in the sequence to be sorted
 */
template <typename Iterator> void bubble_sort(Iterator first, Iterator last) {
  bool done = false;
  int swap = 0;
  auto temp = *first;
  Iterator restart = first;
  Iterator next;
  --last;
  while (!done) {
    for (; first != last;) {
      next = first++;
      if (*first < *next) {
        temp = *first;
        *first = *next;
        *next = temp;
        swap++;
      }
    }
    if (swap == 0) {
      done = true;
    }
    swap = 0;
    first = restart;
  }
}

/**
 * Performs an index-based selection sort on an indexable object.
 *
 * @tparam IndexedContainer must support `operator[]` and `size()`, e.g.
 * `std::vector`. Container elements must support `operator<` and `operator=`.
 *
 * @param values the object to sort
 */
template <typename IndexedContainer>
void selection_sort(IndexedContainer &values) {
  bool new_min = false;
  for (int i = 0; i < values.size() - 1; ++i) {
    auto min = i;
    new_min = false;
    for (int k = i + 1; k < values.size(); ++k) {
      if (values[k] < values[min]) {
        min = k;
        new_min = true;
      }
    }
    if (new_min == true) {
      auto temp = values[min];
      values[min] = values[i];
      values[i] = temp;
    }
  }
}

/**
 * Sorts the elements in the range `[first,last)` into ascending order, using
 * the selection-sort algorithm.
 *
 * @tparam Iterator a position iterator that supports the [standard input
 * iterator
 * operations](http://www.cplusplus.com/reference/iterator/InputIterator/)
 *
 * @param first the initial position in the sequence to be sorted
 * @param last one element past the final position in the sequence to be sorted
 */
template <typename Iterator>
void selection_sort(Iterator first, Iterator last) {
  bool new_min = false;
  auto temp = *first;
  for (; first != last; ++first) {
    Iterator min = first;
    new_min = false;
    for (Iterator sec_search = ++first; sec_search != last; ++sec_search) {
      if (*sec_search < *min) {
        min = sec_search;
        new_min = true;
      }
    }
    first--;
    if (new_min == true) {
      temp = *min;
      *min = *first;
      *first = temp;
    }
  }
}

} // namespace cs19

#endif // CS19_SEARCH_SORT_H_