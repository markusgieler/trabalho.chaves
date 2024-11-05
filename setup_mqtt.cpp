#include <WiFi.h>
#include <PubSubClient.h>
#include <ArduinoJson.h>
#include "setup_mqtt.h"
#include "setup_bme280.h"

// Defina as credenciais do servidor MQTT
const char* mqtt_server = "your_mqtt_server";
const char* mqtt_user = "your_mqtt_user";
const char* mqtt_password = "your_mqtt_password";
const int mqtt_port = 1883;

WiFiClient espClient;
PubSubClient client(espClient);

void setup_mqtt() {
  client.setServer(mqtt_server, 1883);
}

void reconnect_mqtt() {
  while (!client.connected()) {
    Serial.print("Conectando ao servidor MQTT...");
    if (client.connect("ESP32Client", mqtt_user, mqtt_password)) {
      Serial.println("conectado!");
    } else {
      Serial.print("falha, rc=");
      Serial.print(client.state());
      Serial.println(" tentando novamente em 5 segundos");
      delay(5000);
    }
  }
}

void publish_data(const char* topic, const char* payload) {
  if (!client.connected()) {
    reconnect_mqtt();
  }
  client.loop();
  client.publish(topic, payload);
}

void send_bme280_data(const char* topic) {
  StaticJsonDocument<200> doc;
  doc["temperature"] = bme.readTemperature();
  doc["humidity"] = bme.readHumidity();
  doc["pressure"] = bme.readPressure() / 100.0F;
  
  char buffer[512];
  serializeJson(doc, buffer);
  publish_data(topic, buffer);
}