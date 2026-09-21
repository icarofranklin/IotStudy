#include <Arduino.h>
#include <Wire.h>

void setup() {
 Wire.begin(21, 22);
 Serial.begin(115200);
 Serial.println("Teste dos Reles da AF Smart ESP32 Rev2.1");
}
void loop() {


}
