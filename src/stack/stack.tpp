using namespace MyNamespace;

// Stack Member functions
template <typename value_type>
stack<value_type>::stack() {
  top_node = nullptr;
}

template <typename value_type>
stack<value_type>::stack(std::initializer_list<value_type> const& items) {
  top_node = nullptr;
  for (size_type i = 0; i < items.size(); i++) {
    this->push(items.begin()[i]);
  }
}

template <typename value_type>
stack<value_type>::stack(const stack& s) {
  top_node = nullptr;
  this->copy(s);
}

template <typename value_type>
stack<value_type>::stack(stack&& s) {
  top_node = s.top_node;
  s.top_node = nullptr;
}

template <typename value_type>
stack<value_type>& stack<value_type>::operator=(const stack& s) {
  if (top_node == s.top_node) return *this;
  this->erase();
  this->copy(s);
  return *this;
}

template <typename value_type>
stack<value_type>& stack<value_type>::operator=(stack&& s) {
  if (top_node == s.top_node) return *this;
  this->erase();
  top_node = s.top_node;
  s.top_node = nullptr;
  return *this;
}

template <typename value_type>
stack<value_type>::~stack() {
  this->erase();
}

// Stack Element access
template <typename value_type>
typename stack<value_type>::const_reference stack<value_type>::top() {
  return top_node->value;
}

// Stack Capacity
template <typename value_type>
bool stack<value_type>::empty() {
  return top_node == nullptr;
}

template <typename value_type>
typename stack<value_type>::size_type stack<value_type>::size() {
  Node<value_type>* tmp = top_node;
  size_type counter = 0;
  while (tmp != nullptr) {
    counter++;
    tmp = tmp->next;
  }
  return counter;
}

// Stack Modifiers
template <typename value_type>
void stack<value_type>::push(const_reference value) {
  Node<value_type>* tmp = new Node<value_type>;
  if (tmp) {
    tmp->value = value;
    tmp->next = top_node;
    top_node = tmp;
  }
}

template <typename value_type>
void stack<value_type>::pop() {
  Node<value_type>* popped = top_node;
  if (popped) {
    top_node = top_node->next;
    delete popped;
    popped = nullptr;
  }
}

template <typename value_type>
void stack<value_type>::swap(stack& other) {
  Node<value_type>* tmp = other.top_node;
  other.top_node = top_node;
  top_node = tmp;
}

// utils
template <typename value_type>
void stack<value_type>::erase() {
  Node<value_type>* tmp;
  while (top_node != nullptr) {
    tmp = top_node;
    top_node = top_node->next;
    delete tmp;
  }
  tmp = nullptr;
}

template <typename value_type>
void stack<value_type>::copy(const stack& s) {
  Node<value_type>* tmp = s.top_node;
  while (tmp) {
    this->push(tmp->value);
    tmp = tmp->next;
  }
}