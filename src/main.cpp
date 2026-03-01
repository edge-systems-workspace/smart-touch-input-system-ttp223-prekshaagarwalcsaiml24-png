const int touchPin = 2;
const int ledPin = 13;

bool ledState = LOW;
bool lastTouchState = LOW;

void setup() {
  pinMode(touchPin, INPUT);
  pinMode(ledPin, OUTPUT);
}

void loop() {
  bool currentTouch = digitalRead(touchPin);

  if (currentTouch == HIGH && lastTouchState == LOW) {
    ledState = !ledState;   // Toggle LED
    digitalWrite(ledPin, ledState);
    delay(200); // debounce
  }

  lastTouchState = currentTouch;
}
