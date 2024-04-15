#ifndef SRC_ARRAY_ARRAY_H_
#define SRC_ARRAY_ARRAY_H_

#include <iostream>

namespace MyNamespace {

template <typename T, std::size_t N>
struct array {
  T arr[N];

  // Array Member type
  using value_type = T;
  using reference = T &;
  using size_type = size_t;
  using const_reference = const T &;
  using iterator = T *;
  using const_iterator = const T *;

  // Array Element access
  reference at(size_type pos) {
    if (pos <= N)
      return arr[pos];
    else
      throw "Array index is out of range";
  }

  reference operator[](size_type pos) { return arr[pos]; }

  const_reference front() { return arr[0]; }

  const_reference back() { return arr[N - 1]; }

  iterator data() {
    if (N == 0)
      return nullptr;
    else
      return &arr[0];
  };

  // Array Iterators
  iterator begin() { return &arr[0]; }

  iterator end() { return &arr[N]; }

  // Array Capacity
  bool empty() { return N == 0 ? true : false; }

  size_type size() { return N; }

  size_type max_size() { return N; };

  // Array Modifiers
  void swap(array &other) { std::swap(this->arr, other.arr); }

  void fill(const_reference value) {
    for (size_type i = 0; i < N; i++) arr[i] = value;
  }
};

}  // namespace MyNamespace

#endif  // SRC_ARRAY_ARRAY_H_