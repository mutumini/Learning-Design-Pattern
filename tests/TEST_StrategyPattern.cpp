#include <iostream>
#include <memory>

#include "StrategyPattern.h"

void RunMain(int argc, char* argv[]) {  // NOLINT
  std::cout << "Test Strategy Pattern!" << std::endl;

  std::shared_ptr<Duck> duck = std::make_shared<MallardDuck>();
  duck->performQuack();
  duck->setQuackBehavior(std::make_shared<Squeak>());
  duck->performQuack();
  duck->swim();
}