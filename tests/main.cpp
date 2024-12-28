#include <iostream>

#include "TEST.h"

int main(int argc, char* argv[]) {  // NOLINT
  std::cout << "Hello, World!\n";

  TestStrategyPattern();

  TestObserverPattern();

  TestDecoratorPattern();

  TestSimpleFactory();

  TestFactoryMethodPattern();

  TestAbstractFactoryPattern();

  TestSingletonPattern();

  return 0;
}
