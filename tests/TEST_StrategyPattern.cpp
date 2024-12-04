#include <iostream>
#include <memory>

#include "StrategyPattern.h"
#include "TEST_Pattern.h"

void TestStrategyPattern() {  // NOLINT
  std::cout << "Test Strategy Pattern!" << std::endl;

  std::shared_ptr<Duck> duck = std::make_shared<MallardDuck>();
  duck->performQuack();
  duck->setQuackBehavior(std::make_shared<Squeak>());
  duck->performQuack();
  duck->swim();
}