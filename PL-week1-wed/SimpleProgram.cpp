#include <iostream>
#include <string>

int main() {

  std::string name;

  // input/output
  std::cout << "Please type you name: ";
  // std::cin >> name;
  std::getline(std::cin, name);
  std::cout << "Your name is: " << name << std::endl;
  std::cout << "Thank you" << std::endl;

  // pointers
  char ch = 'Q';
  char *p;
  p = &ch;
  std::cout << ch << " " << *p << std::endl;

  // arrays
  int nums[10];
  int num1 = nums[0];
  int num2 = nums[9];
  int nums2[] = {1, 2, 3};

  // array pointers
  char c[] = {'a', 'b', 'c'};
  char *d = c; // d point to c[0]
  char *e = &c[0];

  std::cout << e[2] << std::endl;

  return 0;
}