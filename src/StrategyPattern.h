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
  virtual void quack() = 0;
};

class Quack : public QuackBehavior {
public:
  void quack() override { std::cout << "Quack! From Quack::quack()" << std::endl; }
};

class Squeak : public QuackBehavior {
public:
  void quack() override { std::cout << "Squeak! From Squeak::quack()" << std::endl; }
};

class Duck {
public:
  Duck() = default;
  void         performQuack() { m_quack_behavior->quack(); }
  virtual void setQuackBehavior(std::shared_ptr<QuackBehavior> quack) { this->m_quack_behavior = quack; }
  void         swim() { std::cout << "All ducks can swim, even decoys! From Duck::swim()" << std::endl; }

protected:
  std::shared_ptr<QuackBehavior> m_quack_behavior;

private:
};

class MallardDuck : public Duck {
public:
  MallardDuck() { this->m_quack_behavior = std::make_shared<Quack>(); }
};

#endif  // SRC_STRATEGYPATTERN_H_
