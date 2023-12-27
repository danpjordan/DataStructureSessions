#include <fstream>
#include <iostream>
#include <sstream>
#include <string>

int main() {
  std::fstream inFS;

  // opening an input file
  inFS.open("someText.txt", std::ios_base::in);
  if (!inFS.is_open()) {
    std::cout << "Failed to open";
  }
  std::string line;

  // getting input from file
  while (getline(inFS, line)) {
    std::cout << line << std::endl;
  }

  // opening an output file
  std::fstream outFS;
  outFS.open("nestedfolder/outputText.txt", std::ios_base::out);

  if (!outFS.is_open()) {
    std::cout << "Failed to open";
  }

  // outputing to file
  std::cout << "What do you want to write: " << std::endl;
  while (getline(std::cin, line) && line != "q") {
    outFS << line << std::endl;
  }


  std::string str = "this,is,a,string,of words!";
  std::stringstream SS(str);
  while (getline(SS, line, ',')) {
    std::cout << line << std::endl;
  };

  inFS.close();
  outFS.close();

  return 0;
}