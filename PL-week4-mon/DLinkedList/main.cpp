#include "DLinkedList.h"
#include <iostream>

int main() {

  DLinkedList<std::string> *names = new DLinkedList<std::string>;

  names->addFront("Carly");
  names->addFront("Sam");

  names->addBack("Spencer");
  names->addBack("Mrs. Benson");

  names->print();

  names->removeFront();
  names->removeBack();

  names->print();

  names->addBack("Nevel");
  names->addFront("Gibby");
  names->addFront("Freddie");

  names->print();

  listReverse(*names);

  names->print();

  return 0;
}