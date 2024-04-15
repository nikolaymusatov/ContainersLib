#ifndef SRC_QUEUE_QUEUE_H_
#define SRC_QUEUE_QUEUE_H_

#include <cstddef>
#include <initializer_list>
#include <iostream>

#include "node.h"

namespace MyNamespace {

template <typename T>
class Queue {
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
  Queue();
  Queue(std::initializer_list<value_type> const& items);
  Queue(const Queue& q);
  Queue(Queue&& q);
  ~Queue();
  Queue& operator=(const Queue& q);
  Queue& operator=(Queue&& q);

  // Queue Element access
  const_reference front();
  const_reference back();

  // Queue Capacity
  size_type size();
  bool empty();

  // Queue Modifiers
  void push(const_reference value);
  void pop();
  void swap(Queue& other);

  // utils
  void erase();
  void copy(const Queue& s);
};

}  // namespace MyNamespace

#include "queue.tpp"

#endif  // SRC_QUEUE_QUEUE_H_