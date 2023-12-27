#include <iostream>
#include <string>

template <typename T> class BasicVector {
public:
  BasicVector(int capac = 10);
  T &operator[](int i) { return a[i]; }

  T getVal(int pos) { return a[pos]; }

private:
  T *a;
  int capacity;
};

template <typename T>
// constructor
BasicVector<T>::BasicVector(int capac) {
  capacity = capac;
  a = new T[capacity]; // allocate array storage
}

int main() {
  BasicVector<int> iv(5); // vector of 5 integers

  iv[1] = 12;

  std::cout << "iv[1] = " << iv.getVal(1) << std::endl;

  BasicVector<double> dv(20); // vector of 20 doubles
  dv[13] = 4.2;
  std::cout << "dv[13] = " << dv[13] << std::endl;

  BasicVector<std::string> sv(10); // vector of 10 strings
  sv[8] = "hello there";
  std::cout << "sv[8] = " << sv[8] << std::endl;

  return 0;
}