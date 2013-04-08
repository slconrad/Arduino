/*
 Fade
 
 This example shows how to fade an LED on pin 9
 using the analogWrite() function.
 
 This example based on the Arduino Example Fade sketch
 but modified to use timing instead of the delay() function
 
 */
int brightness = 0;    // how bright the LED is
int fadeAmount = 1;    // how many points to fade the LED by
unsigned long currentTime;
unsigned long loopTime;

void setup()  { 
  // declare pin 9 to be an output:
  pinMode(9, OUTPUT);
  currentTime = millis();
  loopTime = currentTime; 
} 

void loop()  { 
  currentTime = millis();
  if(currentTime >= (loopTime + 20)){  
    // set the brightness of pin 9:
    analogWrite(9, brightness);    

    // change the brightness for next time through the loop:
    brightness = brightness + fadeAmount;

    // reverse the direction of the fading at the ends of the fade: 
    if (brightness == 0 || brightness == 255) {
      fadeAmount = -fadeAmount ; 
    }     
    loopTime = currentTime;  // Updates loopTime
  }
                           
}