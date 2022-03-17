#include <Adafruit_NeoPixel.h>

#define PIN       6     // LED strip data pin is on this PIN
#define NUMPIXELS 30    // number of LED on strip
#define BRIGHTNESS 155  // 0 - 255 dim to bright

Adafruit_NeoPixel pixels(NUMPIXELS, PIN, NEO_GRB + NEO_KHZ800); // essential for lib

#define DELAYVAL 250

void setup() {
  Serial.begin(9600);
  pixels.setBrightness(BRIGHTNESS);
  pixels.begin();
}

void loop() {
  pixels.clear();
  //test style - comment or uncomment to try
  //  kitRun();
  //  staticWhite();
  offLED();
}

// off
void offLED() {
  pixels.show();
}


//staticWhite style
void staticWhite() {

  for (int i = 0; i < NUMPIXELS; i++) {
    pixels.setPixelColor(i, pixels.Color(255, 255, 255));
  }
  pixels.show();
  delay(DELAYVAL);

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
