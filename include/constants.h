#ifndef CONSTANTS_H
#define CONSTANTS_H

#include <Arduino.h>

// credenciales de la red WiFi
extern const char* ssid;
extern const char* password;

// credenciales del servidor MQTT
extern const char* mqttServer;
extern const int mqttPort;
extern const char* mqttTopic;

// constantes del sensor DHT11
const uint8_t SENSOR_PIN = 4;

#endif