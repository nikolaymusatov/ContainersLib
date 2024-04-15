using namespace MyNamespace;

// Node
template <typename T>
List<T>::BaseNode::BaseNode(BaseNode *next, BaseNode *prev)
    : next_(next), prev_(prev) {}

template <typename T>
List<T>::Node::Node(T data) : BaseNode(), data_(data) {}

template <typename T>
List<T>::Node::Node(BaseNode *next, BaseNode *prev, T data)
    : BaseNode(next, prev), data_(data) {}

// ListIterator
template <typename T>
List<T>::iterator::ListIterator(BaseNode *ptr) : ptr_(ptr) {}

template <typename T>
typename List<T>::reference List<T>::ListIterator::operator*() {
  if (ptr_->next_ == nullptr) throw std::out_of_range("Out of range List");
  return static_cast<Node *>(ptr_)->data_;
}

template <typename T>
typename List<T>::iterator &List<T>::ListIterator::operator++() {
  ptr_ = ptr_->next_;
  return *this;
}

template <typename T>
typename List<T>::iterator List<T>::ListIterator::operator++(int) {
  iterator copy = *this;
  ptr_ = ptr_->next_;
  return copy;
}

template <typename T>
typename List<T>::iterator &List<T>::ListIterator::operator--() {
  ptr_ = ptr_->prev_;
  return *this;
}

template <typename T>
typename List<T>::iterator List<T>::ListIterator::operator--(int) {
  iterator copy = *this;
  ptr_ = ptr_->prev_;
  return copy;
}

template <class T>
bool List<T>::ListIterator::operator==(iterator other) const {
  return (ptr_ == other.ptr_);
}

template <class T>
bool List<T>::ListIterator::operator!=(iterator other) const {
  return (ptr_ != other.ptr_);
}

// ListConstIterator
template <typename T>
typename List<T>::const_reference List<T>::ListConstIterator::operator*()
    const {
  if (this->ptr_->next_ == nullptr)
    throw std::out_of_range("Out of range List");
  return static_cast<Node *>(this->ptr_)->data_;
}

// List
template <typename T>
List<T>::List() : head_(nullptr), tail_(nullptr), size_(0) {
  end_node_ = new BaseNode(nullptr, nullptr);
}

template <typename T>
List<T>::List(size_type n) : List() {
  for (size_t i = 0; i != n; ++i) push_back(0);
}

template <typename T>
List<T>::List(std::initializer_list<value_type> const &items) : List() {
  for (auto i = items.begin(); i != items.end(); ++i) push_back(*i);
}

template <typename T>
List<T>::~List() {
  clear();
  if (end_node_) delete end_node_;
}

template <typename T>
List<T>::List(const List &l) : List() {
  BaseNode *newnode = l.head_;
  while (newnode != l.end_node_) {
    push_back(static_cast<Node *>(newnode)->data_);
    newnode = newnode->next_;
  }
}

template <class T>
List<T>::List(List &&l) : List() {
  swap(l);
}

template <class T>
List<T> &List<T>::operator=(const List &l) {
  if (this != &l) {
    List<T> copy = l;
    swap(copy);
  }
  return *this;
}

template <class T>
List<T> &List<T>::operator=(List &&l) {
  swap(l);
  return *this;
}

template <typename T>
bool List<T>::empty() const {
  return (size_ == 0);
}

template <typename T>
typename List<T>::size_type List<T>::size() const {
  return size_;
}

template <typename T>
void List<T>::push_front(const_reference value) {
  Node *newnode = new Node(value);
  if (head_) {
    head_->prev_ = newnode;
    newnode->next_ = head_;
    head_ = newnode;
  } else {
    head_ = tail_ = newnode;
    head_->next_ = end_node_;
    head_->prev_ = end_node_;
    end_node_->prev_ = tail_;
  }
  end_node_->next_ = head_;
  ++size_;
}

template <typename T>
void List<T>::push_back(const_reference value) {
  Node *newnode = new Node(value);
  if (tail_) {
    tail_->next_ = newnode;
    newnode->prev_ = tail_;
    tail_ = newnode;
  } else {
    head_ = tail_ = newnode;
    newnode->prev_ = end_node_;
    end_node_->next_ = head_;
  }
  newnode->next_ = end_node_;
  end_node_->prev_ = tail_;
  ++size_;
}

template <typename T>
void List<T>::pop_front() {
  if (head_) {
    if (size_ == 1) {
      clear();
    } else {
      BaseNode *cur = head_;
      head_ = cur->next_;
      end_node_->next_ = cur->next_;
      cur->next_->prev_ = end_node_;
      delete cur;
      --size_;
    }
  }
}

template <typename T>
void List<T>::pop_back() {
  if (tail_) {
    if (size_ == 1) {
      clear();
    } else {
      BaseNode *cur = tail_;
      tail_ = cur->prev_;
      end_node_->prev_ = cur->prev_;
      cur->prev_->next_ = end_node_;
      delete cur;
      --size_;
    }
  }
}

