
// TemperatureSensor.h
#ifndef TEMPERATURE_SENSOR_H
#define TEMPERATURE_SENSOR_H

// Include all the standard Arduino libraries
#include <arduino.h>

// Function prototypes
bool TemperatureSetup(int SensorPin);
int TemperatureLoop(int SensorPin);



#endif // TEMPERATURE_SENSOR_H
