#ifndef SRC_SINGLETONPATTERN_H_
#define SRC_SINGLETONPATTERN_H_  // NOLINT

#include <iostream>
#include <memory>

// The Singleton Pattern ensures a class has only one instance,
// and provides a global point of access to it.

class Singleton {
public:
  static Singleton& getInstance() {
    static Singleton m_unique;
    return m_unique;
  }

  void doSomething() { std::cout << "Singleton is doing something." << std::endl; }

private:
  Singleton() { std::cout << "Singleton constructor called." << std::endl; }
  Singleton(const Singleton&) = delete;
};

#endif  // SRC_SINGLETONPATTERN_H_
