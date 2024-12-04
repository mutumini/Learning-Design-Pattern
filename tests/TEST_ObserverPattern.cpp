#include "ObserverPattern.h"

void TestObserverPattern() {  // NOLINT
  WeatherData weatherData;
  weatherData.setMeasurements(80f, 65f, 30.4f);

  CurrentCondtionsDisplay currentDisplay(weatherData);
  StatisticsDisplay       statisticsDisplay(weatherData);
  weatherData.setMeasurements(82f, 70f, 29.2f);
  weatherData.setMeasurements(78f, 90f, 29.2f);
  weatherData.setMeasurements(85f, 72f, 28.3f);
}
