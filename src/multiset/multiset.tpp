using namespace MyNamespace;

template <typename value_type>
multiset<value_type>::multiset() : root(nullptr), nodes_qnt(0){};

template <typename value_type>
multiset<value_type>::multiset(std::initializer_list<value_type> const& items)
    : multiset<value_type>() {
  for (size_type i = 0; i < items.size(); i++) this->insert(items.begin()[i]);
}

template <typename value_type>
multiset<value_type>::multiset(const multiset<value_type>& ms)
    : multiset<value_type>() {
  if (this != &ms) {
    clear();
    this->root = copy_multiset(ms.root, nullptr);
    this->nodes_qnt = ms.nodes_qnt;
  }
}

template <typename value_type>
multiset<value_type>::multiset(multiset<value_type>&& ms)
    : multiset<value_type>() {
  swap(ms);
}

template <typename value_type>
multiset<value_type>& multiset<value_type>::operator=(
    const multiset<value_type>& ms) {
  if (this != &ms) {
    multiset<value_type> copy(ms);
    swap(copy);
  }
  return *this;
}

template <typename value_type>
multiset<value_type>& multiset<value_type>::operator=(
    multiset<value_type>&& ms) {
  swap(ms);
  return *this;
}

template <typename value_type>
multiset<value_type>::~multiset() {
  delete_multiset(root);
};

template <typename value_type>
bool multiset<value_type>::empty() {
  return !root;
};

template <typename value_type>
typename multiset<value_type>::size_type multiset<value_type>::size() {
  return this->nodes_qnt;
}

template <typename value_type>
typename multiset<value_type>::size_type multiset<value_type>::max_size() {
  return std::numeric_limits<size_type>::max() / sizeof(value_type);
};

template <typename value_type>
bool multiset<value_type>::contains(const_reference key) {
  Node_t<value_type>* node = root;
  while (node && node->value != key) {
    if (node->value > key)
      node = node->left;
    else
      node = node->right;
  }
  return node != nullptr;
}

template <typename value_type>
typename multiset<value_type>::iterator multiset<value_type>::insert(
    const value_type& value) {
  insert_node(root, value);
  ++nodes_qnt;
  return find(value);
}

template <typename value_type>
Node_t<value_type>* multiset<value_type>::insert_node(Node_t<value_type>* node,
                                                      const value_type& value) {
  if (node == nullptr) {
    Node_t<value_type>* tmp = new Node_t<value_type>;
    tmp->value = value;
    tmp->left = tmp->right = tmp->parent = nullptr;
    if (!root) {
      root = tmp;
    }
    return tmp;
  }
  if (value <= node->value) {
    Node_t<value_type>* lchild = insert_node(node->left, value);
    node->left = lchild;
    lchild->parent = node;
  } else if (value > node->value) {
    Node_t<value_type>* rchild = insert_node(node->right, value);
    node->right = rchild;
    rchild->parent = node;
  }
  return node;
}

template <typename value_type>
void multiset<value_type>::erase(iterator pos) {
  if (pos.get_node()) {
    Node_t<value_type>* node = pos.get_node();
    if (node->left && node->right) {
      Node_t<value_type>* replaced_node = node->right;
      while (replaced_node->left) replaced_node = replaced_node->left;
      value_type replaced_value = replaced_node->value;
      erase(find(replaced_value));
      node->value = replaced_value;
    } else if (!node->left && node != this->root) {
      if (node->parent->left == node) node->parent->left = node->right;
      if (node->parent->right == node) node->parent->right = node->right;
      if (node->right) node->right->parent = node->parent;
      nodes_qnt--;
      delete node;
    } else if (!node->right && node != this->root) {
      if (node->parent->left == node) node->parent->left = node->left;
      if (node->parent->right == node) node->parent->right = node->left;
      if (node->left) node->left->parent = node->parent;
      nodes_qnt--;
      delete node;
    } else {
      if (!node->left && !node->right) {
        delete node;
        nodes_qnt--;
        this->root = nullptr;
      } else if (!node->left) {
        this->root = node->right;
        delete node;
        nodes_qnt--;
      } else {
        this->root = node->left;
        node->left->parent = nullptr;
        delete node;
        nodes_qnt--;
      }
    }
  }
}

