#include <Arduino.h>

#define RXD2 16
#define TXD2 17

void setup() {
 Serial.begin(115200);

 Serial2.begin(9600, SERIAL_8N1, RXD2, TXD2);

 Serial.println("Teste do HC-05 iniciando. Conecte pelo celular!");
}

void loop() {
  if (Serial2.available()) {
    char c = Serial2.read();
    Serial.print(c);
  }

  if (Serial.available()) {
    char c = Serial.read();
    Serial2.print(c);
  }
}