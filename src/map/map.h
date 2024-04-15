#ifndef SRC_MAP_MAP_H_
#define SRC_MAP_MAP_H_

#include <utility>

#include "../set/set.h"

namespace MyNamespace {

template <typename Key, typename T>
class map : public set<std::pair<Key, T>> {
 public:
  using key_type = Key;
  using mapped_type = T;
  using value_type = std::pair<Key, T>;
  using reference = value_type &;
  using const_reference = const value_type &;
  using iterator = Iterator<value_type>;
  using const_iterator = ConstIterator<value_type>;
  using size_type = size_t;

  map();
  map(std::initializer_list<value_type> const &items);
  map(const map &m);
  map(map &&m);
  map<Key, T> &operator=(const map &m);
  map<Key, T> &operator=(map &&m);
  ~map();

  T &at(const Key &key);
  T &operator[](const Key &key);

  std::pair<iterator, bool> insert(const value_type &value);
  std::pair<iterator, bool> insert(const Key &key, const T &obj);
  std::pair<iterator, bool> insert_or_assign(const Key &key, const T &obj);
  template <typename... Args>
  std::vector<std::pair<iterator, bool>> insert_many(Args &&...args);

  void swap(map &other);
  void merge(map &other);

  bool contains(const Key &key);
  iterator find(const Key &key);
};

}  // namespace MyNamespace

#include "map.tpp"

#endif  // SRC_MAP_MAP_H_