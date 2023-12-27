#include <iostream>
#include <string>

class Vehicle {
public:
  Vehicle();                           // default constructor
  Vehicle(std::string owr, int y_old); // constructor
  virtual void print_info();

  // setter function for owner
  void setOwner(std::string owner) { this->owner = owner; }

protected:
  std::string owner;
  int years_old;
};

class Car : public Vehicle {
public:
  Car(); // default constructor
  Car(std::string owr, int y_old, std::string modl,
      double m_driven); // constructor

  virtual void print_info();

protected:
  std::string model;
  double mile_driven;
};
// default constructor definition
Vehicle::Vehicle() : owner(""), years_old(-1) {}
//  constructor definition
Vehicle::Vehicle(std::string owr, int y_old) : owner(owr), years_old(y_old) {}
// default constructor definition
Car::Car() : Vehicle("", -1), model(""), mile_driven(-1) {}

// constructor definition
Car::Car(std::string owr, int y_old, std::string modl, double m_driven)
    : Vehicle(owr, y_old), model(modl), mile_driven(m_driven) {}

// print function
void Vehicle::print_info() {
  std::cout << "Owner: " << owner << std::endl;
  std::cout << "Years old: " << years_old << std::endl;
}

// overloaded print function
void Car::print_info() {
  // we can call vehicle print statement in our car print statement
  Vehicle::print_info();
  std::cout << "Model: " << model << std::endl;
  std::cout << "Miles driven: " << mile_driven << std::endl;
}

int main() {
  Vehicle v1("Bob", 3);
  v1.print_info();
  std::cout << std::endl;

  Car c1("Bill", 3, "Audi", 12832);
  c1.print_info();
  std::cout << std::endl;

  // object pointers!
  Vehicle *v2 = new Vehicle;
  v2->print_info();
  std::cout << std::endl;

  v2->setOwner("Frank");
  v2->print_info();
  std::cout << std::endl;

  Car *c2 = new Car;
  c2->print_info();
  std::cout << std::endl;

  c2->setOwner("Kevin");
  c2->print_info();
  std::cout << std::endl;

  Car *c3 = new Car("Dan", 12, "Honda", 50392);
  c3->print_info();

  return 0;
}
