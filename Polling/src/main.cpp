#include <Arduino.h>
#include <WiFi.h>

const char* ssid = "AGSinn_5G";
const char* password = "AGS@385hc";

void setup() {
  Serial.begin(115200);
  delay(1000);

  Serial.println("Connecting to WiFi...");
  WiFi.begin(ssid, password);
  while (WiFi.status() != WL_CONNECTED) {
    delay(500);
    Serial.print(".");
  }
    Serial.println("\n--- Conexão Estabelecida com Sucesso! ---");
    Serial.print("O IP da tua placa na rede é: ");
    Serial.println(WiFi.localIP());
}

void loop() {
  
}