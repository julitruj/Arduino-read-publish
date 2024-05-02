#ifndef DHT11SENSOR_H
#define DHT11SENSOR_H

#include <Arduino.h>
#include <DHT.h>

class DHT11Sensor {
public:
    DHT11Sensor(uint8_t pin); // constructor de la clase DHT11Sensor
    void begin();
    float readTemperature(); // lee la temperatura

private:
    DHT _dht; // crea un objeto de la clase DHT
};

#endif