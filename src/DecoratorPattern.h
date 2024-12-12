#ifndef SRC_DECORATORPATTERN_H_
#define SRC_DECORATORPATTERN_H_  // NOLINT

#include <iostream>
#include <memory>
#include <string>

//! Design Principle
// Classes should be open for extension, but closed for modification.

// The Decorator Pattern attaches additional reponsibilities to an object
// dynamically. Decorators provide a flexible alternative to subclassing
// for extending functionality.

//! Component
class Beverage {
public:
  Beverage() = default;
  explicit Beverage(const std::string& description) noexcept : m_description(description) {}
  virtual ~Beverage() = default;

  virtual float       cost() const noexcept = 0;
  virtual std::string getDescription() const noexcept { return m_description; }

private:
  std::string m_description{"Unknown Beverage"};
};

class Espresso : public Beverage {
public:
  Espresso() : Beverage("Espresso") {}
  float cost() const noexcept override { return 1.99f; }
};

class HouseBlend : public Beverage {
public:
  HouseBlend() : Beverage("House Blend Coffee") {}
  float cost() const noexcept override { return 0.89f; }
};

//! Decorator
class CondimentDecorator : public Beverage {
public:
  explicit CondimentDecorator(std::shared_ptr<Beverage> beverage) : m_beverage(beverage) {}

protected:
  std::shared_ptr<Beverage> m_beverage;
};

class Mocha : public CondimentDecorator {
public:
  explicit Mocha(std::shared_ptr<Beverage> beverage) : CondimentDecorator(beverage) {}
  std::string getDescription() const noexcept override { return m_beverage->getDescription() + ", Mocha"; }
  float       cost() const noexcept override { return m_beverage->cost() + 0.2f; }
};

class WhipCream : public CondimentDecorator {
public:
  explicit WhipCream(std::shared_ptr<Beverage> beverage) : CondimentDecorator(beverage) {}
  std::string getDescription() const noexcept override {
    return m_beverage->getDescription() + ", Whip Cream";
  }
  float cost() const noexcept override { return m_beverage->cost() + 0.1f; }
};

#endif  // SRC_DECORATORPATTERN_H_
