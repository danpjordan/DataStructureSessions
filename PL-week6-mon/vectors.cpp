#include <iostream>
#include <vector>
#include <string>

template <typename T> void print(std::vector<T> v) {
  for (auto kv : v) {
    std::cout << kv << " ";
  }
  std::cout << std::endl;
}


int main() {
  std::vector<int> v(5, 0);
  v.push_back(2);
  v.push_back(5);
  v.push_back(6);

  print(v);

  std::vector<int>::iterator iter = v.begin();

  std::cout << *iter << std::endl;

  v.at(0) = 4;
  v.at(1) = 8;


  while (iter != v.end()) {
    std::cout << *iter << " ";
    iter++;
  }
  std::cout << std::endl;

  v.insert(v.begin(), 10); // O(n)
  v.push_back(5); // O(1)

  sort(v.begin(), v.end()); // O(nlog(n))
  reverse(v.begin() + v.size() / 2, v.end()); // O(n)

  print(v);

  std::cout << std::endl << "W9 Q2:"<< std::endl;
  std::vector<int> seg;
  for (int i = 0; i < 10; i++) {
    seg.insert(seg.begin() + (i / 2), i);
    print(seg);
  }

  return 0;
}