#include <Arduino.h>
#include <Wire.h>

#define PCF_ADDR 0x27

/*
Com isso, comprovei que:

i=0 -> 0xEF (P4=LOW) -> RL1 liga.

i=1 -> 0xDF (P5=LOW) -> RL2 liga.

i=2 -> 0xBF (P6=LOW) -> RL3 liga.

i=3 -> 0x7F (P7=LOW) -> RL4 liga.
*/

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
  byte testes[] = {0xEF, 0xCF, 0x8F, 0x0F};

  for (int i = 0; i < 4; i++) {
    escreverPCF(testes[i]);
    Serial.print("Testando byte: 0x");
    Serial.println(testes[i], HEX);
    delay(5000);

    escreverPCF(0xFF);
    Serial.println("Todos HIGH");
    delay(1000);
  }

  Serial.println("--- fim do ciclo ---");
}