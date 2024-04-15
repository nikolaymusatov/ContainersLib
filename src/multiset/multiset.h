#ifndef SRC_MULTISET_MULTISET_H_
#define SRC_MULTISET_MULTISET_H_

#include <cstddef>
#include <iostream>
#include <vector>

#include "../set/iterator.h"
#include "../set/node.h"

namespace MyNamespace {

template <typename Key>
class Multiset {
 public:
  Node_t<Key>* root;
  size_t nodes_qnt;

  void delete_multiset(Node_t<Key>* node);
  Node_t<Key>* copy_multiset(Node_t<Key>* node, Node_t<Key>* parent);

 public:
  //  Multiset Member type
  using key_type = Key;
  using value_type = Key;
  using reference = value_type&;
  using size_type = size_t;
  using const_reference = const value_type&;
  using iterator = Iterator<value_type>;
  using const_iterator = ConstIterator<value_type>;

  // Multiset Member functions
  Multiset();
  Multiset(std::initializer_list<value_type> const& items);
  Multiset(const Multiset&);
  Multiset(Multiset&& ms);
  Multiset& operator=(const Multiset& ms);
  Multiset<Key>& operator=(Multiset&& ms);
  ~Multiset();

  // Multiset Capacity
  bool empty();
  size_type size();
  size_type max_size();

  // Multiset Iterators
  iterator begin();
  iterator end();

  // Multiset Modifiers
  void clear();
  iterator insert(const value_type& value);
  Node_t<value_type>* insert_node(Node_t<value_type>* node,
                                  const value_type& value);
  void erase(iterator pos);
  void swap(Multiset& other);
  void merge(Multiset& other);

  size_type count(const_reference key);
  std::pair<iterator, iterator> equal_range(const_reference key);
  iterator lower_bound(const_reference key);
  iterator upper_bound(const_reference key);

  template <typename... Args>
  std::vector<std::pair<iterator, bool>> insert_many(Args&&... args);

  // Multiset Lookup
  iterator find(const_reference key);
  bool contains(const_reference key);
};

}  // namespace MyNamespace

#include "multiset.tpp"

#endif  // SRC_MULTISET_MULTISET_H_