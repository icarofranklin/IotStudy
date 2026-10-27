#include <Arduino.h>
#include <WiFi.h>
#include <WiFiUdp.h>
#include <NTPClient.h>


const char* ssid = "";
const char* password = "";

WiFiUDP ntpUDP;
const long utcOffsetInSeconds = -18000; 

NTPClient timeClient(ntpUDP, "pool.ntp.org", utcOffsetInSeconds);

void setup() {
  Serial.begin(115200);
  delay(1000);
  Serial.println("Iniciando teste de hora NTP...");

  Serial.printf("Conectando a %s\n", ssid);
  WiFi.begin(ssid, password);

  while (WiFi.status() != WL_CONNECTED) {
    delay(500);
    Serial.print(".");
  }
  Serial.println("\nWi-Fi conectado!");
  Serial.print("Endereço IP: ");
  Serial.println(WiFi.localIP());

  timeClient.begin();
}

void loop() {
  timeClient.update();
  Serial.print("Hora atual: ");
  Serial.println(timeClient.getFormattedTime());
  delay(1000);
}