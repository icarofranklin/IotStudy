#include <Arduino.h>

#define RX_PIN 44
#define TX_PIN 43
#define RS485_EN_PIN 1

void setup(){
  Serial.begin(115200);
  Serial1.begin (115200, SERIAL_8N1, RX_PIN, TX_PIN);

  pinMode(RS485_EN_PIN, OUTPUT);
  digitalWrite(RS485_EN_PIN, HIGH);

  delay(1000);
  Serial.println("Iniciando transmissao via RS485...");
}

void loop(){
  for (int i = 1; i <= 5; i++){
    Serial1.print("Numero: ");
    Serial1.println(i);

    Serial.print("Enviando pro RS485: ");
    Serial.println(i);

    delay(1000);
  }

  Serial.println("--- Fim do ciclo. Reiniciando... ---");
  delay(1000);
}