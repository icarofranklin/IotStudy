#include <Arduino.h>
#include <WiFi.h>
#include <WebServer.h>

const char* ssid = "AGSinn_2.4G";
const char* password = "AGS@385hc";
#define PINO_STATUS 2
WebServer server(80);

void setup() {
  Serial.begin(115200);
    delay(3000);
  pinMode(PINO_STATUS, OUTPUT);
  digitalWrite(PINO_STATUS, LOW);
  WiFi.begin(ssid, password);
  while (WiFi.status() != WL_CONNECTED) {
    delay(500);
  }
  Serial.println(WiFi.localIP());

  for(int i = 0; i < 5; i++) {
    digitalWrite(PINO_STATUS, HIGH);
    delay(150);
    digitalWrite(PINO_STATUS, LOW);
    delay(150);
  }

  server.on("/ligar", []() {
    digitalWrite(PINO_STATUS, HIGH);
    server.send(200, "text/plain", "Hardware LIGADO via rede local!");
  });

  server.on("/desligar", []() {
    digitalWrite(PINO_STATUS, LOW);
    server.send(200, "text/plain", "Hardware DESLIGADO via rede local!");
  });

  server.begin();
}


void loop() {
  server.handleClient();
}