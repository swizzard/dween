#include <Servo.h>

int green = 11, 
    red = 12, 
    srvo = 9, 
    pos = 0, 
    oldPos = 0;
Servo srv;

void setup() {
  pinMode(green, OUTPUT);
  pinMode(red, OUTPUT);
  srv.attach(srvo);
  
}

void loop() {
  if (oldPos > pos) {
    if (pos > 0) {
      pos -= 15;
    } else {
      oldPos = pos;
      pos += 15;
    }
  } else {
    if (pos < 180) {
      pos += 15;
    } else {
      oldPos = pos;
      pos -= 15;
    }
  }
  srv.write(pos);
  digitalWrite(red, HIGH);
  delay(200);
  digitalWrite(red, LOW);
  digitalWrite(green, HIGH);
  delay(100);
  digitalWrite(green, LOW);
}
