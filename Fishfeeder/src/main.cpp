#include <Arduino.h>
#include <Servo.h>

const int SERVO_PIN   = 9;
const int BUTTON_PIN  = 2;
const unsigned long AUTO_INTERVAL  = 15000;  // ms between automatic activations
const unsigned long DEBOUNCE_DELAY = 50;     // ms

Servo servo;

void activateServo() {
  servo.write(0);
  delay(1000);
  servo.write(180);
  delay(1000);
}

void setup() {
  servo.attach(SERVO_PIN);
  pinMode(BUTTON_PIN, INPUT_PULLUP);
}

void loop() {
  static unsigned long lastAutoTime   = 0;
  static unsigned long lastDebounceTime = 0;
  static bool lastButtonState         = HIGH;
  static bool buttonState             = HIGH;

  // Automatic activation
  if (millis() - lastAutoTime >= AUTO_INTERVAL) {
    lastAutoTime = millis();
    activateServo();
  }

  // Button debounce
  bool reading = digitalRead(BUTTON_PIN);
  if (reading != lastButtonState) {
    lastDebounceTime = millis();
  }
  if (millis() - lastDebounceTime >= DEBOUNCE_DELAY) {
    if (reading != buttonState) {
      buttonState = reading;
      if (buttonState == LOW) {  // button pressed
        activateServo();
      }
    }
  }
  lastButtonState = reading;
}
