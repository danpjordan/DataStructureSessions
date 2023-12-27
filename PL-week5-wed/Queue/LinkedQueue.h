#ifndef LINKED_QUEUE
#define LINKED_QUEUE

#include "CLinkedList/CLinkedList.h"
#include "Exceptions/QueueEmptyException.h"

template <typename T> class LinkedQueue {
public:
  LinkedQueue() : C(), numElem(0) {}
  int size() const { return numElem; }
  bool empty() const { return numElem == 0; }
  const T &front() const noexcept(false);
  void enqueue(const T &e);
  void dequeue() noexcept(false);
  void print();

private:
  CLinkedList<T> C;
  int numElem;
};

template <typename T> const T &LinkedQueue<T>::front() const noexcept(false) {
  if (empty()) {
    throw QueueEmptyException("Front of empty queue");
  }
  return C.front();
}

template <typename T> void LinkedQueue<T>::enqueue(const T &e) {
  C.add(e);
  C.advance();
  numElem++;
}

template <typename T> void LinkedQueue<T>::dequeue() noexcept(false) {
  if (empty()) {
    throw QueueEmptyException("Dequeue of empty queue");
  }
  numElem--;
  return C.remove();
}

template <typename T> void LinkedQueue<T>::print() {
  LinkedQueue<T> p;

  while (!empty()) {
    std::cout << front() << " ";
    p.enqueue(front());
    dequeue();
  }
  std::cout << std::endl;

  while (!p.empty()) {
    enqueue(p.front());
    p.dequeue();
  }
}

#endif