#include "DHT11Sensor.h"

DHT11Sensor::DHT11Sensor(uint8_t pin) : _dht(pin, DHT11) {} // constructor de la clase DHT11Sensor

void DHT11Sensor::begin() {
    _dht.begin(); // inicializa el sensor
}

float DHT11Sensor::readTemperature() {
    return _dht.readTemperature(); // lee la temperatura
}
