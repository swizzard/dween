#include <Servo.h>

int srv0 = 9, 
    eyes = 12,
    i = 0;
Servo srv;


void setup() {
  srv.attach(srv0);
  srv.write(180);
  pinMode(eyes, OUTPUT);
  digitalWrite(eyes, HIGH);
  Serial.begin(9600);
}

void loop() {
  delay(10000);
  for (i = 179; i > 0; i -= 1) {
    srv.write(i);
    Serial.println(i);
    delay(1
    );
  }
  digitalWrite(eyes, LOW);
  delay(10000);
  digitalWrite(eyes, HIGH);
  srv.write(180);
}
