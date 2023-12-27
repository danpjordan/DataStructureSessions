#ifndef LINKED_STACK
#define LINKED_STACK

#include "Exceptions/StackEmptyException.h"
#include "SLinkedList/SLinkedList.h"
#include <exception>
#include <iostream>
#include <string>

template <typename T> class LinkedStack {
public:
  LinkedStack() : S(), numElem(0){};
  int size() const { return numElem; };
  bool empty() const { return numElem == 0; };
  const T &top() const noexcept(false); // return top element from stack
  void push(const T &e);                // add new element to stack
  void pop() noexcept(false);           // remove top element from stack
  void print();
  void clearStack();

private:
  SLinkedList<T> S;
  int numElem;
};

template <typename T> const T &LinkedStack<T>::top() const noexcept(false) {
  if (empty()) {
    throw StackEmptyException("Top of empty stack");
  }

  return S.front();
}

template <typename T> void LinkedStack<T>::push(const T &e) {
  S.addFront(e);
  numElem++;
}

template <typename T> void LinkedStack<T>::pop() noexcept(false) {
  if (empty()) {
    throw StackEmptyException("Pop from empty stack");
  }
  S.removeFront();
  numElem--;
}

template <typename T> void LinkedStack<T>::print() {
  // add them into stack 2
  // remove elements from stack 1
  // print as we add them into stack 2
  // add items from stack 2 into stack 1

  LinkedStack<T> p;
  while (!empty()) {
    p.push(top());
    std::cout << top() << " ";
    pop();
  }

  while (!p.empty()) {
    push(p.top());
    p.pop();
  }

  std::cout << std::endl << std::endl;
  ;
}

template <typename T> void LinkedStack<T>::clearStack() {

  if (empty()) {
    return;
  } else {
    pop();
    clearStack();
  }
}

#endif