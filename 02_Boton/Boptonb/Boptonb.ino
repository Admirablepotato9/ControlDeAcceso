const int inputPin = 7;
int lastButtonState = LOW;
int currentButtonState;
int outputState = 0;

void setup() {
  pinMode(inputPin, INPUT);
  Serial.begin(9600);
}

void loop() {
  currentButtonState = digitalRead(inputPin);
  
  if (currentButtonState == HIGH && lastButtonState == LOW) {
    if (outputState == 0) {
      outputState = 1;
    } else {
      outputState = 0;
    }
    Serial.println(outputState);
    delay(50);
  }
  
  lastButtonState = currentButtonState;
}