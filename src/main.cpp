#include <Arduino.h>

#define ENDSTOP_PIN 2  //what pin are we using?

unsigned long startmillis;
unsigned long time = 0;
float velocidade_rotacao;

void setup() {
  pinMode(ENDSTOP_PIN, INPUT);
  Serial.begin(9600);
  startmillis = millis();
  Serial.println("Starting opto endstop exerciser.");
  }

void loop() {
  if (0<abs(time-startmillis)) {
    time = abs(time-startmillis);
  }
  if (digitalRead(ENDSTOP_PIN)==true)  {
      Serial.println("open.");
      velocidade_rotacao = 3.14159 / time * 1000;
      Serial.println("Velocidade:\t");
      Serial.println(velocidade_rotacao);
      Serial.println(" rad/s");
    } else {
      Serial.println("blocked.");
      }
  delay(500);
}
