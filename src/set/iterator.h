#ifndef SRC_SET_ITERATOR_H_
#define SRC_SET_ITERATOR_H_

#include "node.h"

namespace MyNamespace {

template <typename T>
class Iterator {
 protected:
  Node_t<T> *ptr_;

 public:
  explicit Iterator(Node_t<T> *ptr) : ptr_(ptr){};

  T &operator*() { return ptr_->value; };

  T *operator->() { return &(ptr_->value); };

  Iterator &operator++() {
    if (ptr_ == nullptr) {
      return *this;
    }
    if (ptr_->right != nullptr) {
      ptr_ = ptr_->right;
      while (ptr_->left != nullptr) ptr_ = ptr_->left;
    } else {
      auto parent = ptr_->parent;
      while (parent != nullptr && ptr_ == parent->right) {
        ptr_ = parent;
        parent = parent->parent;
      }
      ptr_ = parent;
    }
    return *this;
  }

  Iterator operator++(int) {
    Iterator copy = *this;
    ++(*this);
    return copy;
  }

  Iterator &operator--() {
    if (ptr_->left) {
      ptr_ = ptr_->left;
      while (ptr_->right) ptr_ = ptr_->right;
    } else {
      while (ptr_->parent && ptr_->value < ptr_->parent->value)
        ptr_ = ptr_->parent;
      ptr_ = ptr_->parent;
    }
    return *this;
  }

  Iterator operator--(int) {
    Iterator copy = *this;
    --(*this);
    return copy;
  }

  bool operator==(const Iterator other) const { return (ptr_ == other.ptr_); }

  bool operator!=(const Iterator other) const { return (ptr_ != other.ptr_); };

  Node_t<T> *get_node() { return this->ptr_; }
};

template <typename T>
class ConstIterator : public Iterator<T> {
 public:
  explicit ConstIterator(Node_t<T> *ptr) : Iterator<T>(ptr){};

  const T &operator*() const { return Iterator<T>::ptr_->value; };
};

}  // namespace MyNamespace

#endif  // SRC_SET_ITERATOR_H_
