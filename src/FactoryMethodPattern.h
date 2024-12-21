#ifndef SRC_FACTORYMETHODPATTERN_H_
#define SRC_FACTORYMETHODPATTERN_H_  // NOLINT

#include <iostream>
#include <memory>

#include "SimpleFactory.h"

//! Design Principle
// Depend upon abstractions. Do not depend upon concrete classes.

// The Factory Method Pattern defines an interface for creating an object,
// but lets subclasses decide which class to instantiate. Factory Method
// lets a class defer instantiation to subclasses.

class NYStyleCheesePizza : public Pizza {
public:
  NYStyleCheesePizza() : Pizza("NYStyleCheesePizza") {}
};

class NYStylePepperoniPizza : public Pizza {
public:
  NYStylePepperoniPizza() : Pizza("NYStylePepperoniPizza") {}
};

class ChicagoStyleCheesePizza : public Pizza {
public:
  ChicagoStyleCheesePizza() : Pizza("ChicagoStyleCheesePizza") {}
};

class ChicagoStylePepperoniPizza : public Pizza {
public:
  ChicagoStylePepperoniPizza() : Pizza("ChicagoStylePepperoniPizza") {}
};

class PizzaStore {
public:
  void orderPizza(PizzaType type) {
    std::unique_ptr<Pizza> pizza{createPizza(type)};
    if (pizza) {
      pizza->prepare();
      pizza->bake();
      pizza->cut();
      pizza->box();
    } else {
      std::cout << "Pizza not available\n";
    }
  }

private:
  virtual std::unique_ptr<Pizza> createPizza(PizzaType type) const = 0;
};

class NYPizzaStore : public PizzaStore {
  std::unique_ptr<Pizza> createPizza(PizzaType type) const override {
    switch (type) {
      case PizzaType::kCheese:
        return std::make_unique<NYStyleCheesePizza>();
      case PizzaType::kPepperoni:
        return std::make_unique<NYStylePepperoniPizza>();
      default:
        std::cout << "Error: invalid pizza type\n";
        return nullptr;
    }
  }
};

class ChicagoPizzaStore : public PizzaStore {
  std::unique_ptr<Pizza> createPizza(PizzaType type) const override {
    switch (type) {
      case PizzaType::kCheese:
        return std::make_unique<ChicagoStyleCheesePizza>();
      case PizzaType::kPepperoni:
        return std::make_unique<ChicagoStylePepperoniPizza>();
      default:
        std::cout << "Error: invalid pizza type\n";
        return nullptr;
    }
  }
};

#endif  // SRC_FACTORYMETHODPATTERN_H_
