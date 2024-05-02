#include "SensorReading.h"
#include <ArduinoJson.h>
#include "WiFiS3.h"
#include <SPI.h>
#include <MQTT.h>
#include "SensorReading.h"

SensorReading::SensorReading(uint8_t pin) : _dhtSensor(pin), _readingCount(0), _readingIndex(0) {} // constructor de la clase SensorReading

void SensorReading::begin() {
  _dhtSensor.begin(); // inicializa el sensor
}
void SensorReading::readSensor() {
float temperature = _dhtSensor.readTemperature(); // lee la temperatura

if (!isnan(temperature)) {
  _temperatureReadings[_readingIndex] = temperature; // guarda la temperatura en el arrey
  _readingIndex = (_readingIndex + 1) % 5; // incrementa el índice y lo reinicia si es mayor a 5

if (_readingCount < 5) {
  _readingCount++; // incrementa el contador de lecturas
    }
  }
}
float SensorReading::getAverageTemperature() {

if (_readingCount == 0) {
  return 0; // retorna 0 si no hay lecturas
}

float sum = 0;

for (uint8_t i = 0; i < _readingCount; i++) {
  sum += _temperatureReadings[i]; // suma las temperaturas
}

return sum / _readingCount; // retorna el promedio de las temperaturas
}
