#include <iostream>
#include <memory>

#include "SimpleFactory.h"
#include "TEST.h"

template <typename Factory>
void OrderPizza(const Factory& factory, PizzaType type) {
  std::unique_ptr<Pizza> pizza{nullptr};
  pizza = factory.createPizza(type);
  if (pizza) {
    pizza->prepare();
    pizza->bake();
    pizza->cut();
    pizza->box();
  } else {
    std::cout << "Pizza not available\n";
  }
}

void TestSimpleFactory() {
  PrintSingleLine();
  std::cout << "Test Simple Factory!\n";
  SimplePizzaFactory factory;
  OrderPizza(factory, PizzaType::kCheese);
  OrderPizza(factory, PizzaType::kPepperoni);
  OrderPizza(factory, PizzaType::kInvalid);
}