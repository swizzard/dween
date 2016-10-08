#include <Adafruit_NeoPixel.h>

#define PIN 6
#define STRIPSIZE 32

Adafruit_NeoPixel strip = Adafruit_NeoPixel(STRIPSIZE, PIN, NEO_GRB + NEO_KHZ800);

const uint8_t rowLength = 8;

const uint32_t blue = strip.Color(0, 0, 255);
const uint32_t red = strip.Color(255, 0, 0);
const uint32_t green = strip.Color(0, 255, 0);
const uint32_t pink = strip.Color(250, 200, 212);

uint8_t counter = 0;

void plotPixel(uint8_t x, uint8_t y, uint32_t color) {
  strip.setPixelColor(24 - (8 * y) + x, color);
}

void plotFigure1(uint8_t x) {
  plotPixel(x, 3, pink);
  plotPixel(x, 2, blue);
  plotPixel(x, 1, blue);
  plotPixel(x, 0, red);
}

void plotFigure2(uint8_t x) {
  plotPixel(x, 3, pink);
  plotPixel(x, 2, blue);
  plotPixel(x, 1, blue);
  plotPixel(x + 1, 1, blue);
  plotPixel(x, 0, red);
  plotPixel(x + 1, 0, red);
}

void plotLips1() {
  for (int i = 0; i < rowLength; i++) {
    plotPixel(i, 1, red);
    plotPixel(i, 2, red);
  }
}

void plotLips2() {
  plotPixel(0, 1, red);
  plotPixel(0, 2, red);
  plotPixel(1, 1, red);
  plotPixel(1, 2, red);
  plotPixel(2, 1, red);
  plotPixel(2, 2, red);
  plotPixel(3, 0, red);
  plotPixel(3, 3, red);
  plotPixel(4, 0, red);
  plotPixel(4, 3, red);
  plotPixel(5, 1, red);
  plotPixel(5, 2, red);
  plotPixel(6, 1, red);
  plotPixel(6, 2, red);
  plotPixel(7, 1, red);
  plotPixel(7, 2, red);
}

void setup() {
  Serial.begin(9600);
  strip.begin();
  strip.setBrightness(4);
  strip.show();
}

void loop() {
  strip.clear();
  if (counter % 2 == 0) {
    plotFigure1(counter);
//    plotLips1;
  } else {
//    plotLips2;
    plotFigure2(counter);
  }
  strip.show();
  counter = (counter + 1) % 8;
  delay(250);
}

