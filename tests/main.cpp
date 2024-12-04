#include <iostream>

#include "TEST_Pattern.h"

int main(int argc, char* argv[]) {  // NOLINT
  std::cout << "Hello, World!" << std::endl;
  std::cout << "<--------------------------------------------------------------------------->" << std::endl;
  TestStrategyPattern();
  std::cout << "---------------------------------------------------------------------------" << std::endl;
  TestObserverPattern();
  std::cout << "---------------------------------------------------------------------------" << std::endl;
  return 0;
}
