#include <iostream>

#include "TEST_Pattern.h"

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
  return 0;
}
