#ifndef CLINKEDLIST
#define CLINKEDLIST

#include "CNode.h"
#include <iostream>

template <typename E> class CLinkedList {
public:
  CLinkedList() : cursor(nullptr){};
  ~CLinkedList();

  bool empty() const { return cursor == nullptr; }

  const E front() const { return cursor->next->elem; }
  const E back() const { return cursor->elem; }
  void advance() { cursor = cursor->next; }

  void add(const E elm);
  void remove();
  void print();

private:
  CNode<E> *cursor;
};

template <typename E> CLinkedList<E>::~CLinkedList() {
  while (!empty()) {
    remove();
  }
}

template <typename E> void CLinkedList<E>::remove() {
  CNode<E> *old = cursor->next;
  if (old == cursor) {
    cursor = nullptr;
  } else {
    cursor->next = old->next;
    delete old;
  }
}

template <typename E> void CLinkedList<E>::add(const E elm) {
  CNode<E> *v = new CNode<E>;
  v->elem = elm;
  if (cursor == nullptr) {
    v->next = v;
    cursor = v;
  } else {
    v->next = cursor->next;
    cursor->next = v;
  }
}

template <typename E> void CLinkedList<E>::print() {

  if (!empty()) {
    CNode<E> *fast = cursor->next->next;
    CNode<E> *slow = cursor->next;

    while (fast != slow) {
      std::cout << slow->elem << " ";
      fast = fast->next->next;
      slow = slow->next;
    }
    std::cout << slow->elem << " ";
  }

  std::cout << std::endl;

}

#endif