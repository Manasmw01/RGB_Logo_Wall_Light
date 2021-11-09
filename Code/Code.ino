#include <FastLED.h>
#define DATA_PIN 5
#define CLOCK_PIN 13
#define NUM_LEDS    10
CRGB leds[NUM_LEDS];

void setup() {
  FastLED.addLeds<NEOPIXEL, DATA_PIN>(leds, NUM_LEDS);  // GRB ordering is assumed
}

void loop() {
  fade(0, 0, 1);
  fade(0, 1, 0);
  fade(1, 0, 0);
  fade(1, 1, 1);
}

void fade(int a, int b, int c)
{
  for (int j = 0; j <= 150; j++)
  {
    for ( int i = 0; i < NUM_LEDS; ++i) {
      leds[i] = CRGB(a*j, b*j, c*j);
    }
    FastLED.show();
    delay(25);
  }
  for (int j = 150; j >= 0; j--)
  {
    for ( int i = 0; i < NUM_LEDS; ++i) {
      leds[i] = CRGB(a*j, b*j, c*j);
    }
    FastLED.show();
    delay(25);
  }
}
