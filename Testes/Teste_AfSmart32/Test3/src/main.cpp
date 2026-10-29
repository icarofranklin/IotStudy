#include <Arduino.h>
#include <Wire.h>

#define PCF_ADDR 0x27

void escreverPCF(byte valor) {
  Wire.beginTransmission(PCF_ADDR);
  Wire.write(valor);
  Wire.endTransmission();
}

void setup () {
  Serial.begin(115200);
  delay(500);
  Wire.begin(21, 22);
  Serial.println("Teste 2 - Mapeamento dos Reles");
}

void loop() {
  byte testes[] = {0xEF, 0xDF, 0xBF, 0x7F};  // um 0 deslizando em P4..P7

  for (int i = 0; i < 4; i++) {
    escreverPCF(testes[i]);          // liga o atual, desliga o anterior
    Serial.print("Rele ");
    Serial.print(i + 1);
    Serial.print(" ativo -> 0x");
    Serial.println(testes[i], HEX);
    delay(1000);                     // fica 1s com este relé ativo
  }

  // fim do ciclo: desliga o último e reinicia
  escreverPCF(0xFF);
  Serial.println("Todos desligados - reiniciando ciclo");
  delay(1000);
}