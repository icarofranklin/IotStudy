#include <Arduino.h>
#include <Wire.h>

void setup() {
 Wire.begin(21, 22);
 Serial.begin(115200);
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
}
