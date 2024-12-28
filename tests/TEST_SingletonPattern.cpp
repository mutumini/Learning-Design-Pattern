#include <iostream>
#include <memory>

#include "SingletonPattern.h"
#include "TEST.h"

void TestSingletonPattern() {
  PrintSingleLine();
  std::cout << "Test Singleton Pattern!\n";
  Singleton::getInstance().doSomething();
}