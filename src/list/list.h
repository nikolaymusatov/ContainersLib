#ifndef SRC_LIST_LIST_H
#define SRC_LIST_LIST_H

#include <stddef.h>

#include <cassert>
#include <initializer_list>
#include <utility>

namespace MyNamespace {

template <typename T>
class List {
 public:
  class ListIterator;

  class ListConstIterator;

  // Member types
  using value_type = T;
  using reference = T &;
  using const_reference = const T &;
  using iterator = ListIterator;
  using const_iterator = ListConstIterator;
  using size_type = size_t;

  // List Functions
  List();
  List(size_type n);
  List(std::initializer_list<value_type> const &items);
  List(const List &l);
  ~List();
  List(List &&l);
  List<T> &operator=(const List &l);
  List<T> &operator=(List &&l);

  bool empty() const;

  size_type size() const;

  // List Modifiers
  void push_front(const_reference value);
  void push_back(const_reference value);
  void pop_front();
  void pop_back();
  void erase(iterator pos);
  void clear();
  void swap(List &other);
  void merge(List &other);
  void splice(const_iterator pos, List &other);
  void reverse();
  void unique();
  void sort();

  const_reference front() const;
  const_reference back() const;
  const_iterator begin() const;
  const_iterator end() const;

  iterator begin();
  iterator end();

  iterator insert(iterator pos, const_reference value);

  template <typename... Args>
  iterator insert_many(const_iterator pos, Args &&...args);

  template <typename... Args>
  void insert_many_back(Args &&...args);

  template <typename... Args>
  void insert_many_front(Args &&...args);

 private:
  struct BaseNode {
    BaseNode *next_ = nullptr;
    BaseNode *prev_ = nullptr;

    BaseNode(BaseNode *next, BaseNode *prev);
    BaseNode() = default;
  };

  struct Node : BaseNode {
    value_type data_;
    Node(T data);
    Node(BaseNode *next, BaseNode *prev, T data);
  };

 public:
  class ListIterator {
   public:
    explicit ListIterator(BaseNode *ptr = nullptr);
    reference operator*();
    iterator &operator++();
    iterator operator++(int);
    iterator &operator--();
    iterator operator--(int);
    bool operator==(iterator other) const;
    bool operator!=(iterator other) const;

    BaseNode *ptr_;
  };

  class ListConstIterator : public ListIterator {
   public:
    explicit ListConstIterator(BaseNode *ptr = nullptr) : ListIterator(ptr) {}
    const_reference operator*() const;
  };

 private:
  BaseNode *head_;
  BaseNode *tail_;
  size_type size_;
  BaseNode *end_node_;
};

}  // namespace MyNamespace

#include "list.tpp"

#endif  // SRC_LIST_LIST_H