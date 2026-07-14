#include <Arduino.h>
#include <esp_task_wdt.h>

#define RX_PIN 1
#define TX_PIN 2

#define RS485_CONTROL_PIN 13

int i = 0;
char buffer [4];

void setup(){
  Serial.begin(115200);
  Serial1.begin (9600, SERIAL_8N1, RX_PIN, TX_PIN);

  pinMode(RS485_CONTROL_PIN, OUTPUT);
  digitalWrite(RS485_CONTROL_PIN, LOW);

  delay(1000);
  Serial.println("Iniciando envio TTL puro para o PC2 (vers 4.0 ITOA)...");
}

void loop(){

    itoa(i, buffer, 10);

    digitalWrite(RS485_CONTROL_PIN, HIGH);
    delay(5);

    Serial1.println(buffer);
    delay(5);

    Serial1.flush();
    delay(5);
    digitalWrite(RS485_CONTROL_PIN, LOW);
    
    Serial.print("Enviando pro PC2: ");
    Serial.println(i);

    delay(1000);

    i++;
    if (i > 5) {
      i = 0;
      yield();
    }
    esp_task_wdt_reset();
  //Serial.println("--- Fim do ciclo. Reiniciando... ---");
  delay(10);
}