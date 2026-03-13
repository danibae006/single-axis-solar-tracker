// ============================================
// Project  : Single-Axis Solar Tracker
// Author   : Daniel
// GitHub   : https://github.com/danibae006
// Repo     : https://github.com/danibae006/single-axis-solar-tracker
//
// For wiring & connections, visit the repo
// above and read the README file.
// It contains full wiring diagrams,
// component list, and setup instructions.
// ============================================

#include <Servo.h>

const int LDR_LEFT_PIN  = 2;   // digital output from left LDR module
const int LDR_RIGHT_PIN = 3;   // digital output from right LDR module
const int SERVO_PIN     = 9;   // SG90 signal

Servo trackerServo;
int angle = 90;                // start in middle
const int stepAngle = 2;       // how much to move each correction
const int minAngle  = 0;
const int maxAngle  = 180;

void setup() {
  pinMode(LDR_LEFT_PIN,  INPUT);
  pinMode(LDR_RIGHT_PIN, INPUT);
  trackerServo.attach(SERVO_PIN);
  trackerServo.write(angle);
}

void loop() {
  int leftState  = digitalRead(LDR_LEFT_PIN);   // HIGH = light, LOW = dark (depends on module)
  int rightState = digitalRead(LDR_RIGHT_PIN);

  // Adjust these conditions if your modules give opposite logic
  if (leftState == HIGH && rightState == LOW && angle < maxAngle) {
    angle += stepAngle;        // move toward left
  } else if (leftState == LOW && rightState == HIGH && angle > minAngle) {
    angle -= stepAngle;        // move toward right
  }
  // if both same, do nothing (tracker aligned)

  trackerServo.write(angle);
  delay(50);                   // tracking speed
}