template <typename T>
void List<T>::erase(iterator pos) {
  if (pos.ptr_ == head_) {
    pop_front();
  } else if (pos.ptr_ == tail_) {
    pop_back();
  } else {
    BaseNode *cur = pos.ptr_;
    pos.ptr_->prev_->next_ = pos.ptr_->next_;
    pos.ptr_->next_->prev_ = pos.ptr_->prev_;
    delete cur;
    --size_;
  }
}

template <typename T>
void List<T>::clear() {
  while ((head_ != end_node_) && (head_ != nullptr)) {
    BaseNode *current = head_;
    head_ = head_->next_;
    delete current;
  }
  head_ = tail_ = nullptr;
  size_ = 0;
}

template <typename T>
void List<T>::swap(List &other) {
  if (this != &other) {
    std::swap(head_, other.head_);
    std::swap(tail_, other.tail_);
    std::swap(size_, other.size_);
    std::swap(end_node_, other.end_node_);
  }
}

template <typename T>
void List<T>::merge(List &other) {
  if (other.size_ > 0) {
    for (auto it = other.begin(); it != other.end(); ++it) push_back(*it);
    sort();
    other.clear();
  }
}

template <typename T>
void List<T>::splice(const_iterator pos, List &other) {
  for (auto it = other.begin(); it != other.end(); ++it) insert(pos, *it);
  other.clear();
}

template <typename T>
void List<T>::reverse() {
  if (size_ > 1) {
    auto pos1 = begin();
    auto pos2 = iterator(tail_);
    while (pos1 != pos2) {
      std::swap(static_cast<Node *>(pos1.ptr_)->data_,
                static_cast<Node *>(pos2.ptr_)->data_);
      ++pos1;
      if (pos1 == pos2) break;
      --pos2;
    }
  }
}

template <typename T>
void List<T>::unique() {
  if (size_ > 1) {
    auto pos_prev = begin();
    auto pos = pos_prev;
    ++pos;
    while (pos != end()) {
      if (*pos == *pos_prev) {
        iterator cur = pos;
        ++pos;
        erase(cur);
        --size_;
      } else {
        ++pos_prev;
        ++pos;
      }
    }
  }
}

template <typename T>
void List<T>::sort() {
  if (size_ > 1) {
    for (auto pos1 = begin(); pos1 != end(); ++pos1) {
      auto pos2 = pos1;
      ++pos2;
      for (; pos2 != end(); ++pos2) {
        if (*pos2 < *pos1)
          std::swap(static_cast<Node *>(pos1.ptr_)->data_,
                    static_cast<Node *>(pos2.ptr_)->data_);
      }
    }
  }
}

template <class T>
typename List<T>::const_reference List<T>::front() const {
  return (head_) ? static_cast<Node *>(head_)->data_
                 : static_cast<Node *>(end_node_)->data_;
}

template <class T>
typename List<T>::const_reference List<T>::back() const {
  return (tail_) ? static_cast<Node *>(tail_)->data_
                 : static_cast<Node *>(end_node_)->data_;
}

template <typename T>
typename List<T>::const_iterator List<T>::begin() const {
  return (head_) ? const_iterator(head_) : const_iterator(end_node_);
}

template <typename T>
typename List<T>::const_iterator List<T>::end() const {
  return const_iterator(end_node_);
}

template <typename T>
typename List<T>::iterator List<T>::begin() {
  return (head_) ? iterator(head_) : iterator(end_node_);
}

template <typename T>
typename List<T>::iterator List<T>::end() {
  return iterator(end_node_);
}

template <typename T>
typename List<T>::iterator List<T>::insert(iterator pos,
                                           const_reference value) {
  iterator result;
  if (pos.ptr_) {
    if (pos == begin()) {
      push_front(value);
      result = iterator(this->head_);
    } else if (pos == end()) {
      push_back(value);
      result = iterator(this->tail_);
    } else {
      Node *ins = new Node(pos.ptr_, pos.ptr_->prev_, value);
      pos.ptr_->prev_->next_ = ins;
      pos.ptr_->prev_ = ins;
      result = iterator(ins);
      ++size_;
    }
  }
  return result;
}

template <typename T>
template <typename... Args>
typename List<T>::iterator List<T>::insert_many(const_iterator pos,
                                                Args &&...args) {
  iterator result;
  for (auto &&arg : {std::forward<Args>(args)...}) {
    result = insert(pos, arg);
  }
  return result;
}

template <typename T>
template <typename... Args>
void List<T>::insert_many_back(Args &&...args) {
  for (auto &&arg : {std::forward<Args>(args)...}) {
    push_back(arg);
  }
}

template <typename T>
template <typename... Args>
void List<T>::insert_many_front(Args &&...args) {
  for (auto &&arg : {std::forward<Args>(args)...}) {
    push_front(arg);
  }
}
