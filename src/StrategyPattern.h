#ifndef SRC_STRATEGYPATTERN_H_
#define SRC_STRATEGYPATTERN_H_  // NOLINT

#include <iostream>
#include <memory>

//! Design Principle
// Identify the aspects of your application that vary and separate
// them from what stays the same.
// Program to an interface, not an implementation.
// Favor composition over inheritance.

// The Strategy Pattern defines a family of algorithms,
// encapsulates each one, and makes them interchangeable.
// Strategy lets the algorithm vary independently from clients that use it.

class QuackBehavior {
public:
  virtual void quack() const noexcept = 0;
};

class Quack : public QuackBehavior {
public:
  void quack() const noexcept override { std::cout << "Quack! From Quack::quack()\n"; }
};

class Squeak : public QuackBehavior {
public:
  void quack() const noexcept override { std::cout << "Squeak! From Squeak::quack()\n"; }
};

class Duck {
public:
  Duck() = default;
  Duck(const std::shared_ptr<QuackBehavior> quack) : m_quackBehavior(quack) {}

  void performQuack() const noexcept { m_quackBehavior->quack(); }

  void setQuackBehavior(std::shared_ptr<QuackBehavior> quack) noexcept { m_quackBehavior = quack; }

private:
  std::shared_ptr<QuackBehavior> m_quackBehavior;
};

class MallardDuck : public Duck {
public:
  MallardDuck() : Duck(std::make_shared<Quack>()) {}
};

#endif  // SRC_STRATEGYPATTERN_H_
