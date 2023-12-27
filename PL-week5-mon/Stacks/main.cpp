#include "Exceptions/StackEmptyException.h"
#include "LinkedStack.h"
#include <iostream>
#include <string>

int main() {
  LinkedStack<std::string> *names = new LinkedStack<std::string>;

  names->push("Rachel");
  names->push("Monica");
  names->push("Ross");

  names->print();

  names->pop();
  names->pop();
  names->pop();

  try {
    names->pop();
  } catch (StackEmptyException e) {
    std::cout << "Error: " << e.getMessage() << std::endl;
  }

  names->push("Chandler");
  names->push("Pheobe");
  names->push("Joey");

  names->print();

  names->clearStack();

  names->print();

  return 0;
}