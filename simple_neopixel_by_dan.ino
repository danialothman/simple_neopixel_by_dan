#include <Adafruit_NeoPixel.h>

#define PIN       6
#define NUMPIXELS 30

Adafruit_NeoPixel pixels(NUMPIXELS, PIN, NEO_GRB + NEO_KHZ800);

#define DELAYVAL 250

void setup() {
  Serial.begin(9600);
  pixels.setBrightness(50);
  pixels.begin();

}

void loop() {
  pixels.clear();
  
  for (int i = 0; i < NUMPIXELS; i++) {
    Serial.println(i);
    pixels.setPixelColor(i, pixels.Color(0, 255, 0));
    if (i != 0) {
      pixels.setPixelColor(i-1, pixels.Color(0, 0, 0));
    }
    pixels.show();
    delay(DELAYVAL);
    if (i == NUMPIXELS-1) {
      Serial.println("SWITCH");
      pixels.clear();
      for (int j = NUMPIXELS-2; j > 0; j--) {
        Serial.println(j);
        pixels.setPixelColor(j, pixels.Color(0, 255, 0));
        if (j != NUMPIXELS) {
          pixels.setPixelColor(j+1, pixels.Color(0, 0, 0));
        }
        pixels.show();
        delay(DELAYVAL);
      }     
    }
  }

}
