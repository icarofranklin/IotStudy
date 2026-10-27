#include <Arduino.h>
#include <SPI.h>
#include <RF24.h>

#define CE_PIN  4
#define CSN_PIN 5
RF24 radio(CE_PIN, CSN_PIN);

void setup() {
  Serial.begin(115200);
  delay(1000);
  Serial.println("Iniciando Diagnostico do NRF24L01...\n");

  SPI.begin(18, 19, 23, CSN_PIN);

  if (!radio.begin()) {
    Serial.println(">>> ERRO: O modulo nao respondeu.");
    while (1);
  }
  radio.setPALevel(RF24_PA_HIGH);  
  radio.setDataRate(RF24_1MBPS);    
  radio.setChannel(115);            
  radio.openWritingPipe(0x1234567890LL);
  
  Serial.println("--- RELATORIO DO CHIP ---");
  radio.printPrettyDetails();
  Serial.println("-------------------------");
  Serial.println("\nSe voce consegue ler isso, o chip esta 100% funcional!");
}

void loop() {

}