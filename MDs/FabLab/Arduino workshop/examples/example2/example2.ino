/*
  Turns on an LED on for one if it get's dark
  This example code is in the public domain.
*/

// Pin 13 has an LED connected on most Arduino boards.
// give it a name:
int led = 13;

// Pin A0 is connected to the photo diode.
int analogPin = 1;

// Minimum sensor value
int minimum_sensor_value = 20;

// The setup routine runs once when you press reset:
void setup()
{
  // Initialize the digital pin as an output.
  pinMode(led, OUTPUT);
}

// The loop routine runs over and over again forever:
void loop()
{
  // Read the sensor data from the photo diode
  int sensorValue = analogRead(analogPin);
  // if it is dark
  if (sensorValue <= minimum_sensor_value) {
    // turn the LED on (HIGH is the voltage level)
    digitalWrite(led, HIGH);
  // else
  } else{
    // turn the LED off by making the voltage LOW
    digitalWrite(led, LOW);
  }
}

