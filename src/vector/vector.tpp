using namespace MyNamespace;

// constructors
template <typename value_type>
VECTOR::Vector(size_type size) {
  size_type new_capacity = calculate_capacity(size);
  ptr_ = new value_type[new_capacity];
  size_ = size;
  capacity_ = new_capacity;
}

template <typename value_type>
VECTOR::Vector(std::initializer_list<value_type> const &items) {
  size_type new_capacity = calculate_capacity(items.size());
  ptr_ = new value_type[new_capacity];
  size_ = items.size();
  capacity_ = new_capacity;
  for (int i = 0; i < size_; ++i) {
    ptr_[i] = items.begin()[i];
  }
}

template <typename value_type>
VECTOR::Vector(const Vector &v) {
  ptr_ = new value_type[v.capacity_];
  size_ = v.size_;
  capacity_ = v.capacity_;
  for (int i = 0; i < v.size_; ++i) {
    ptr_[i] = v.ptr_[i];
  }
}

template <typename value_type>
VECTOR::Vector(Vector &&v) noexcept {
  ptr_ = v.ptr_;
  size_ = v.size_;
  capacity_ = v.capacity_;
  v.ptr_ = nullptr;
  v.size_ = 0;
  v.capacity_ = 0;
}

template <typename value_type>
VECTOR::~Vector() {
  delete_vector(*this);
}

// iterators
template <typename value_type>
typename VECTOR::iterator VECTOR::end() {
  return iterator(ptr_ + size_);
}

template <typename value_type>
typename VECTOR::iterator VECTOR::begin() {
  return iterator(ptr_);
}

template <typename value_type>
typename VECTOR::const_iterator VECTOR::end() const {
  return const_iterator(ptr_ + size_);
}

template <typename value_type>
typename VECTOR::const_iterator VECTOR::begin() const {
  return const_iterator(ptr_);
}

template <typename value_type>
VECTOR::VectorIterator::~VectorIterator() {
  this->iterator_ptr_ = nullptr;
}

template <typename value_type>
VECTOR::VectorIterator::operator VectorConstIterator() {
  return VectorConstIterator(this->iterator_ptr_);
}

template <typename value_type>
VECTOR::VectorIterator::VectorIterator(Vector::pointer const &other) {
  this->iterator_ptr_ = other;
}

template <typename value_type>
VECTOR::VectorConstIterator::VectorConstIterator(Vector::pointer const &other) {
  this->iterator_ptr_ = other;
}

template <typename value_type>
VECTOR::VectorConstIterator::VectorConstIterator(
    const Vector::VectorConstIterator::iterator &other) {
  this->iterator_ptr_ = other.iterator_ptr_;
}

template <typename value_type>
VECTOR::VectorConstIterator::~VectorConstIterator() {
  this->iterator_ptr_ = nullptr;
}

template <typename value_type>
template <typename iterator_type, typename reference_type>
bool VECTOR::BASE_ITERATOR::operator!=(const iterator_type &other) const {
  return this->iterator_ptr_ != other.iterator_ptr_;
}

template <typename value_type>
template <typename iterator_type, typename reference_type>
bool VECTOR::BASE_ITERATOR::operator==(const iterator_type &other) const {
  return this->iterator_ptr_ == other.iterator_ptr_;
}

template <typename value_type>
template <typename iterator_type, typename reference_type>
iterator_type VECTOR::BASE_ITERATOR::operator--() {
  this->iterator_ptr_--;
  return iterator_type(this->iterator_ptr_);
}

template <typename value_type>
template <typename iterator_type, typename reference_type>
iterator_type VECTOR::BASE_ITERATOR::operator++() {
  this->iterator_ptr_++;
  return iterator_type(this->iterator_ptr_);
}

template <typename value_type>
template <typename iterator_type, typename reference_type>
iterator_type VECTOR::BASE_ITERATOR::operator+(int n) {
  return iterator_type(this->iterator_ptr_ + n);
}

template <typename value_type>
template <typename iterator_type, typename reference_type>
reference_type VECTOR::BASE_ITERATOR::operator*() const {
  return *this->iterator_ptr_;
}

template <typename value_type>
template <typename iterator_type, typename reference_type>
auto VECTOR::BASE_ITERATOR::operator-(const iterator_type &other) const {
  return this->iterator_ptr_ - other.iterator_ptr_;
}

// access functions
template <typename value_type>
typename VECTOR::reference VECTOR::at(size_type pos) {
  if (size_ < pos) {
    throw std::out_of_range(
        "Requested element: " + std::to_string(pos) +
        " is outside the allowed Vector size: " + std::to_string(size_));
  }

  return ptr_[pos];
}

template <typename value_type>
typename VECTOR::const_reference VECTOR::back() {
  return ptr_[size_ - 1];
}

template <typename value_type>
typename VECTOR::const_reference VECTOR::front() {
  return *ptr_;
}

template <typename value_type>
typename VECTOR::pointer VECTOR::data() {
  return ptr_;
}

// capacity information functions
template <typename value_type>
bool VECTOR::empty() const noexcept {
  return ptr_ == ptr_ + size_;
}

template <typename value_type>
typename VECTOR::size_type VECTOR::max_size() const noexcept {
  return std::numeric_limits<size_type>::max() / sizeof(value_type);
}

template <typename value_type>
typename VECTOR::size_type VECTOR::size() const noexcept {
  return size_;
}

template <typename value_type>
typename VECTOR::size_type VECTOR::capacity() const {
  return capacity_;
}

