#include <Arduino.h>
#include <esp_task_wdt.h>

#define RX_PIN RX
#define TX_PIN TX

#define RS485_CONTROL_PIN 13

int contador = 0;
char buffer [4];

void setup(){
  Serial.begin(115200);
  Serial1.begin (9600, SERIAL_8N1, RX_PIN, TX_PIN);

  pinMode(RS485_CONTROL_PIN, OUTPUT);
  digitalWrite(RS485_CONTROL_PIN, LOW);

  delay(1000);
  Serial.println("=== Sistema RS485 Iniciado com Sucesso ===");
}

void loop(){

    itoa(contador, buffer, 10);

    digitalWrite(RS485_CONTROL_PIN, HIGH);
    delay(5);

    Serial1.print("Dado ESP32: ");
    Serial1.println(buffer);

    Serial1.flush();
    delay(5);
    digitalWrite(RS485_CONTROL_PIN, LOW);
    
    Serial.print ("Enviado para o barramento RS485: ");
    Serial.println(contador);

    delay(1000);

    contador++;
    if (contador > 5) {
      contador = 0;
      yield();
    }
    
    esp_task_wdt_reset();

  Serial.println("--- Fim do ciclo. Reiniciando... ---");
  delay(10);
}