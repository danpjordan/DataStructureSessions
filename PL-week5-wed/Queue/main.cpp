#include "Exceptions/QueueEmptyException.h"
#include "LinkedQueue.h"
#include <iostream>
#include <string>

template <typename T> void print(LinkedQueue<T> *q) {
  LinkedQueue<T> *p = new LinkedQueue<T>;

  while (!q->empty()) {
    std::cout << q->front() << " ";
    p->enqueue(q->front());
    q->dequeue();
  }
  std::cout << std::endl;

  while (!p->empty()) {
    q->enqueue(p->front());
    p->dequeue();
  }
}

int main() {

  LinkedQueue<std::string> *names = new LinkedQueue<std::string>;

  names->enqueue("Jim");
  names->enqueue("Pam");
  names->enqueue("Michael");

  print(names);

  names->dequeue();
  names->dequeue();
  names->dequeue();

  try {
    names->dequeue();
  } catch (QueueEmptyException e) {
    std::cout << e.getMessage() << std::endl;
  }

  try {
    names->front();
  } catch (QueueEmptyException e) {
    std::cout << e.getMessage() << std::endl;
  }

  return 0;
}