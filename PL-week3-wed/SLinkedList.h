#ifndef SLINKED_LIST
#define SLINKED_LIST

#include "SNode.h"
#include <iostream>
#include <locale>
#include <string>

template <typename E> class SLinkedList {
public:
  SLinkedList();
  ~SLinkedList();
  bool empty() const;
  const E &front() const;
  void addFront(const E &e);
  void removeFront();
  void print();
  int getSize() { return nElem; }

  void appendAfter(SLinkedList<E> *L);

private:
  SNode<E> *head;
  int nElem = 0;
};

// default constructor
template <typename E> SLinkedList<E>::SLinkedList() : head(nullptr) {}

// returns whether the linked list is empty or not
template <typename E> bool SLinkedList<E>::empty() const {
  return head == nullptr;
}

// returns the value of the first node
template <typename E> const E &SLinkedList<E>::front() const {
  return head->elem;
}

// removes the first node
template <typename E> void SLinkedList<E>::removeFront() {
  SNode<E> *old = head;
  head = head->next;
  delete old;

  nElem--;
}

// deconstructor
template <typename E> SLinkedList<E>::~SLinkedList() {
  while (!empty()) {
    removeFront();
  }
}

template <typename E> void SLinkedList<E>::addFront(const E &e) {
  // create a new node with elem = e
  // set (new node)->next = head
  // make the new node the head node of the linked list

  SNode<E> *v = new SNode<E>;
  v->elem = e;
  v->next = head;
  head = v;

  nElem++;
}

template <typename E> void SLinkedList<E>::print() {
  // create a pointer which points to head
  // itterate that pointer through all the nodes and print each element

  SNode<E> *curr = head;

  while (curr != nullptr) {
    std::cout << curr->elem << " ";
    curr = curr->next;
  }
  std::cout << std::endl;
}

template <typename E> void SLinkedList<E>::appendAfter(SLinkedList<E> *L) {
  // walk through existing list
  // set (last node of existing list)->next = L->head

  SNode<E> *curr = head;
  while (curr->next != nullptr) {
    curr = curr->next;
  }

  curr->next = L->head;

  nElem += L->getSize();
}

#endif