#include <Arduino.h>

#define ENDSTOP_PIN 2  //what pin are we using?

unsigned long startmillis;
unsigned long time_rot;
unsigned long periodo = 1000;
unsigned long per_i = 0;
float velocidade_rotacao;

void setup() {
  pinMode(ENDSTOP_PIN, INPUT);
  Serial.begin(9600);
  startmillis = millis();
  Serial.println("Starting opto endstop exerciser.");
  }

void loop() {
  time_rot = millis();
  if (periodo<(time_rot-per_i)) {
    if (digitalRead(ENDSTOP_PIN)==true)  {
      if (0<abs(time_rot-startmillis)) {
        startmillis = abs(time_rot-startmillis);
      }
      Serial.println("open.");
      velocidade_rotacao = (3.14159 / startmillis) * 1000;
      Serial.println("Velocidade:\t");
      Serial.println(velocidade_rotacao);
      Serial.println(" rad/s");
    } else {
        Serial.println(time_rot);
        Serial.println(startmillis);
      }
    per_i = time_rot - per_i;
  }
}
