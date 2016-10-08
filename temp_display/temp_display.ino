#include <LiquidCrystal.h>

LiquidCrystal lcd(13,12, 8,9,10,11);
const int sensorPin = A0;
int sensorValue = 0;
const int ARR_SIZE = 8;
float temps[ARR_SIZE];

void setup() {
  Serial.begin(9600);
  lcd.begin(16, 2);
  lcd.print("current temp is: ");
}

float avg (float* arr) {
  float tot = 0.0;
  for (int i = 0; i < ARR_SIZE; i++) {
    tot += arr[i];
  }
  return tot / (float)ARR_SIZE;
}

float mAv(float* tempsArr, float newTemp) {
  for (int i = 1; i < ARR_SIZE; i++) {
    float v = tempsArr[i];
    tempsArr[i - 1] = v;
  };
  tempsArr[ARR_SIZE - 1] = newTemp;
  return avg(tempsArr);
}

float calcTemp(int reading) {
  float inC = (float)reading / 10;
  return ((9 * inC) / 5) + 32.0;
}

void loop() {
  int sensorValue = analogRead(sensorPin);
  float temp = calcTemp(sensorValue);
  float avgTemp = mAv(temps, temp);
  lcd.setCursor(0, 1);
  lcd.print(avgTemp);
  delay(1000);
}
