


#include "TemperatureSensor.h"

// Hardware pin definitions
const int PinTemperature = 2;
const int PinO2Sensor = 3;
const int PinCO2Sensor = 4;
const int PinpHSensor = 5;
const int PinAirMoisture = 6;
const int PinSoilMoisture = 7;
const int PinLightSensor = 8;
const int PinDoorSensor = 9;
const int PinRainGauge = 10;

const int PinOutputTooHot = 12;
const int PinOutputTooCold = 13;

const int HotTemperatureThreshold = 30;
const int ColdTemperatureThreshold = 15;

// Global variables

const unsigned long MillisPerLoop = 100;
unsigned long TimeMillis = 0;



// put your setup code here, to run once
void setup()
{
  Serial.begin(115200);
  Serial.println("Beginning setup of PlantKeeper.");

  // Set the output pins as outputs, set low
  pinMode(PinOutputTooHot, OUTPUT);
  pinMode(PinOutputTooCold, OUTPUT);

  // Run the setup for each of the sensors
  TemperatureSetup(PinTemperature);

  // TODO: Implement all of these sensors
  
  /*
  O2SensorSetup(PinO2Sensor);
  CO2SensorSetup(PinCO2Sensor);
  pHSensorSetup(PinpHSensor);
  AirMoistureSetup(PinAirMoisture);
  LightSensorSetup(PinLightSensor);
  DoorSensorSetup(PinDoorSensor);
  RainGaugeSetup(PinRainGauge);
  Setup(Pin);
  */

}

// put your main code here, to run repeatedly
void loop()
{
  // Get the current millisecond count
  unsigned long CurrentMillis = millis();
  
  // Find out how much time has elapsed since the previous loop
  unsigned long ElapsedTimeMillis = CurrentMillis - TimeMillis;

  // If not enough time has elapsed, return
  if (ElapsedTimeMillis < MillisPerLoop)
    return;

  Serial.println("Running loop of PlantKeeper.");


  // Run the loop for each of the sensors
  int temperature = TemperatureLoop(PinTemperature);

  // TODO: Implement all of these sensors

  /*
  O2SensorLoop(PinO2Sensor);
  CO2SensorLoop(PinCO2Sensor);
  pHSensorLoop(PinpHSensor);
  AirMoistureLoop(PinAirMoisture);
  LightSensorLoop(PinLightSensor);
  DoorSensorLoop(PinDoorSensor);
  RainGaugeLoop(PinRainGauge);
  Loop(Pin);
  */

  // If it is too hot
  if (temperature >  HotTemperatureThreshold)
  {
    Serial.println("It is too hot!");

    // Turn on the "too hot" alarm
    digitalWrite(PinOutputTooHot, 1);
  }

  // Else, it is not too hot
  else
  {
    // Turn off the "too hot" alarm
    digitalWrite(PinOutputTooHot, 0);
  }

  // If it is too cold
  if (temperature < ColdTemperatureThreshold)
  {
    Serial.println("It is too cold!");

    // Turn on the "too cold" alarm
    digitalWrite(PinOutputTooCold, 1);
  }

  // Else, it is not too cold
  else
  {
    // Turn off the "too cold" alarm
    digitalWrite(PinOutputTooCold, 0);
  }

  // Save the new time
  TimeMillis = CurrentMillis;
}
