#ifndef SRC_STACK_STACK_H_
#define SRC_STACK_STACK_H_

#include <cstddef>
#include <initializer_list>
#include <iostream>

#include "queue/node.h"

namespace MyNamespace {

template <typename T>
class stack {
 private:
  Node<T>* top_node;

  // Stack Member type
  using value_type = T;
  using reference = value_type&;
  using const_reference = const value_type&;
  using size_type = size_t;

 public:
  // Stack Member functions
  stack();
  stack(std::initializer_list<value_type> const& items);
  stack(const stack& s);
  stack(stack&& s);
  ~stack();
  stack& operator=(const stack& s);
  stack& operator=(stack&& s);

  // Stack Element access
  const_reference top();

  // Stack Capacity
  size_type size();
  bool empty();

  // Stack Modifiers
  void push(const_reference value);
  void pop();
  void swap(stack& other);

  // utils
  void erase();
  void copy(const stack& s);
};

}  // namespace MyNamespace

#include "stack.tpp"

#endif  // SRC_STACK_STACK_H_