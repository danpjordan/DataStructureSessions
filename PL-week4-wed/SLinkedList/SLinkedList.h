#ifndef SLINKEDLIST
#define SLINKEDLIST

#include "SNode.h"
#include <cstddef>
#include <iostream>

template <typename E> class SLinkedList {
public:
  SLinkedList();
  ~SLinkedList();
  bool empty() const;
  const E &front() const;
  void addFront(const E &e);
  void removeFront();
  void print();
  int getTotal();
  int countTotal(SNode<E> *p);
  std::string toString(SNode<E> *p);
  std::string getString() { return toString(head); }

private:
  SNode<E> *head;
};
template <typename E> SLinkedList<E>::SLinkedList() : head(nullptr) {}

template <typename E> bool SLinkedList<E>::empty() const {
  return head == nullptr;
}

template <typename E> const E &SLinkedList<E>::front() const {
  return head->elem;
}

template <typename E> SLinkedList<E>::~SLinkedList() {
  while (!empty())
    removeFront();
}

template <typename E> void SLinkedList<E>::addFront(const E &e) {
  SNode<E> *v = new SNode<E>;
  v->elem = e;
  v->next = head;
  head = v;
}

template <typename E> void SLinkedList<E>::removeFront() {
  SNode<E> *old = head;
  head = old->next;
  delete old;
}

template <typename E> void SLinkedList<E>::print() {
  SNode<E> *curr = head;

  while (curr) {
    std::cout << curr->elem << " ";
    curr = curr->next;
  }
  std::cout << std::endl;
}

template <typename E> int SLinkedList<E>::countTotal(SNode<E> *p) {
  if (p == nullptr) {
    return 0;
  }

  return p->elem + countTotal(p->next);
}


template <typename E> int SLinkedList<E>::getTotal() {
  return countTotal(head);
}

template <typename E> std::string SLinkedList<E>::toString(SNode<E> *p) {
  if (p == nullptr) {
    return "";
  }

  return std::to_string(p->elem) + " " + toString(p->next);
}

// (1) -> (2) -> (4) -> (5) -> nullptr

// toString(n1) = 1 + " " + toString(n2)
// toString(n2) = 2 + " " + toString(n3)
// toString(n3) = 4 + " " + toString(n4) 
// toString(n4) = 5 + " " + toString(nullptr) 
// toString(nullptr) = ""


//toString(n1) = 1 2 4 5 

#endif