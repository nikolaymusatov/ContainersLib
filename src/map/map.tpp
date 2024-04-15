using namespace MyNamespace;

template <class Key, class T>
Map<Key, T>::Map() : set<std::pair<Key, T>>() {}

template <typename Key, typename T>
Map<Key, T>::Map(std::initializer_list<value_type> const &items)
    : set<std::pair<Key, T>>(items) {}

template <typename Key, typename T>
Map<Key, T>::Map(const Map &m) : Map() {
  this->root = set<value_type>::copy_set(m.root, nullptr);
  this->nodes_qnt = m.nodes_qnt;
}

template <typename Key, typename T>
Map<Key, T>::Map(Map &&m) : Map() {
  swap(m);
}

template <typename Key, typename T>
Map<Key, T> &Map<Key, T>::operator=(const Map &m) {
  if (this != &m) {
    Map<Key, T> copy = m;
    swap(copy);
  }
  return *this;
}

template <typename Key, typename T>
Map<Key, T> &Map<Key, T>::operator=(Map &&m) {
  swap(m);
  return *this;
}

template <typename Key, typename T>
Map<Key, T>::~Map() {
  set<value_type>::clear();
}

template <typename Key, typename T>
T &Map<Key, T>::at(const Key &key) {
  if (!(contains(key)))
    throw std::out_of_range("No such key in the Map!");
  else {
    iterator iterator_has_already = find(key);
    return iterator_has_already->second;
  }
}

template <typename Key, typename T>
T &Map<Key, T>::operator[](const Key &key) {
  if (!(contains(key))) insert(key, mapped_type());
  iterator it_result = find(key);
  return it_result->second;
}

template <typename Key, typename T>
std::pair<typename Map<Key, T>::iterator, bool> Map<Key, T>::insert(
    const value_type &value) {
  iterator iterator_has_already = find(value.first);
  if (contains(value.first))
    return std::pair<iterator, bool>(iterator_has_already, false);
  return set<value_type>::insert(value);
}

template <typename Key, typename T>
std::pair<typename Map<Key, T>::iterator, bool> Map<Key, T>::insert(
    const Key &key, const T &obj) {
  return set<value_type>::insert(std::make_pair(key, obj));
}

template <typename Key, typename T>
std::pair<typename Map<Key, T>::iterator, bool> Map<Key, T>::insert_or_assign(
    const Key &key, const T &obj) {
  iterator iterator_has_already = find(key);
  if (contains(key)) {
    iterator_has_already->second = obj;
    return std::pair<iterator, bool>(iterator_has_already, false);
  }
  return set<value_type>::insert(std::make_pair(key, obj));
}

template <typename Key, typename T>
void Map<Key, T>::swap(Map &other) {
  if (this != &other) {
    std::swap(this->root, other.root);
    std::swap(this->nodes_qnt, other.nodes_qnt);
  }
}

template <typename Key, typename T>
void Map<Key, T>::merge(Map &other) {
  if (this != &other) {
    for (auto iter = other.begin(); iter != other.end(); ++iter) {
      if (!contains(iter->first)) {
        this->insert(*iter);
      }
    }
    other.clear();
  }
}

template <typename Key, typename T>
template <typename... Args>
std::vector<std::pair<typename Map<Key, T>::iterator, bool>>
Map<Key, T>::insert_many(Args &&...args) {
  std::vector<std::pair<iterator, bool>> result;
  for (auto &&arg : {std::forward<Args>(args)...}) {
    result.push_back(insert(arg));
  }
  return result;
}

template <typename Key, typename T>
typename Map<Key, T>::iterator Map<Key, T>::find(const Key &key) {
  iterator i = set<value_type>::begin();
  while (i != set<value_type>::end()) {
    if (i->first == key) return i;
    ++i;
  }
  return i;
}

template <typename Key, typename T>
bool Map<Key, T>::contains(const Key &key) {
  bool flag = false;
  if (find(key) != set<value_type>::end()) flag = true;
  return flag;
}
