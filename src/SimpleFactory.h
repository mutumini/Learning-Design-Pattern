#ifndef SRC_SIMPLEFACTORY_H_
#define SRC_SIMPLEFACTORY_H_  // NOLINT

// The Simple Factory isn't actually a design pattern; it's more of a programming
// idiom. It's a way to encapsulate object creation details.

#include <iostream>
#include <memory>
#include <string>

enum struct PizzaType : int { kInvalid = -1, kCheese = 0, kPepperoni };

class Pizza {
public:
  Pizza() = default;
  explicit Pizza(const std::string& name) : m_name(name) {}
  virtual ~Pizza() = default;

  void prepare() const noexcept { std::cout << "Preparing " << m_name << std::endl; }

  void bake() const noexcept { std::cout << "Bake for 25 minutes at 350 degrees" << std::endl; }
  void cut() const noexcept { std::cout << "Cutting the pizza into diagonal slices" << std::endl; }
  void box() const noexcept { std::cout << "Place pizza in official PizzaStore box" << std::endl; }

private:
  std::string m_name;
};

class CheesePizza : public Pizza {
public:
  CheesePizza() : Pizza("Cheese") {}
};

class PepperoniPizza : public Pizza {
public:
  PepperoniPizza() : Pizza("Pepperoni") {}
};

class SimplePizzaFactory {
public:
  std::unique_ptr<Pizza> createPizza(PizzaType type) const {
    switch (type) {
      case PizzaType::kCheese:
        return std::make_unique<CheesePizza>();
      case PizzaType::kPepperoni:
        return std::make_unique<PepperoniPizza>();
      default:
        std::cout << "Error: Invalid pizza type" << std::endl;
        return nullptr;
    }
  }
};

#endif  // SRC_SIMPLEFACTORY_H_