template <typename value_type>
void multiset<value_type>::swap(multiset& other) {
  if (this != &other) {
    std::swap(this->root, other.root);
    std::swap(this->nodes_qnt, other.nodes_qnt);
  }
}

template <typename value_type>
void multiset<value_type>::merge(multiset& other) {
  Node_t<value_type>* nodes_to_delete[other.size()];
  int i = 0;
  for (auto iter = other.begin(); iter != other.end(); iter++) {
    this->insert(*iter);
    nodes_to_delete[i] = iter.get_node();
    i++;
  }
  for (int j = 0; j < i; j++)
    other.erase(other.find(nodes_to_delete[j]->value));
}

template <typename value_type>
typename multiset<value_type>::size_type multiset<value_type>::count(
    const_reference key) {
  size_type count_elements = 0;
  for (auto item : *this) {
    if (item == key) ++count_elements;
  }
  return count_elements;
}

template <typename value_type>
typename multiset<value_type>::iterator multiset<value_type>::lower_bound(
    const_reference key) {
  iterator iterator_not_less = begin();
  while (iterator_not_less != end() && *iterator_not_less < key)
    ++iterator_not_less;
  if (!(iterator_not_less.get_node()))
    throw std::out_of_range("Iterator not found");
  return iterator_not_less;
}

template <typename value_type>
typename multiset<value_type>::iterator multiset<value_type>::upper_bound(
    const_reference key) {
  iterator iterator_upper = begin();
  while (iterator_upper != end() && *iterator_upper <= key) ++iterator_upper;
  if (!(iterator_upper.get_node()))
    throw std::out_of_range("Iterator not found");
  return iterator_upper;
}

template <typename value_type>
std::pair<typename multiset<value_type>::iterator,
          typename multiset<value_type>::iterator>
multiset<value_type>::equal_range(const_reference key) {
  return std::pair(lower_bound(key), upper_bound(key));
}

template <typename value_type>
template <typename... Args>
std::vector<std::pair<typename multiset<value_type>::iterator, bool>>
multiset<value_type>::insert_many(Args&&... args) {
  std::vector<std::pair<iterator, bool>> result;
  for (auto&& arg : {std::forward<Args>(args)...}) {
    result.push_back(std::make_pair(insert(arg), true));
  }
  return result;
}

template <typename value_type>
typename multiset<value_type>::iterator multiset<value_type>::find(
    const_reference key) {
  iterator iter = this->begin();
  while (iter != this->end() && *iter != key) iter++;
  return iter;
}

template <typename value_type>
typename multiset<value_type>::iterator multiset<value_type>::begin() {
  Node_t<value_type>* tmp = root;
  while (tmp && tmp->left) tmp = tmp->left;
  return iterator(tmp);
}

template <typename value_type>
typename multiset<value_type>::iterator multiset<value_type>::end() {
  return iterator(nullptr);
}

template <typename value_type>
void multiset<value_type>::clear() {
  if (!this->empty()) {
    this->delete_multiset(this->root);
    this->root = nullptr;
    this->nodes_qnt = 0;
  }
}

template <typename value_type>
Node_t<value_type>* multiset<value_type>::copy_multiset(
    Node_t<value_type>* node, Node_t<value_type>* parent) {
  if (node) {
    Node_t<value_type>* new_node = new Node_t<value_type>;
    new_node->value = node->value;
    new_node->parent = parent;
    new_node->left = copy_multiset(node->left, new_node);
    new_node->right = copy_multiset(node->right, new_node);
    return new_node;
  } else {
    return nullptr;
  }
}

template <typename value_type>
void multiset<value_type>::delete_multiset(Node_t<value_type>* node) {
  if (node) {
    delete_multiset(node->left);
    delete_multiset(node->right);
    delete node;
  }
}
