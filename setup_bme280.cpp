#include "setup_bme280.h"
#include <Wire.h>

Adafruit_BME280 bme280; // Criação da instância do sensor BME280

#define I2C_SDA 8  // GPIO I2C_SDA no ESP32 C3
#define I2C_SCL 9  // GPIO I2C_SCL no ESP32 C3

#define SEALEVELPRESSURE_HPA (1013.25)

bool setup_bme280() {
  Wire.begin(I2C_SDA, I2C_SCL);

  if (!bme280.begin(0x76)) {  // O endereço padrão I2C do BME280 pode ser 0x76 ou 0x77
    Serial.println("Não foi possível encontrar o sensor BME280. Verifique a conexão!");
    return false;
  }

  Serial.println("Sensor BME280 inicializado com sucesso");
  Serial.print("Temperatura: ");
  Serial.print(bme280.readTemperature());
  Serial.println(" °C");
  Serial.print("Umidade: ");
  Serial.print(bme280.readHumidity());
  Serial.println(" %");
  Serial.print("Pressão: ");
  Serial.print(bme280.readPressure() / 100.0F);
  Serial.println(" hPa");
  Serial.print(bme280.readAltitude(SEALEVELPRESSURE_HPA));
  Serial.println(" m");

  return true;
}