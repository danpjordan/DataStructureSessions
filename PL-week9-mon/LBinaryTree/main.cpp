#include "LBinaryTree.h"
#include <iostream>
#include <list>
#include <string>

int main() {

  LinkedBinaryTree<std::string> *names = new LinkedBinaryTree<std::string>;

  names->addRoot();
  LinkedBinaryTree<std::string>::Position root;
  LinkedBinaryTree<std::string>::Position p;

  root = names->root();
  *root = "Tony";

  names->expandExternal(root);
  p = root.left();
  *p = "Happy";

  *root.right() = "Pepper";

  names->print();

  if (root.left().isExteral()) {
    std::cout << *root.left() << " is an external node " << std::endl;
  } else {
    std::cout << *root.left() << " is not an external node " << std::endl;
  }

  names->expandExternal(root.left());

  if (root.left().isExteral()) {
    std::cout << *root.left() << " is an external node " << std::endl;
  } else {
    std::cout << *root.left() << " is not an external node " << std::endl;
  }

  names->print();

  p = root.left();
  *p.left() = "Rhodey";
  *p.right() = "JARVIS";

  LinkedBinaryTree<std::string>::PositionList pl;

  pl = names->positions();
  
  for (auto kv : pl) {
    std::cout << *kv << "-";
  }
  std::cout << std::endl;

  delete names;

  names->addRoot();
  *names->root() = "Steve";
  names->print();
}
