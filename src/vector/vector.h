#ifndef SRC_VECTOR_VECTOR_H
#define SRC_VECTOR_VECTOR_H

#define VECTOR Vector<value_type>
#define BASE_ITERATOR BaseIterator<iterator_type, reference_type>

#include <limits>
#include <memory>

namespace MyNamespace {

template <typename value_type>
class Vector {
 public:
  using size_type = std::size_t;
  using pointer = value_type *;
  using reference = value_type &;
  using const_reference = const value_type &;

 private:
  pointer ptr_ = nullptr;
  size_type size_ = 0;
  size_type capacity_ = 0;

  template <typename iterator_type, typename reference_type>
  class BaseIterator {
   public:
    BaseIterator() noexcept = default;
    reference_type operator*() const;
    iterator_type operator++();
    iterator_type operator--();
    iterator_type operator+(int n);
    auto operator-(const iterator_type &other) const;
    bool operator==(const iterator_type &other) const;
    bool operator!=(const iterator_type &other) const;

   protected:
    pointer iterator_ptr_ = nullptr;
  };

 public:
  class VectorConstIterator
      : public BaseIterator<VectorConstIterator, const_reference> {
   public:
    using iterator = VectorConstIterator;
    using const_iterator = VectorConstIterator;

    VectorConstIterator() noexcept = default;
    VectorConstIterator(const pointer &other);
    VectorConstIterator(const iterator &other);
    ~VectorConstIterator();
  };

  class VectorIterator : public BaseIterator<VectorIterator, reference> {
   public:
    using iterator = VectorIterator;
    using const_iterator = VectorConstIterator;

    VectorIterator() noexcept = default;
    VectorIterator(const pointer &other);
    ~VectorIterator();

    operator VectorConstIterator();
  };

  // iterators
  using iterator = VectorIterator;
  using const_iterator = VectorConstIterator;

  iterator begin();
  iterator end();
  const_iterator begin() const;
  const_iterator end() const;

  // constructors
  explicit Vector() = default;
  explicit Vector(size_type size);
  Vector(std::initializer_list<value_type> const &items);
  Vector(const Vector &v);
  Vector(Vector &&v) noexcept;
  ~Vector();

  // operators
  Vector &operator=(Vector &&v) noexcept;
  Vector &operator=(const Vector &v);
  reference operator[](size_type pos);

  // access elements function
  reference at(size_type pos);
  const_reference front();
  const_reference back();
  pointer data();

  // capacity information functions
  bool empty() const noexcept;
  size_type size() const noexcept;
  size_type max_size() const noexcept;
  size_type capacity() const;

  // modifiers functions
  iterator insert(iterator pos, const_reference value);
  void resize(size_type size);
  void push_back(const_reference value);
  void push_back(value_type &&value);
  void shrink_to_fit();
  void reserve(size_type size);
  void swap(Vector &other);
  void erase(iterator pos);
  void pop_back();
  void clear();

 private:
  // internal implementation
  size_type calculate_capacity(size_type size) noexcept;
  void allocate_volume(size_type new_size, size_type new_capacity,
                       iterator begin_deadzone = nullptr,
                       iterator end_deadzone = nullptr);
  void switch_pointer(pointer &new_alloc, pointer &old_alloc,
                      size_type new_size,
                      Vector::iterator begin_deadzone = nullptr,
                      Vector::iterator end_deadzone = nullptr);
  size_type calculate_deadzone(Vector::iterator begin,
                               Vector::iterator end = nullptr);
  void delete_vector(Vector &v);
};

}  // namespace MyNamespace

#include "vector.tpp"

#endif  // SRC_VECTOR_VECTOR_H