#include "CLinkedList.h"
#include <iostream>
#include <string>

int main() {
  CLinkedList<std::string> *names = new CLinkedList<std::string>;

  names->add("Tori");
  std::cout << std::endl;

  names->add("Jade");

  names->print();
  std::cout << std::endl;

  names->add("Cat");
  names->add("Beck");
  names->print();
  std::cout << std::endl;

  names->remove();
  names->print();
  std::cout << std::endl;

  names->add("Cat");
}