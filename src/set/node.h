#ifndef SRC_SET_NODE_H_
#define SRC_SET_NODE_H_

namespace MyNamespace {

template <typename Key>
struct Node_t {
  Key value;
  Node_t<Key> *parent;
  Node_t<Key> *left;
  Node_t<Key> *right;
};

}  // namespace MyNamespace

#endif  // SRC_SET_NODE_H_