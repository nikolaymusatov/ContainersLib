#ifndef SRC_SET_SET_H_
#define SRC_SET_SET_H_

#include <cstddef>
#include <iostream>

#include "iterator.h"
#include "node.h"

namespace MyNamespace {

template <typename Key>
class Set {
 public:
  //  Set Member type
  using key_type = Key;
  using value_type = Key;
  using reference = value_type &;
  using size_type = size_t;
  using const_reference = const value_type &;
  using iterator = Iterator<value_type>;
  using const_iterator = ConstIterator<value_type>;

 protected:
  Node_t<Key> *root;
  size_t nodes_qnt;

  void delete_set(Node_t<Key> *node);
  Node_t<Key> *copy_set(Node_t<Key> *node, Node_t<Key> *parent);
  void insert_(const_reference key);

 public:
  // Set Member functions
  Set();
  Set(std::initializer_list<value_type> const &items);
  Set(const Set &);
  Set(Set &&s);
  Set &operator=(const Set &s);
  Set<Key> &operator=(Set &&s);
  ~Set();

  // Set Capacity
  bool empty();
  size_type size();
  size_type max_size();

  // Set Iterators
  iterator begin();
  iterator end();

  const_iterator cbegin() const;
  const_iterator cend() const;

  // Set Modifiers
  void clear();
  std::pair<iterator, bool> insert(const_reference value);
  template <typename... Args>
  std::vector<std::pair<iterator, bool>> insert_many(Args &&...args);
  void erase(iterator pos);
  void swap(Set &other);
  void merge(Set &other);

  // Set Lookup
  iterator find(const_reference key);
  bool contains(const_reference key);
};

}  // namespace MyNamespace

#include "Set.tpp"

#endif  // SRC_SET_SET_H_
