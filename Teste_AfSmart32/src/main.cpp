#include <Arduino.h>
#include "Wire.h"

/*
Nesta placa, o PCF8574 responde em 0x27.

Se A2=A1=A0=0 → endereço 0x20

Se A2=A1=A0=1 → endereço 0x27
*/

void setup() {  
    Serial.begin(115200);
    delay(500);
    Wire.begin(21, 22);
    Serial.println("Teste 1 - polaridade dos reles");
}
void loop() {
    Wire.beginTransmission(0x27);
    Wire.write(0x00);
    Wire.endTransmission();
    Serial.println("Ligado 0x00");
    delay(2000);

    Wire.beginTransmission(0x27);
    Wire.write(0xFF);
    Wire.endTransmission();
    Serial.println("Desligado 0xFF");
    delay(2000);

    Serial.println("---Fim do Ciclo---");
    delay(10000);
}
