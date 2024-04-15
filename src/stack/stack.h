#ifndef SRC_STACK_STACK_H_
#define SRC_STACK_STACK_H_

#include <cstddef>
#include <initializer_list>
#include <iostream>

#include "queue/node.h"

namespace MyNamespace {

template <typename T>
class Stack {
 private:
  Node<T>* top_node;

  // Stack Member type
  using value_type = T;
  using reference = value_type&;
  using const_reference = const value_type&;
  using size_type = size_t;

 public:
  // Stack Member functions
  Stack();
  Stack(std::initializer_list<value_type> const& items);
  Stack(const Stack& s);
  Stack(Stack&& s);
  ~Stack();
  Stack& operator=(const Stack& s);
  Stack& operator=(Stack&& s);

  // Stack Element access
  const_reference top();

  // Stack Capacity
  size_type size();
  bool empty();

  // Stack Modifiers
  void push(const_reference value);
  void pop();
  void swap(Stack& other);

  // utils
  void erase();
  void copy(const Stack& s);
};

}  // namespace MyNamespace

#include "stack.tpp"

#endif  // SRC_STACK_STACK_H_