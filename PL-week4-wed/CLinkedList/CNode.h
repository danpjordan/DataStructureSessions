#ifndef CNODE
#define CNODE

template <typename E> class CNode {
private:
  E elem;
  CNode<E> *next;

  public:
  CNode() {}

  template <typename U> friend class CLinkedList;
};

#endif