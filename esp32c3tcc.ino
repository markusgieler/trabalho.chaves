//#include <Arduino.h>
//#include <WiFiClient.h>
//#include <ESPmDNS.h>
#include <Wire.h> // verificar a necessidade

#include "setup_webserver.h"
// #include "setup_bme280.h" // descomentar caso use sensor bme280
// #include "setup_mqtt.h" // descomentar caso use mqtt

static unsigned long lastSend_one = 0;
static unsigned long lastSend_two = 0;
const long interval_one = 2000;
const long interval_two = 7000;

//const char* mqtt_topic = "topico"; // descomentar caso use mqtt

void setup() {
  setup_webserver(); // webserver, e ja carrega o setup_wifi() indernamente

  //setup_mqtt(); // descomentar caso use mqtt

  //pinMode(LED_PIN, OUTPUT);
  //pinMode(GPIO_PIN_0, OUTPUT);
  //pinMode(GPIO_PIN_1, OUTPUT);
  //pinMode(GPIO_PIN_2, OUTPUT);
  //pinMode(GPIO_PIN_3, OUTPUT);
  //pinMode(GPIO_PIN_4, OUTPUT);

  //pinMode(GPIO_PIN_0, INPUT); // Temt6000 signal
  //pinMode(GPIO_PIN_1, INPUT);
  //pinMode(GPIO_PIN_2, INPUT);
  //pinMode(GPIO_PIN_3, INPUT);
  //pinMode(GPIO_PIN_4, INPUT);
}

void loop() {
  server.handleClient();

  // Lê os dados do sensor bme280
  //temperature = bme.readTemperature();
  //humidity = bme.readHumidity();
  //pressure = bme.readPressure() / 100.0F; // Conversão para hPa
  //altitude = bme.readAltitude(SEALEVELPRESSURE_HPA); // Calcular altitude

  // Lê os dados do sensor Temt6000
  /*sensorValue = analogRead(GPIO_PIN_0);  // Lê o valor do sensor
  voltage = sensorValue * (3.3 / 4095.0);  // Converte o valor ADC para voltagem
  luminosity = voltage * 1000;  // Converte a voltagem para unidade de luminosidade (aproximadamente)

  String payloadTemperature = String(temperature);
  String payloadHumi
  dity = String(humidity);
  String payloadPressure = String(pressure);
  String payloadAltitude = String(altitude);

  String payloadSensorValue = String(sensorValue);
  String payloadVoltage = String(voltage);
  String payloadLuminosity = String(luminosity);

  client.publish(mqtt_topic_temperature, payloadTemperature.c_str());
  client.publish(mqtt_topic_humidity, payloadHumidity.c_str());
  client.publish(mqtt_topic_pressure, payloadPressure.c_str());
  client.publish(mqtt_topic_altitude, payloadAltitude.c_str());*/

 // client.publish(mqtt_topic_sensor_value, payloadSensorValue.c_str());
 // client.publish(mqtt_topic_voltage, payloadVoltage.c_str());
  //client.publish(mqtt_topic_luminosity, payloadLuminosity.c_str());

  //Serial.print("Valor do Sensor: ");
  //Serial.print(sensorValue);
  //Serial.print("\tVoltagem: ");
  //Serial.print(voltage);
  //Serial.print(" V\tLuminosidade: ");
  //Serial.print(luminosity);
  //Serial.println(" lux");
  //Serial.println(analogRead(GPIO_PIN_0));
/*
  DynamicJsonDocument doc(1024);
  doc["DEVICE"] = esp32Board;
  doc["TEMPERATURA"] = payloadTemperature;
  doc["UMIDADE"] = payloadHumidity;
  doc["PRESSAO"] = payloadPressure;
  doc["ALTITUDE"] = payloadAltitude;
  doc["SENSOR"] = payloadSensorValue;
  doc["VOLTAGEM"] = payloadVoltage;
  doc["LUMINOSIDADE"] = payloadLuminosity;   
  //doc["analogico"] = valor1;
  char JSONmessageBuffer[300];
  serializeJson(doc, JSONmessageBuffer);
  client.publish(mqtt_topic, JSONmessageBuffer);
  Serial.print("msg json out enviado: ");
  Serial.println(JSONmessageBuffer);*/
}