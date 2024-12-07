#include "ObserverPattern.h"
#include "TEST.h"

void TestObserverPattern() {
  std::cout << "Test Observer Pattern!\n";

  WeatherData weatherData;
  weatherData.setMeasurements(80, 65, 30.4f);

  CurrentCondtionsDisplay currentDisplay(weatherData);
  StatisticsDisplay       statisticsDisplay(weatherData);
  weatherData.setMeasurements(82, 70, 29.2f);
  weatherData.setMeasurements(78, 90, 29.2f);
  weatherData.setMeasurements(85, 72, 28.3f);
}
