int ledPin = 13;
bool blinking = false;

void setup() {
  Serial.begin(9600);
  pinMode(ledPin, OUTPUT);
}

void loop() {
  if (Serial.available() > 0) {
    char data = Serial.read();
    if (data == 'e') {
      blinking = true;
      Serial.println("LED Blinking ON");
    } else if (data == 'a') {
      blinking = false;
      digitalWrite(ledPin, LOW);
      Serial.println("LED OFF");
    }
  }

  if (blinking) {
    digitalWrite(ledPin, HIGH);
    delay(500);
    digitalWrite(ledPin, LOW);
    delay(500);
  }
}

