/*
  Blink
  Turns on an LED on for one second, then off for one second, repeatedly.
 
  This example code is in the public domain.
 */
 
// Pin 13 has an LED connected on most Arduino boards.
// give it a name:
int redPin = 12;                  // Red LED connected to digital pin 12
int greenPin = 11;                // Green LED connected to digital pin 11

void setup()                      // run once, when the sketch starts
{
  pinMode(redPin, OUTPUT);        // sets the digital pin as output
  pinMode(greenPin, OUTPUT);      // sets the digital pin as output
}

void loop()                       // run over and over again
{
  digitalWrite(redPin, HIGH);     // sets the Red LED on
  digitalWrite(greenPin, HIGH);   // sets the Green LED on
  delay(100);                     // waits for half a second
  digitalWrite(redPin, HIGH);     // sets the Red LED on
  digitalWrite(greenPin, LOW);    // sets the Green LED off
  delay(300);                     // waits for half a second
  digitalWrite(redPin, LOW);      // sets the Red LED off
  digitalWrite(greenPin, LOW);    // sets the Green LED off
  delay(100);                     // waits for half a second
  digitalWrite(redPin, LOW);      // sets the Red LED off
  digitalWrite(greenPin, HIGH);   // sets the Green LED on
  delay(700);                     // waits for half a second
}