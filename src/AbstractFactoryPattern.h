#ifndef SRC_ABSTRACTFACTORYPATTERN_H_
#define SRC_ABSTRACTFACTORYPATTERN_H_  // NOLINT

#include <iostream>
#include <memory>

// The Abstract Factory Pattern provides an interface for creating families
// of related or dependent objects without specifying their concrete classes.

namespace {
enum struct PizzaType {
  kInvalid = -1,
  kCheese  = 0,
  kPepperoni,
};

class Cheese {
public:
  Cheese() = default;
  Cheese(const std::string& name) : m_name(name) {}
  virtual ~Cheese() = default;

  const std::string& getName() const noexcept { return m_name; }

private:
  std::string m_name;
};

class Pepperoni {
public:
  Pepperoni() = default;
  Pepperoni(const std::string& name) : m_name(name) {}
  virtual ~Pepperoni() = default;

  const std::string& getName() const noexcept { return m_name; }

private:
  std::string m_name;
};

class Sauce {
public:
  Sauce() = default;
  Sauce(const std::string& name) : m_name(name) {}
  virtual ~Sauce() = default;

  const std::string& getName() const noexcept { return m_name; }

private:
  std::string m_name;
};

class ReggianoCheese : public Cheese {
public:
  ReggianoCheese() : Cheese("Reggiano Cheese") {}
};

class MarinaraSauce : public Sauce {
public:
  MarinaraSauce() : Sauce("Marinara Sauce") {}
};

class SlicedPepperoni : public Pepperoni {
public:
  SlicedPepperoni() : Pepperoni("Sliced Pepperoni") {}
};

class MozzarellaCheese : public Cheese {
public:
  MozzarellaCheese() : Cheese("Mozzarella Cheese") {}
};

class PlumTomatoSauce : public Sauce {
public:
  PlumTomatoSauce() : Sauce("Plum Tomato Sauce") {}
};

class FrozenPepperoni : public Pepperoni {
public:
  FrozenPepperoni() : Pepperoni("Frozen Pepperoni") {}
};

class PizzaIngredientFactory {
public:
  virtual ~PizzaIngredientFactory()                          = default;
  virtual std::unique_ptr<Cheese>    createCheese() const    = 0;
  virtual std::unique_ptr<Pepperoni> createPepperoni() const = 0;
  virtual std::unique_ptr<Sauce>     createSauce() const     = 0;
};

class NYPizzaIngredientFactory : public PizzaIngredientFactory {
public:
  std::unique_ptr<Cheese>    createCheese() const override { return std::make_unique<ReggianoCheese>(); }
  std::unique_ptr<Pepperoni> createPepperoni() const override {
    return std::make_unique<SlicedPepperoni>();
  }
  std::unique_ptr<Sauce> createSauce() const override { return std::make_unique<MarinaraSauce>(); }
};

class ChicagoPizzaIngredientFactory : public PizzaIngredientFactory {
public:
  std::unique_ptr<Cheese>    createCheese() const override { return std::make_unique<MozzarellaCheese>(); }
  std::unique_ptr<Pepperoni> createPepperoni() const override {
    return std::make_unique<FrozenPepperoni>();
  }
  std::unique_ptr<Sauce> createSauce() const override { return std::make_unique<PlumTomatoSauce>(); }
};

class Pizza {
public:
  Pizza() = default;
  Pizza(const std::string& name) : m_name(name) {}
  virtual ~Pizza() = default;

  virtual void prepare() noexcept = 0;
  void         bake() const noexcept { std::cout << "Bake for 25 minutes at 350 degrees" << std::endl; }
  void         cut() const noexcept { std::cout << "Cutting the pizza into diagonal slices" << std::endl; }
  void         box() const noexcept { std::cout << "Place pizza in official PizzaStore box" << std::endl; }
  void         setName(const std::string& name) noexcept { m_name = name; }

protected:
  std::string                m_name;
  std::unique_ptr<Cheese>    m_cheese;
  std::unique_ptr<Pepperoni> m_pepperoni;
  std::unique_ptr<Sauce>     m_sauce;
};

class CheesePizza : public Pizza {
public:
  CheesePizza(const std::shared_ptr<PizzaIngredientFactory>& ingredient_factory)
      : Pizza("CheesePizza"), m_ingredientFactory(ingredient_factory) {}
  void prepare() noexcept override {
    m_cheese = m_ingredientFactory->createCheese();
    m_sauce  = m_ingredientFactory->createSauce();
    std::cout << "Preparing " << m_name << std::endl;
    std::cout << "Cheese: " << m_cheese->getName() << std::endl;
    std::cout << "Sauce: " << m_sauce->getName() << std::endl;
  }

private:
  std::shared_ptr<PizzaIngredientFactory> m_ingredientFactory;
};

class PepperoniPizza : public Pizza {
public:
  PepperoniPizza(const std::shared_ptr<PizzaIngredientFactory>& ingredient_factory)
      : Pizza("PepperoniPizza"), m_ingredientFactory(ingredient_factory) {}
  void prepare() noexcept override {
    m_pepperoni = m_ingredientFactory->createPepperoni();
    std::cout << "Preparing " << m_name << std::endl;
    std::cout << "Pepperoni: " << m_pepperoni->getName() << std::endl;
  }

private:
  std::shared_ptr<PizzaIngredientFactory> m_ingredientFactory;
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
public:
  std::unique_ptr<Pizza> createPizza(PizzaType type) const override {
    std::unique_ptr<Pizza>                  pizza{nullptr};
    std::shared_ptr<PizzaIngredientFactory> ingredient_factory =
        std::make_shared<NYPizzaIngredientFactory>();
    switch (type) {
      case PizzaType::kCheese:
        pizza = std::make_unique<CheesePizza>(ingredient_factory);
        pizza->setName("NY Style Cheese Pizza");
        break;
      case PizzaType::kPepperoni:
        pizza = std::make_unique<PepperoniPizza>(ingredient_factory);
        pizza->setName("NY Style Pepperoni Pizza");
        break;
      default:
        break;
    }
    return pizza;
  }
};

class ChicagoPizzaStore : public PizzaStore {
public:
  std::unique_ptr<Pizza> createPizza(PizzaType type) const override {
    std::unique_ptr<Pizza>                  pizza{nullptr};
    std::shared_ptr<PizzaIngredientFactory> ingredient_factory =
        std::make_shared<ChicagoPizzaIngredientFactory>();
    switch (type) {
      case PizzaType::kCheese:
        pizza = std::make_unique<CheesePizza>(ingredient_factory);
        pizza->setName("Chicago Style Cheese Pizza");
        break;
      case PizzaType::kPepperoni:
        pizza = std::make_unique<PepperoniPizza>(ingredient_factory);
        pizza->setName("Chicago Style Pepperoni Pizza");
        break;
      default:
        break;
    }
    return pizza;
  }
};

}  // namespace

#endif  // SRC_ABSTRACTFACTORYPATTERN_H_
