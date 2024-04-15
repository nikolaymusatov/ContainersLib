#ifndef SRC_QUEUE_NODE_H_
#define SRC_QUEUE_NODE_H_

namespace MyNamespace {

template <typename T>
struct Node {
  T value;
  struct Node<T>* next;
};

}  // namespace MyNamespace

#endif  // SRC_QUEUE_NODE_H_