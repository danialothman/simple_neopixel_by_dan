#include <Adafruit_NeoPixel.h>

#define PIN       6     // LED strip data pin is on this PIN
#define NUMPIXELS 8    // number of LED on strip
#define BRIGHTNESS 50 // 0 - 255 dim to bright

Adafruit_NeoPixel pixels(NUMPIXELS, PIN, NEO_GRB + NEO_KHZ800); // essential for lib

#define DELAYVAL 250


// debounce button setup
const int buttonPin = 2;
int ledState = LOW;
boolean buttonState = HIGH;
int pressed = 0;

void setup() {
//  Serial.begin(9600);

  //configure pin 2 as an input and enable the internal pull-up resistor
  pinMode(buttonPin, INPUT_PULLUP);
  
  pixels.setBrightness(BRIGHTNESS);
  pixels.begin();
  pixels.clear();


  
}

void loop() {

//  Serial.println(buttonState);
//  Serial.println(pressed);

  if (debounceButton(buttonState) == HIGH && buttonState == LOW)
  {
    pressed++;
    buttonState = HIGH;
  }
  else if (debounceButton(buttonState) == LOW && buttonState == HIGH)
  {
    buttonState = LOW;
  }

  if (pressed == 0)
  {
    allOff();
  }
  if (pressed == 1) {
    allRed();
  }
  if (pressed == 2) {
    allGreen();
  }
  if (pressed == 3) {
    allBlue();
  }
  if (pressed == 4) {
    allWhite();
  }
  if (pressed > 4) {
    pressed = 0;
  }
  
}

boolean debounceButton(boolean state)
{
  boolean stateNow = digitalRead(buttonPin);
  if (state != stateNow)
  {
    delay(10);
    stateNow = digitalRead(buttonPin);
  }
  return stateNow;
}

// off
void allOff() {
  pixels.clear();
  pixels.show();
}

void allRed() {
  Serial.println("RED");
  pixels.clear();
  for (int i = 0; i < NUMPIXELS; i++) { // For each pixel...
    pixels.setPixelColor(i, pixels.Color(255, 0, 0));
  }
  pixels.show();
  //  delay(1000);
}

void allGreen() {
  Serial.println("GREEN");
  pixels.clear();
  for (int i = 0; i < NUMPIXELS; i++) { // For each pixel...
    pixels.setPixelColor(i, pixels.Color(0, 255, 0));
  }
  pixels.show();
  //  delay(1000);
}

void allBlue() {
  Serial.println("BLUE");
  pixels.clear();
  for (int i = 0; i < NUMPIXELS; i++) { // For each pixel...
    pixels.setPixelColor(i, pixels.Color(0, 0, 255));
  }
  pixels.show();
  //  delay(1000);
}

void allWhite() {
  Serial.println("WHITE");
  pixels.clear();
  for (int i = 0; i < NUMPIXELS; i++) {
    pixels.setPixelColor(i, pixels.Color(255, 255, 255));
  }
  pixels.show();
}

//knightRider style
void kitRun() {
  for (int i = 0; i < NUMPIXELS; i++) {
    Serial.println(i);
    pixels.setPixelColor(i, pixels.Color(0, 150, 150));
    if (i != 0) {
      pixels.setPixelColor(i - 1, pixels.Color(0, 0, 0));
    }
    pixels.show();
    delay(DELAYVAL);
    if (i == NUMPIXELS - 1) {
      Serial.println("SWITCH");
      pixels.clear();
      for (int j = NUMPIXELS - 2; j > 0; j--) {
        Serial.println(j);
        pixels.setPixelColor(j, pixels.Color(0, 150, 150));
        if (j != NUMPIXELS) {
          pixels.setPixelColor(j + 1, pixels.Color(0, 0, 0));
        }
        pixels.show();
        delay(DELAYVAL);
      }
    }
  }
}
