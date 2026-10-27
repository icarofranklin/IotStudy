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

  // Vamos configurar algumas coisas para ver se o chip obedece
  radio.setPALevel(RF24_PA_HIGH);    // Potência alta
  radio.setDataRate(RF24_1MBPS);     // Velocidade de 1 Mbps
  radio.setChannel(115);             // Canal 115 (fora da faixa do Wi-Fi)
  radio.openWritingPipe(0x1234567890LL);
  
  // Imprime um relatório bonito e legível de todos os registradores
  Serial.println("--- RELATORIO DO CHIP ---");
  radio.printPrettyDetails();
  Serial.println("-------------------------");
  Serial.println("\nSe voce consegue ler isso, o chip esta 100% funcional!");
}

void loop() {
  // Nada a fazer aqui
}