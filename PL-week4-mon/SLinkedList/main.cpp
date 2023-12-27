#include "SLinkedList.h"
#include <iostream>
#include <string>

int main() {

  SLinkedList<int> *nums = new SLinkedList<int>;
  nums->addFront(12);
  nums->addFront(10);

  std::cout << "List of nums: ";
  nums->print();

  SLinkedList<std::string> *names1 = new SLinkedList<std::string>;
  names1->addFront("Regina");
  names1->addFront("Grethchen");
  names1->addFront("Karen");

  std::cout << "List of names1: ";
  names1->print();

  std::cout << "Size of names1: ";
  std::cout << names1->getSize() << std::endl;

  SLinkedList<std::string> *names2 = new SLinkedList<std::string>;
  names2->addFront("Cady");
  names2->addFront("Janis");

  names1->appendAfter(names2);

  std::cout << "List of names1: ";
  names1->print();

  std::cout << "Size of names1: ";
  std::cout << names1->getSize() << std::endl;

  SLinkedList<char> *listOfChar = new SLinkedList<char>;
  listOfChar->addFront('c');
  listOfChar->addFront('b');
  listOfChar->addFront('a');
  listOfChar->addFront('c');

  std::cout << "palindome: ";
  listOfChar->print();

  if (listOfChar->isPalindrome()) {
    std::cout << "list is a palindrome" << std::endl;
  } else {
    std::cout << "list is not a palindrome" << std::endl;
  }

  return 0;
}