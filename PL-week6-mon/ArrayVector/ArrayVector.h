#ifndef ARRAY_VECTOR
#define ARRAY_VECTOR

#include "Exceptions/IndexOutOfBounds.h"
#include <cmath>
#include <iterator>
#include <iostream>

template <typename T> class ArrayVector {

public:
  ArrayVector() : capacity(0), n(0), A(nullptr) {}
  int size() const {return n;};
  bool empty() const {return n == 0;}
  T &operator[](int i) { return A[i];} // not safe
  T &at(int i) noexcept(false); // safe

  void erase(int i);
  void insert(int i, const T &e);
  void reserve(int N);
  void print();

private:
  int capacity;
  int n;
  T *A;
};

template <typename T> T& ArrayVector<T>::at(int i) noexcept(false) {
  if (i < 0 || i >= n) {
    throw(IndexOutOfBounds("index out of range in at()"));
  }
  return A[i];
}

template <typename T> void ArrayVector<T>::reserve(int N) {
  if (capacity >= N) { // already big enough
    return;
  }

  T *B = new T[N]; // create new array
  for (int j = 0; j < n; j++) {
    B[j] = A[j]; // copy values over
  }

  if (A != nullptr) {
    delete[] A; // delete old array
  }

  A = B;
  capacity = N;
}


template <typename T> void ArrayVector<T>::insert(int i, const T &e) {

  if (n >= capacity) {
    reserve(std::max(1, 2 * capacity)); // expanding array if its too small
  }

  for (int j = n - 1; j >= i; j--) {
    A[j + 1] = A[j];
  }

  A[i] = e;
  n++;
}

template <typename T> void ArrayVector<T>::erase(int i) {
  for (int j = i + 1; j < n; j++) {
    A[j - 1] = A[j];
  }
  n--;
}

template <typename T> void ArrayVector<T>::print() {
  for (int i = 0; i < n; i++) {
    std::cout << A[i] << " ";
  }
  std::cout << std::endl;
}

#endif