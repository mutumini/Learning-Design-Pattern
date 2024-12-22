#include <iostream>
#include <memory>

#include "FactoryMethodPattern.h"
#include "TEST.h"

void TestFactoryMethodPattern() {
  PrintSingleLine();
  std::cout << "Test Factory Method Pattern!\n";
  std::unique_ptr<PizzaStore> store{std::make_unique<NYPizzaStore>()};
  store->orderPizza(PizzaType::kCheese);
  store->orderPizza(PizzaType::kPepperoni);

  store = std::make_unique<ChicagoPizzaStore>();
  store->orderPizza(PizzaType::kCheese);
  store->orderPizza(PizzaType::kPepperoni);
  store->orderPizza(PizzaType::kInvalid);
}