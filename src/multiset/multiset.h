#ifndef SRC_MULTISET_MULTISET_H_
#define SRC_MULTISET_MULTISET_H_

#include <cstddef>
#include <iostream>
#include <vector>

#include "../set/iterator.h"
#include "../set/node.h"

namespace MyNamespace {

template <typename Key>
class multiset {
 public:
  Node_t<Key>* root;
  size_t nodes_qnt;

  void delete_multiset(Node_t<Key>* node);
  Node_t<Key>* copy_multiset(Node_t<Key>* node, Node_t<Key>* parent);

 public:
  //  multiset Member type
  using key_type = Key;
  using value_type = Key;
  using reference = value_type&;
  using size_type = size_t;
  using const_reference = const value_type&;
  using iterator = Iterator<value_type>;
  using const_iterator = ConstIterator<value_type>;

  // multiset Member functions
  multiset();
  multiset(std::initializer_list<value_type> const& items);
  multiset(const multiset&);
  multiset(multiset&& ms);
  multiset& operator=(const multiset& ms);
  multiset<Key>& operator=(multiset&& ms);
  ~multiset();

  // multiset Capacity
  bool empty();
  size_type size();
  size_type max_size();

  // multiset Iterators
  iterator begin();
  iterator end();

  // multiset Modifiers
  void clear();
  iterator insert(const value_type& value);
  Node_t<value_type>* insert_node(Node_t<value_type>* node,
                                  const value_type& value);
  void erase(iterator pos);
  void swap(multiset& other);
  void merge(multiset& other);

  size_type count(const_reference key);
  std::pair<iterator, iterator> equal_range(const_reference key);
  iterator lower_bound(const_reference key);
  iterator upper_bound(const_reference key);

  template <typename... Args>
  std::vector<std::pair<iterator, bool>> insert_many(Args&&... args);

  // multiset Lookup
  iterator find(const_reference key);
  bool contains(const_reference key);
};

}  // namespace MyNamespace

#include "multiset.tpp"

#endif  // SRC_MULTISET_MULTISET_H_