#include "pitches.h"

const int trigPin = 3;
const int echoPin = 4;
int led = 9;

float duration, distance;

void setup() {
  pinMode(trigPin, OUTPUT);
  pinMode(echoPin, INPUT);
  pinMode(led, OUTPUT);
  Serial.begin(9600);
}

void loop() {
  digitalWrite(trigPin, LOW);
  delayMicroseconds(2);
  digitalWrite(trigPin, HIGH);
  delayMicroseconds(10);
  digitalWrite(trigPin, LOW);

  duration = pulseIn(echoPin, HIGH);
  distance = (duration * .0343) / 2;
  Serial.print("Distance: ");
  Serial.println(distance);
  if (distance < 20) {
    digitalWrite(led, HIGH);
    tone(5, NOTE_C4, 250);
    delay(200);
  } else {
    digitalWrite(led, LOW);
    noTone(5);
    delay(200);
  }
  delay(100);
}
