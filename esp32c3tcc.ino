//#include <Arduino.h>
//#include <WiFiClient.h>
//#include <ESPmDNS.h>
#include <Wire.h>

//#include "setup_wifi.h"
#include "setup_webserver.h"
#include "setup_bme280.h"
#include "setup_mqtt.h"

static unsigned long lastSend_one = 0;
static unsigned long lastSend_two = 0;
const long interval_one = 2000;
const long interval_two = 7000;

//bme280
//float temperature = 0;
//float humidity = 0;
//float pressure = 0;
//float altitude = 0;

// Temt6000
//int sensorValue = 0;
//float voltage = 0;
//float luminosity = 0;

const char* mqtt_topic = "topico";

void setup() {
  Serial.begin(115200);
  //Wire.begin(I2C_SDA, I2C_SCL);

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

  //client.setServer(mqtt_server, mqtt_port);


  
  //setup_wifi();
  setup_webserver(); 
  setup_mqtt();

  setup_bme280();
  //if (!setup_bme280()) { 
  //  Serial.println("Falha ao inicializar o sensor BME280!"); 
    //while (1); // Loop infinito caso o sensor não seja encontrado   
  //}
}

void loop() {
  server.handleClient();

  //if (!client.connected()) {
  //  reconnect();
  //}
  //client.loop();


  // Envia dados do BME280 via MQTT a cada 10 segundos
  //static unsigned long lastSend_one = 0;
  if (millis() - lastSend_one >= interval_one) {
    lastSend_one = millis();
    send_bme280_data(mqtt_topic); 
    //publish_data(mqtt_topic, bme280.readTemperature());
  }

  // Segundo temporizador
  //static unsigned long lastSend = 0;
  //if (millis() - lastSend_two >= interval_two) {
  //  lastSend_two = millis();
  //  //send_bme280_data(mqtt_topic); 
  //  publish_data(mqtt_topic, "teste");
  //}


  //delay(2);//allow the cpu to switch to other tasks

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