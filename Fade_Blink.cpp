int ledPin = 12;                 // LED connected to digital pin 13
int fadePin = 9;
unsigned long nextBlink, nextFade;
int fadeBrightness = 0;
char ledState = LOW, fadeDir = 10;

void setup()
{
    pinMode(ledPin, OUTPUT);      // sets the digital pin as output
    pinMode(fadePin, OUTPUT);
    ledState = LOW;
    nextBlink = millis();
    nextFade = millis();
}

/*
 * This checks whether it's time to change the state of the LED, and
 * does the write if so.  But it doesn't execute delay(), so in either
 * case it takes essentially no time to execute.
 */
void blink(void)
{
    unsigned long now;
    now = millis();
    if (now >= nextBlink) {
        nextBlink = now + 1000;    // Next change in one second
        if (ledState == LOW) {
            digitalWrite(ledPin, HIGH);
            ledState = HIGH;
        } 
        else {
            digitalWrite(ledPin, LOW);
            ledState = LOW;
        }
    }
}

void fade(void)
{
    unsigned long now;
    now = millis();
    if (now >= nextFade) {
        nextFade = now + 200;    // Next change in one second
        if (fadeDir > 0) {
            if (fadeBrightness > (255 - fadeDir)) {
                fadeDir = - fadeDir;
            }
        } 
        else {
            if (fadeBrightness < (-fadeDir)) {
                fadeDir = - fadeDir;
            }
        }
        fadeBrightness += fadeDir;
        analogWrite(fadePin, fadeBrightness);
    }
}

void loop()
{
    blink();
    fade();
}