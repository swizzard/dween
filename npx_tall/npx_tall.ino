#include <Adafruit_NeoPixel.h>

#define PIN 6
#define STRIPSIZE 32

Adafruit_NeoPixel strip = Adafruit_NeoPixel(STRIPSIZE, PIN, NEO_GRB + NEO_KHZ800);

const uint32_t red = strip.Color(255, 0, 0);
boolean f1 = true;

class PxMapper {
  private:
    uint8_t intercept;
    int8_t xMod;
    int8_t yMod;
  public:
    uint8_t xMax;
    uint8_t yMax;
    PxMapper(uint8_t intercept_, int8_t xMod_, int8_t yMod_, uint8_t xMax_, uint8_t yMax_) {
      intercept = intercept_;
      xMod = xMod_;
      yMod = yMod_;
      xMax = xMax_;
      yMax = yMax_;
    }
    uint8_t plot(uint8_t x, uint8_t y) {
      return intercept + (yMod * y) + (xMod * x);
    }
};

PxMapper H4x8 = PxMapper(24, 1, -8, 7, 3);

void lips1() {
  strip.clear();
  uint8_t x;
  for (x = 0; x <= H4x8.xMax; x++) {
    strip.setPixelColor(H4x8.plot(x, 1), red);
    strip.setPixelColor(H4x8.plot(x, 2), red);
  };
  strip.show();
}

void lips2() {
  strip.clear();
  strip.setPixelColor(H4x8.plot(0, 1), red);
  strip.setPixelColor(H4x8.plot(0, 2), red);
  strip.setPixelColor(H4x8.plot(1, 1), red);
  strip.setPixelColor(H4x8.plot(1, 2), red);
  strip.setPixelColor(H4x8.plot(6, 1), red);
  strip.setPixelColor(H4x8.plot(6, 2), red);
  strip.setPixelColor(H4x8.plot(7, 1), red);
  strip.setPixelColor(H4x8.plot(7, 2), red);
  for (uint8_t x = 2; x <= 5; x++) {
    strip.setPixelColor(H4x8.plot(x, 0), red);
    strip.setPixelColor(H4x8.plot(x, 3), red);
  }
  strip.show();
}

void setup() {
  strip.begin();
  strip.setBrightness(4);
  strip.show();
}

void loop() {
  if (f1) {
    lips1();
    f1 = !f1;
  } else {
    lips2();
    f1 = !f1;
  }
  delay(250);
}
