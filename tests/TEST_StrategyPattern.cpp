#include <iostream>
#include <memory>

#include "StrategyPattern.h"
#include "TEST.h"

void TestStrategyPattern() {
  std::cout << "Test Strategy Pattern!\n";

  std::unique_ptr<Duck> duck = std::make_unique<MallardDuck>();
  duck->performQuack();
  duck->setQuackBehavior(std::make_shared<Squeak>());
  duck->performQuack();
}