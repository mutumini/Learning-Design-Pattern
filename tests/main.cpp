#include <iostream>

#include "TEST.h"

void PrintSingleLine() {
  std::cout << "<--------------------------------------------------------------------------->\n";
}

int main(int argc, char* argv[]) {  // NOLINT
  std::cout << "Hello, World!\n";

  TestStrategyPattern();

  TestObserverPattern();

  TestDecoratorPattern();

  TestSimpleFactory();

  TestFactoryMethodPattern();

  return 0;
}
