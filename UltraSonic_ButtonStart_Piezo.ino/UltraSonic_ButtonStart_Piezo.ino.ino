#include "pitches.h"

const int trigPin = 3;
const int echoPin = 4;
int led = 9;
const int buttonPin = 7;
int buttonState = 0;

float duration, distance;

void setup() {
  pinMode(trigPin, OUTPUT);
  pinMode(echoPin, INPUT);
  pinMode(led, OUTPUT);
  pinMode(buttonPin, INPUT);
  Serial.begin(9600);
}

void loop() {
  buttonState = digitalRead(buttonPin);
  digitalWrite(trigPin, LOW);
  delayMicroseconds(2);
  digitalWrite(trigPin, HIGH);
  delayMicroseconds(10);
  digitalWrite(trigPin, LOW);

  if (buttonState == HIGH) {
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
  }
  delay(100);
}
