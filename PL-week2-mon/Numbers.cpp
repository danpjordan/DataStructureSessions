#include <iostream>
#include <string>

class Numbers {
public:
  Numbers() {}
  Numbers(int v1, int v2, int v3) : var1(v1), var2(v2), var3(v3) {}

  void printAllNums();

  int var1;

protected:
  int getVar3() { return var3; }
  void setVar3(int var) { var3 = var; }
  int var2;

private:
  int var3;
};

class B : public Numbers {
public:
  B(int v1, int v2, int v3) {
    // in the class 'B' which extendes numbers, we can access the public
    // variable var1 and the protected variable var2
    var1 = v1;
    var2 = v2;

    // we cannot however access var3 because var3 is private
    setVar3(v3); // we can still call the setVar3 function because it is public
  }

  void printLastTwoNums();
};

void Numbers::printAllNums() {
  std::cout << "Num1: " << var1 << " Num2: " << var2 << " Num3: " << var3
            << std::endl;
}

void B::printLastTwoNums() {
  // because 'B' extends numbers we can access the protected variable var2
  std::cout << "Num2: " << var2 << " Num3: " << getVar3() << std::endl;
}

int main() {

  Numbers nums(1, 2, 3);
  B nums2(5, 6, 7);

  // we can access the public variable var1 outside both classes;
  std::cout << "var1: " << nums.var1 << std::endl;
  // however we can't access the protected or private varibles var2 or var3

  nums.printAllNums();

  nums2.printAllNums();
  nums2.printLastTwoNums();

  return 0;
}