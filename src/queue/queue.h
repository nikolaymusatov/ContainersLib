#ifndef SRC_QUEUE_QUEUE_H_
#define SRC_QUEUE_QUEUE_H_

#include <cstddef>
#include <initializer_list>
#include <iostream>

#include "node.h"

namespace MyNamespace {

template <typename T>
class queue {
 private:
  Node<T>* head;
  Node<T>* tail;

  // Queue Member type
  using value_type = T;
  using reference = value_type&;
  using const_reference = const value_type&;
  using size_type = size_t;

 public:
  // Queue Member functions
  queue();
  queue(std::initializer_list<value_type> const& items);
  queue(const queue& q);
  queue(queue&& q);
  ~queue();
  queue& operator=(const queue& q);
  queue& operator=(queue&& q);

  // Queue Element access
  const_reference front();
  const_reference back();

  // Queue Capacity
  size_type size();
  bool empty();

  // Queue Modifiers
  void push(const_reference value);
  void pop();
  void swap(queue& other);

  // utils
  void erase();
  void copy(const queue& s);
};

}  // namespace MyNamespace

#include "queue.tpp"

#endif  // SRC_QUEUE_QUEUE_H_