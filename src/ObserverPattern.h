#ifndef SRC_OBSERVERPATTERN_H_
#define SRC_OBSERVERPATTERN_H_  // NOLINT

#include <algorithm>
#include <iostream>
#include <memory>
#include <numeric>
#include <vector>

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
  virtual void notifyObservers() const noexcept                   = 0;

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

  void notifyObservers() const noexcept override {
    for (auto& observer : m_observers) {
      observer->update(m_temperature, m_humidity, m_pressure);
    }
  }

  void measurementsChanged() const noexcept { notifyObservers(); }

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

class CurrentCondtionsDisplay : public Observer {
public:
  CurrentCondtionsDisplay(WeatherData& weatherData) : m_weatherData(weatherData) {
    m_weatherData = weatherData;
    weatherData.addObserver(std::make_shared<CurrentCondtionsDisplay>(*this));
  }

  void update(float temperature, float humidity, float pressure) override {
    m_temperature = temperature;
    m_humidity    = humidity;
    m_pressure    = pressure;
    display();
  }

  void display() const noexcept {
    std::cout << "Current conditions: " << m_temperature << "F degrees, " << m_humidity
              << "% humidity, and " << m_pressure << " pressure.\n";
  }

private:
  float       m_temperature;
  float       m_humidity;
  float       m_pressure;
  WeatherData m_weatherData;
};

class StatisticsDisplay : public Observer {
public:
  using Tr = float;

  StatisticsDisplay(WeatherData& weatherData) {
    m_weatherData = weatherData;
    weatherData.addObserver(std::make_shared<StatisticsDisplay>(*this));
  }

  void update(Tr temperature, Tr humidity, Tr pressure) override {
    m_temperature.push_back(temperature);
    display();
  }
  void display() const noexcept {
    auto [minIt, maxIt] = std::minmax_element(m_temperature.begin(), m_temperature.end());
    double avg = std::accumulate(m_temperature.begin(), m_temperature.end(), 0.0f) / m_temperature.size();

    std::cout << "Avg/Max/Min temperature = " << avg << "/" << *maxIt << "/" << *minIt << std::endl;
  }

private:
  std::vector<Tr> m_temperature;
  WeatherData     m_weatherData;
};

#endif  // SRC_OBSERVERPATTERN_H_
