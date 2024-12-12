#include <iostream>

#include "TEST.h"

void PrintSingleLine() {
  std::cout << "<--------------------------------------------------------------------------->\n";
}

int main(int argc, char* argv[]) {  // NOLINT
  std::cout << "Hello, World!\n";

  PrintSingleLine();
  TestStrategyPattern();

  PrintSingleLine();
  TestObserverPattern();

  PrintSingleLine();
  TestDecoratorPattern();

  PrintSingleLine();
  TestSimpleFactory();

  PrintSingleLine();
  return 0;
}
