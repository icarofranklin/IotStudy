#include <Arduino.h>

#define RX_PIN 44
#define TX_PIN 43

void setup(){
  Serial.begin(115200);
  Serial1.begin (115200, SERIAL_8N1, RX_PIN, TX_PIN);

  delay(1000);
  Serial.println("Iniciando envio TTL puro para o PC2...");
}

void loop(){
  for (int i = 1; i <= 5; i++){
    Serial1.print("Numero: ");
    Serial1.println(i);

    Serial.print("Enviando pro PC2: ");
    Serial.println(i);

    delay(1000);
  }

  Serial.println("--- Fim do ciclo. Reiniciando... ---");
  delay(1000);
}