using namespace MyNamespace;

// Queue Member functions
template <typename value_type>
Queue<value_type>::Queue() {
  head = tail = nullptr;
}

template <typename value_type>
Queue<value_type>::Queue(std::initializer_list<value_type> const& items) {
  head = tail = nullptr;
  for (size_type i = 0; i < items.size(); i++) {
    this->push(items.begin()[i]);
  }
}

template <typename value_type>
Queue<value_type>::Queue(const Queue& q) {
  head = tail = nullptr;
  this->copy(q);
}

template <typename value_type>
Queue<value_type>::Queue(Queue&& q) {
  tail = q.tail;
  head = q.head;
  q.tail = q.head = nullptr;
}

template <typename value_type>
Queue<value_type>::~Queue() {
  this->erase();
}

template <typename value_type>
Queue<value_type>& Queue<value_type>::operator=(const Queue& q) {
  if (head == q.head) return *this;
  this->erase();
  this->copy(q);
  return *this;
}

template <typename value_type>
Queue<value_type>& Queue<value_type>::operator=(Queue&& q) {
  if (head == q.head) return *this;
  this->erase();
  tail = q.tail;
  head = q.head;
  q.tail = q.head = nullptr;
  return *this;
}

// Queue Element access
template <typename value_type>
typename Queue<value_type>::const_reference Queue<value_type>::front() {
  return head->value;
}

template <typename value_type>
typename Queue<value_type>::const_reference Queue<value_type>::back() {
  return tail->value;
}

// Queue Capacity
template <typename value_type>
typename Queue<value_type>::size_type Queue<value_type>::size() {
  Node<value_type>* tmp = head;
  size_type counter = 0;
  while (tmp != nullptr) {
    counter++;
    tmp = tmp->next;
  }
  return counter;
}

template <typename value_type>
bool Queue<value_type>::empty() {
  return head == nullptr;
}

// // Queue Modifiers
template <typename value_type>
void Queue<value_type>::push(const_reference value) {
  Node<value_type>* tmp = new Node<value_type>;
  tmp->value = value;
  tmp->next = nullptr;
  if (!head)
    head = tail = tmp;
  else
    tail = tail->next = tmp;
}

template <typename value_type>
void Queue<value_type>::pop() {
  Node<value_type>* popped = head;
  if (popped) {
    head = head->next;
    delete popped;
    popped = nullptr;
  }
}

template <typename value_type>
void Queue<value_type>::swap(Queue& other) {
  Node<value_type>* tmp = other.head;
  other.head = head;
  head = tmp;
  tmp = other.tail;
  other.tail = tail;
  tail = tmp;
}

// // utils
template <typename value_type>
void Queue<value_type>::erase() {
  Node<value_type>* tmp;
  while (head != nullptr) {
    tmp = head;
    head = head->next;
    delete tmp;
  }
  tmp = nullptr;
}

template <typename value_type>
void Queue<value_type>::copy(const Queue& q) {
  tail = q.tail;
  Node<value_type>* tmp = q.head;
  while (tmp) {
    this->push(tmp->value);
    tmp = tmp->next;
  }
}