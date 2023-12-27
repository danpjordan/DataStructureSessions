#ifndef DNODE
#define DNODE

template <typename E> class DNode {
public:
  DNode() {}

private:
  E elem;
  DNode<E> *next;
  DNode<E> *prev; // *

  template <typename T> friend class DLinkedList;
};

#endif