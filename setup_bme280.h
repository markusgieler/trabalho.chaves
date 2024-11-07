#ifndef SETUP_BME280_H
#define SETUP_BME280_H

#include <Wire.h>
#include <Adafruit_Sensor.h>
#include <Adafruit_BME280.h>

extern Adafruit_BME280 bme280; // Declaração externa do objeto BME280

bool setup_bme280();

#endif // SETUP_BME280_H