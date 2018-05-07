#include <Arduino.h>

#define ENDSTOP_PIN 2  //what pin are we using?

void setup() {
  pinMode(ENDSTOP_PIN, OUTPUT);
  Serial.begin(9600);
  Serial.println("Starting opto endstop exerciser.");
  }

void loop() {
  if (digitalRead(ENDSTOP_PIN)==true)  {
      Serial.println("open.");
    } else {
      Serial.println("blocked.");
      }
  delay(500);
}
