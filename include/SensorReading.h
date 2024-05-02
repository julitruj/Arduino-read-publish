#ifndef SENSORREADING_H
#define SENSORREADING_H

#include <Arduino.h>
#include "DHT11Sensor.h"

class SensorReading {
public:
  SensorReading(uint8_t pin); // constructor de la clase SensorReading
  void begin(); // inicializa el sensor
  void readSensor(); // lee el sensor
  float getAverageTemperature(); // obtiene la temperatura promedio

private:
  DHT11Sensor _dhtSensor; // crea un objeto de la clase DHT11Sensor
  float _temperatureReadings[5]; // crea un arreglo para guardar las temperaturas
  uint8_t _readingCount; // crea una variable para contar las lecturas
  uint8_t _readingIndex; // crea una variable para guardar el índice
};

#endif