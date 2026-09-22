#include <Arduino.h>
#include <Wire.h>
/*
Nesta placa, o PCF8574 responde em 0x27.

Se A2=A1=A0=0 → endereço 0x20

Se A2=A1=A0=1 → endereço 0x27
*/

void setup() {  
    Serial.begin(115200);
    delay(500);
    Wire.begin(21, 22);
    Serial.println("Teste dos Reles da AF Smart ESP32 Rev2.1");
}
void loop() {
    for (byte endereco = 1; endereco < 127; endereco++) {
    Wire.beginTransmission(endereco);
    byte resposta = Wire.endTransmission();

        if (resposta == 0) {
            Serial.print("Encontrei dispositivo em 0x");
            Serial.println(endereco, HEX);
        }
    }
    Serial.println("Scan completo.");
    delay(5000);
}
