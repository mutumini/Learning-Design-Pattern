#ifndef SRC_OBSERVERPATTERN_H_
#define SRC_OBSERVERPATTERN_H_  // NOLINT

#include <memory>
#include <vector>
#include <algorithm>

//! Design Principle
// Strive for loosely coupled designs between objects that interact.

// The Observer Pattern defines one-to-many dependency bewteen objects so that
// when one object changes state, all of its dependents are notified and updated automatically.

// PUSH scheme
class Observer {
public:
  using Tr = float;

  virtual ~Observer() = default;

  virtual void update(Tr temp, Tr humidity, Tr pressure) = 0;
};

class Subject {
public:
  virtual ~Subject() = default;

  virtual void addObserver(std::shared_ptr<Observer> observer)    = 0;
  virtual void removeObserver(std::shared_ptr<Observer> observer) = 0;
  virtual void notifyObservers()                                  = 0;

protected:
  std::vector<std::shared_ptr<Observer>> m_observers;
};

class WeatherData : public Subject {
public:
  using Tr = float;

  WeatherData() = default;

  void addObserver(std::shared_ptr<Observer> observer) override { m_observers.push_back(observer); }

  void removeObserver(std::shared_ptr<Observer> observer) override {
    m_observers.erase(std::remove(m_observers.begin(), m_observers.end(), observer), m_observers.end());
  }

  void notifyObservers() override {
    for (auto& observer : m_observers) {
      observer->update(m_temperature, m_humidity, m_pressure);
    }
  }

  void measurementsChanged() { notifyObservers(); }

  void setMeasurements(Tr temperature, Tr humidity, Tr pressure) {
    m_temperature = temperature;
    m_humidity    = humidity;
    m_pressure    = pressure;
    measurementsChanged();
  }

private:
  Tr m_temperature;
  Tr m_humidity;
  Tr m_pressure;
};

#endif  // SRC_OBSERVERPATTERN_H_
