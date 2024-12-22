#include <iostream>
#include <memory>

#include "AbstractFactoryPattern.h"
#include "TEST.h"

void TestAbstractFactoryPattern() {
  PrintSingleLine();
  std::cout << "Test Abstract Factory Pattern!\n";
  std::unique_ptr<PizzaStore> store{std::make_unique<NYPizzaStore>()};
  std::cout << '\n';
  store->orderPizza(PizzaType::kCheese);
  std::cout << '\n';
  store->orderPizza(PizzaType::kPepperoni);
  std::cout << '\n';

  store = std::make_unique<ChicagoPizzaStore>();
  store->orderPizza(PizzaType::kCheese);
  std::cout << '\n';
  store->orderPizza(PizzaType::kPepperoni);
  std::cout << '\n';
  store->orderPizza(PizzaType::kInvalid);
}