// modifiers functions
template <typename value_type>
typename VECTOR::iterator VECTOR::insert(Vector::iterator pos,
                                         const_reference value) {
  size_type size = calculate_deadzone(this->begin(), pos);
  allocate_volume(size_ + 1, calculate_capacity(size_ + 1), pos);
  *(ptr_ + size) = value;
  return this->begin() + size;
}

template <typename value_type>
void VECTOR::erase(Vector::iterator pos) {
  for (int i = std::abs(pos - this->begin()); 1 < size_ && i < size_ - 1; ++i) {
    ptr_[i] = ptr_[i + 1];
  }
  if (0 < size_) {
    --size_;
  }
}

template <typename value_type>
void VECTOR::reserve(size_type size) {
  if (capacity_ < size) {
    allocate_volume(size_, size);
  }
}

template <typename value_type>
void VECTOR::shrink_to_fit() {
  allocate_volume(size_, size_);
}

template <typename value_type>
void VECTOR::resize(size_type new_size) {
  allocate_volume(new_size, calculate_capacity(new_size));
}

template <typename value_type>
void VECTOR::push_back(const_reference value) {
  size_type new_size = size_ + 1;
  if (capacity_ < new_size) {
    resize(new_size);
  }
  ptr_[new_size - 1] = value;
  size_ = new_size;
}

template <typename value_type>
void VECTOR::push_back(value_type &&value) {
  size_type new_size = size_ + 1;
  if (capacity_ < new_size) {
    resize(new_size);
  }
  ptr_[new_size - 1] = std::move(value);
  size_ = new_size;
}

template <typename value_type>
void VECTOR::pop_back() {
  if (!empty()) {
    (ptr_ + size_ - 1)->~value_type();
    --size_;
  }
}

template <typename value_type>
void VECTOR::swap(Vector &other) {
  Vector<value_type> tmp_vector(std::move(other));
  other = std::move(*this);
  *this = std::move(tmp_vector);
}

template <typename value_type>
void VECTOR::clear() {
  delete_vector(*this);
}

// operators
template <typename value_type>
VECTOR &VECTOR::operator=(Vector &&v) noexcept {
  delete_vector(*this);
  this->ptr_ = v.ptr_;
  this->size_ = v.size_;
  this->capacity_ = v.size_;
  v.ptr_ = nullptr;
  v.size_ = 0;
  v.capacity_ = 0;
  return *this;
}

template <typename value_type>
VECTOR &VECTOR::operator=(const Vector &v) {
  delete_vector(*this);
  ptr_ = new value_type[v.capacity_];
  size_ = v.size_;
  capacity_ = v.capacity_;
  for (int i = 0; i < v.size_; ++i) {
    ptr_[i] = v.ptr_[i];
  }
  return *this;
}

template <typename value_type>
typename VECTOR::reference VECTOR::operator[](Vector::size_type pos) {
  return ptr_[pos];
}

// internal implementation functions
template <typename value_type>
void VECTOR::delete_vector(Vector &v) {
  delete[] v.ptr_;
  v.ptr_ = nullptr;
  v.size_ = 0;
  v.capacity_ = 0;
}

template <typename value_type>
typename VECTOR::size_type VECTOR::calculate_capacity(
    size_type new_size) noexcept {
  size_type new_capacity = capacity_;
  if (new_capacity - size_ <= 0) {
    new_capacity *= 2;
  }
  if (new_capacity < new_size) {
    new_capacity = new_size;
  }
  return new_capacity;
}

template <typename value_type>
typename VECTOR::size_type VECTOR::calculate_deadzone(Vector::iterator begin,
                                                      Vector::iterator end) {
  int size = 0;
  if (begin != nullptr && end != nullptr) {
    size = end - begin;
  } else if (begin != nullptr && end == nullptr) {
    size = 1;
  }
  return size < 0 ? size * -1 : size;
}

template <typename value_type>
void VECTOR::switch_pointer(pointer &new_alloc, pointer &old_alloc,
                            size_type new_size, Vector::iterator begin_deadzone,
                            Vector::iterator end_deadzone) {
  if (old_alloc == nullptr) {
    old_alloc = new_alloc;
    new_alloc = nullptr;
  } else {
    size_type size_deadzone = calculate_deadzone(begin_deadzone, end_deadzone);
    size_type size_space_before_deadzone =
        std::abs(begin_deadzone - this->begin());
    for (size_type selector_new_element = 0, selector_old_element = 0;
         selector_old_element < (size_ < new_size ? size_ : new_size);
         ++selector_old_element, ++selector_new_element) {
      if (selector_new_element == size_space_before_deadzone) {
        selector_new_element += size_deadzone;
      }
      new_alloc[selector_new_element] =
          std::move(old_alloc[selector_old_element]);
    }
    delete[] old_alloc;
    old_alloc = new_alloc;
    new_alloc = nullptr;
  }
}

template <typename value_type>
void VECTOR::allocate_volume(Vector::size_type new_size,
                             Vector::size_type new_capacity,
                             Vector::iterator begin_deadzone,
                             Vector::iterator end_deadzone) {
  size_type volume = new_size < new_capacity ? new_capacity : new_size;
  if (max_size() - capacity_ < volume) {
    throw std::length_error(
        "An invalid Vector space reservation value was specified: " +
        std::to_string(volume));
  }
  auto new_ptr = new value_type[volume];
  switch_pointer(new_ptr, ptr_, new_size, begin_deadzone, end_deadzone);
  size_ = new_size;
  if (size_ <= new_capacity) {
    capacity_ = new_capacity;
  }
}
