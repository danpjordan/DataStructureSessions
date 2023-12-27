#include "SLinkedList.h"
#include <iostream>
#include <iterator>
#include <ostream>
#include <string>

int main() {

  SLinkedList<int> *nums = new SLinkedList<int>;

  nums->addFront(1);
  nums->addFront(6);
  nums->addFront(8);
  nums->addFront(12);
  nums->print();
  std::cout << std::endl;

  std::cout << nums->getTotal() << std::endl;

  std::cout << nums->getString() << std::endl;


  return 0;
}