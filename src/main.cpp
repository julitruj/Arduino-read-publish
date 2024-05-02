#include <Arduino.h>
#include "SensorReading.h"
#include <PubSubClient.h>
#include <ArduinoJson.h>
#include <WiFiS3.h>
#include <SPI.h>
#include "constants.h"

WiFiClient espClient; // crea un cliente WiFi
PubSubClient client(espClient); // crea un cliente MQTT
SensorReading sensorReading(4); // crea un objeto de la clase SensorReading 

void reconnect(); 

void setup() {
  Serial.begin(9600); // inicia la comunicación serial
  Serial.println("hola...");
  
  WiFi.begin(ssid, password); // conecta el ESP32 a la red WiFi
  
  while (WiFi.status() != WL_CONNECTED) {
    delay(1000); // espera a que el ESP32 se conecte a la red WiFi
    Serial.println("Intentanto conexion al WiFi...");
  }
  Serial.println("Conectado al WiFi!");
  client.setServer(mqttServer, mqttPort); // configura el servidor MQTT
  sensorReading.begin(); // inicializa el sensor
}

void loop() {
  if (!client.connected()) {
  reconnect(); // reconecta al servidor MQTT si no está conectado
  }
  sensorReading.readSensor(); // lee el sensor
  float averageTemperature = sensorReading.getAverageTemperature(); // obtiene la temperatura promedio

  // Crea un objeto JSON con la temperatura promedio
  StaticJsonDocument<200> doc;
  doc["averageTemperature"] = averageTemperature;
  char jsonBuffer[200];
  serializeJson(doc, jsonBuffer);

  // Publica el mensaje en el tópico MQTT
  client.publish(mqttTopic, jsonBuffer);
  delay(5000); // espera 5 segundos antes de enviar el siguiente mensaje
}

void reconnect() {
  
  while (!client.connected()) {
    Serial.println("Intentando conexion al broker MQTT...");
  
  if (client.connect("ESP32Client")) {
    Serial.println("Conectado al broker MQTT");
    } else {
  
  Serial.print("No fue posible conexcion al broker MQTT, reintentando in 5 seconds...");
  delay(5000);
    }
  }
}