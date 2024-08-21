const int inputPin = 7;
const int ledF = 8;
const int ledV = 4;
const int buzz = 3;
bool estado = 0; 

int lastButtonState = LOW;
int currentButtonState;

void encenderVerde() {
  digitalWrite(ledV, HIGH); // Enciende el LED verde (establece el pin 4 en alto)
  delay(5000); // Espera 5 segundos
  digitalWrite(ledV, LOW); // Apaga el LED verde (establece el pin 4 en bajo)
}

void encenderRojo() {
  digitalWrite(ledF, HIGH); // Enciende el LED verde (establece el pin 4 en alto)
  delay(5000); // Espera 5 segundos
  digitalWrite(ledF, LOW); // Apaga el LED verde (establece el pin 4 en bajo)
}

void setup() {
  
  pinMode(inputPin, INPUT);
  pinMode(ledF, OUTPUT);
  pinMode(ledV, OUTPUT);
  pinMode(buzz, OUTPUT);

  Serial.begin(9600);

}

void loop() {

  currentButtonState = digitalRead(inputPin);
  
  if (estado == 0) {
  
  if (currentButtonState == HIGH && lastButtonState == LOW) {
    estado = 1;
    Serial.println("User:example");
    Serial.flush();
    digitalWrite(3, HIGH);
    delay(200);                     // Mantiene el buzzer encendido por 1 segundo
    digitalWrite(3, LOW);
  }
    
  }
  else {
         if (Serial.available() > 0) {
          String receivedString = Serial.readStringUntil('\n'); // Lee una línea hasta '\n'
          Serial.print("Received: ");
          Serial.println(receivedString);
          digitalWrite(3, HIGH);
          delay(200);                     // Mantiene el buzzer encendido por 1 segundo
          digitalWrite(3, LOW);
          delay(100);     
          digitalWrite(3, HIGH);
          delay(200);                     // Mantiene el buzzer encendido por 1 segundo
          digitalWrite(3, LOW);  // Enciende el buzzer
          if (receivedString == "userokay"){
            encenderVerde();
          }
          else{
            encenderRojo();
          }
          estado = 0;

          }
     }
     
  lastButtonState = currentButtonState;
    }