/*
  Blink
  Turns on an LED on for one second, then off for one second, repeatedly.
  This example code is in the public domain.
*/

// Pin 13 has an LED connected on most Arduino boards.
// give it a name:
int led = 13;
// Delay in milliseconds
int delay_duration = 300;

// The setup routine runs once when you press reset:
void setup()
{
  // Initialize the digital pin as an output.
  pinMode(led, OUTPUT);
}

// The loop routine runs over and over again forever:
void loop() {
  // Turn the LED on (HIGH is the voltage level)
  digitalWrite(led, HIGH);
  // Wait for a second
  delay(delay_duration);
  // Turn the LED off by making the voltage LOW
  digitalWrite(led, LOW);
  // Wait for a second
  delay(delay_duration);
}

