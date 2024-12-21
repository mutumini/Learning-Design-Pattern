#include <memory>

#include "DecoratorPattern.h"
#include "TEST.h"

void TestDecoratorPattern() {
  PrintSingleLine();
  std::cout << "Test Decorator Pattern!\n";

  std::shared_ptr<Beverage> beverage{std::make_shared<Espresso>()};
  beverage = std::make_shared<Mocha>(beverage);
  beverage = std::make_shared<WhipCream>(beverage);
  std::cout << beverage->getDescription() << " $" << beverage->cost() << std::endl;

  beverage = std::make_shared<HouseBlend>();
  beverage = std::make_shared<Mocha>(beverage);
  beverage = std::make_shared<Mocha>(beverage);
  beverage = std::make_shared<WhipCream>(beverage);
  std::cout << beverage->getDescription() << " $" << beverage->cost() << std::endl;
}