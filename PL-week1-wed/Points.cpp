#include <iostream>
#include <ostream>
#include <string>

class Point {
private:
  int x;
  int y;

public:
  Point(); // default contructor

  Point(int x, int y);

  Point(const Point &p); // copy constructor

  // getters
  int getX() { return x; }
  int getY() { return y; }

  // setters
  void setX(int x) { this->x = x; }
  void setY(int y) { this->y = y; }

  // print function
  void print();
};

// default constructor
Point::Point() {
  x = 0;
  y = 0;
}

Point::Point(int x, int y) {
  this->x = x;
  this->y = y;
}

// copy constructor
Point::Point(const Point &p) {
  this->x = p.x;
  this->y = p.y;
}

// opperator overloading for ==
bool operator==(Point p1, Point p2) {
  if (p1.getX() == p2.getX() && p1.getY() == p2.getY()) {
    return true;
  } else {
    return false;
  }
}

// opperator overloading for !=
bool operator!=(Point p1, Point p2) { return !(p1 == p2); }

// opperator overloading for -
Point operator-(Point p1, Point p2) {
  return Point(p1.getX() - p2.getX(), p1.getY() - p2.getY());
}

// opperator overloading for +
Point operator+(Point p1, Point p2) {
  return Point(p1.getX() + p2.getX(), p1.getY() + p2.getY());
}

// opperator overloading for <<
std::ostream &operator<<(std::ostream &os, Point p) {
  return os << p.getX() << ", " << p.getY();
}

void Point::print() { std::cout << x << ", " << y << std::endl; }

int main() {

  Point p1;
  p1.setX(2);
  p1.setY(3);

  p1.print();

  Point p2;
  p2.print();

  Point p3(3, 4);
  p3.print();

  Point p4(p3);
  p4.print();

  if (p1 != p4) {
    std::cout << "They not are equal" << std::endl;
  } else {
    std::cout << "They are equal" << std::endl;
  }

  Point p5(5, 2);
  std::cout << "Point 5: " << p5 << std::endl;

  Point p6(3, 7);

  // We didn't explicit cover this, but read through and see if you can
  // understand what is happening

  Point p7 = p5 + p6;
  std::cout << "Point 7: " << p7 << std::endl;

  Point p8 = p5 - p6;
  std::cout << "Point 8: " << p8 << std::endl;

  // object pointers
  Point p9(5, 3);
  Point *p10 = &p9; // sets p10 to the address of p9

  std::cout << "Point 9: " << p9 << std::endl;
  std::cout << "Point 10: " << *p10 << std::endl;
  *p10 = Point(4, 2); // changes p9 as well
  std::cout << "Point 9: " << p9 << std::endl;

  return 0;
}