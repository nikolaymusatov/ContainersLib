using namespace MyNamespace;

template <typename value_type>
set<value_type>::set() : root(nullptr), nodes_qnt(0){};

template <typename value_type>
set<value_type>::set(std::initializer_list<value_type> const &items)
    : set<value_type>() {
  for (size_type i = 0; i < items.size(); i++) {
    this->insert(items.begin()[i]);
  }
}

template <typename value_type>
set<value_type>::set(const set<value_type> &s) : set<value_type>() {
  root = copy_set(s.root, nullptr);
  nodes_qnt = s.nodes_qnt;
}

template <typename value_type>
set<value_type>::set(set<value_type> &&s) : set<value_type>() {
  root = s.root;
  nodes_qnt = s.nodes_qnt;
  s.root = nullptr;
  s.nodes_qnt = 0;
}

template <typename value_type>
set<value_type> &set<value_type>::operator=(const set<value_type> &s) {
  if (root == s.root) return *this;
  this->delete_set(root);
  root = copy_set(s.root, nullptr);
  nodes_qnt = s.nodes_qnt;
  return *this;
}

template <typename value_type>
set<value_type> &set<value_type>::operator=(set<value_type> &&s) {
  if (root == s.root) return *this;
  this->delete_set(root);
  root = s.root;
  nodes_qnt = s.nodes_qnt;
  s.root = nullptr;
  s.nodes_qnt = 0;
  return *this;
}

template <typename value_type>
set<value_type>::~set() {
  delete_set(root);
};

template <typename value_type>
bool set<value_type>::empty() {
  return !root;
};

template <typename value_type>
typename set<value_type>::size_type set<value_type>::size() {
  return this->nodes_qnt;
}

template <typename value_type>
typename set<value_type>::size_type set<value_type>::max_size() {
  return std::numeric_limits<size_type>::max() / sizeof(value_type);
};

template <typename value_type>
bool set<value_type>::contains(const_reference key) {
  Node_t<value_type> *node = root;
  while (node && node->value != key) {
    if (node->value > key)
      node = node->left;
    else
      node = node->right;
  }
  return node != nullptr;
}

template <typename value_type>
std::pair<typename set<value_type>::iterator, bool> set<value_type>::insert(
    const_reference value) {
  bool status = !contains(value);
  if (status) {
    try {
      insert_(value);
    } catch (const std::exception &e) {
      std::cerr << "Error during insert operation" << '\n';
      status = false;
    }
  }
  return std::make_pair(find(value), status);
}

template <typename value_type>
void set<value_type>::insert_(const_reference key) {
  Node_t<value_type> *node = new Node_t<value_type>;
  node->value = key;
  node->left = node->right = node->parent = nullptr;
  if (!root) {
    root = node;
    ++nodes_qnt;
  } else {
    Node_t<value_type> *tmp = root;
    while (tmp) {
      if (tmp->value > key && !tmp->left) {
        tmp->left = node;
        node->parent = tmp;
        ++nodes_qnt;
      } else if (tmp->value < key && !tmp->right) {
        tmp->right = node;
        node->parent = tmp;
        ++nodes_qnt;
      } else if (tmp->value > key)
        tmp = tmp->left;
      else
        tmp = tmp->right;
    }
  }
}

template <typename value_type>
template <typename... Args>
std::vector<std::pair<typename set<value_type>::iterator, bool>>
set<value_type>::insert_many(Args &&...args) {
  std::vector<std::pair<iterator, bool>> result;
  for (auto &&arg : {std::forward<Args>(args)...}) {
    result.push_back(insert(arg));
  }
  return result;
}

template <typename value_type>
void set<value_type>::erase(iterator pos) {
  if (pos.get_node()) {
    Node_t<value_type> *node = pos.get_node();
    if (node->left && node->right) {
      Node_t<value_type> *replaced_node = node->right;
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
void set<value_type>::swap(set &other) {
  Node_t<value_type> *tmp = other.root;
  size_type size = other.nodes_qnt;
  other.root = root;
  root = tmp;
  other.nodes_qnt = nodes_qnt;
  nodes_qnt = size;
}

template <typename value_type>
void set<value_type>::merge(set &other) {
  Node_t<value_type> *nodes_to_delete[other.size()];
  int i = 0;
  for (auto iter = other.begin(); iter != other.end(); iter++) {
    if (!this->contains(*iter)) {
      this->insert(*iter);
      nodes_to_delete[i] = iter.get_node();
      i++;
    }
  }
  for (int j = 0; j < i; j++)
    other.erase(other.find(nodes_to_delete[j]->value));
}

template <typename value_type>
typename set<value_type>::iterator set<value_type>::find(const_reference key) {
  iterator iter = this->begin();
  while (iter != this->end() && *iter != key) iter++;
  return iter;
}

template <typename value_type>
typename set<value_type>::iterator set<value_type>::begin() {
  Node_t<value_type> *tmp = root;
  while (tmp && tmp->left) tmp = tmp->left;
  return iterator(tmp);
}

template <typename value_type>
typename set<value_type>::iterator set<value_type>::end() {
  return iterator(nullptr);
}

template <typename value_type>
typename set<value_type>::const_iterator set<value_type>::cbegin() const {
  Node_t<value_type> *tmp = root;
  while (tmp && tmp->left) tmp = tmp->left;
  return const_iterator(tmp);
}

template <typename value_type>
typename set<value_type>::const_iterator set<value_type>::cend() const {
  return const_iterator(nullptr);
}

template <typename value_type>
void set<value_type>::clear() {
  if (!this->empty()) {
    this->delete_set(this->root);
    this->root = nullptr;
    this->nodes_qnt = 0;
  }
}

template <typename value_type>
Node_t<value_type> *set<value_type>::copy_set(Node_t<value_type> *node,
                                              Node_t<value_type> *parent) {
  if (node) {
    Node_t<value_type> *new_node = new Node_t<value_type>;
    new_node->value = node->value;
    new_node->parent = parent;
    new_node->left = copy_set(node->left, new_node);
    new_node->right = copy_set(node->right, new_node);
    return new_node;
  } else {
    return nullptr;
  }
}

template <typename value_type>
void set<value_type>::delete_set(Node_t<value_type> *node) {
  if (node) {
    delete_set(node->left);
    delete_set(node->right);
    delete node;
  }
}
