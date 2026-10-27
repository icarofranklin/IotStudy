#include <Arduino.h>
#include <Wire.h>
#include <Adafruit_PN532.h>

// Pinos I2C padrão da ESP32
#define SDA_PIN 21
#define SCL_PIN 22

// Cria o objeto passando os pinos SDA e SCL
Adafruit_PN532 nfc(SDA_PIN, SCL_PIN);

void setup() {
  Serial.begin(115200);
  delay(1000);
  Serial.println("Teste do PN532 (HW-147) no modo I2C...");

  nfc.begin();

  uint32_t versiondata = nfc.getFirmwareVersion();
  if (!versiondata) {
    Serial.println("Erro: Nao foi possivel encontrar o modulo PN532.");
    Serial.println("Verifique a fiacao (SDA/SCL) e se o modulo esta no modo I2C.");
    while (1); // Para o programa aqui
  }

  // Se chegou aqui, o modulo foi encontrado!
  Serial.print("Encontrado chip PN5");
  Serial.println((versiondata>>24) & 0xFF, HEX);
  Serial.print("Firmware ver. ");
  Serial.print((versiondata>>16) & 0xFF, DEC);
  Serial.print('.');
  Serial.println((versiondata>>8) & 0xFF, DEC);

  // Configura o modulo para ler cartoes
  nfc.SAMConfig();
  Serial.println("Aguardando um cartao NFC/RFID...");
}

void loop() {
  uint8_t success;
  uint8_t uid[] = { 0, 0, 0, 0, 0, 0, 0 };  // Buffer para o UID
  uint8_t uidLength;

  // Tenta ler um cartao
  success = nfc.readPassiveTargetID(PN532_MIFARE_ISO14443A, uid, &uidLength);

  if (success) {
    Serial.println("Cartao encontrado!");
    Serial.print("Tamanho do UID: ");
    Serial.print(uidLength, DEC);
    Serial.println(" bytes");
    Serial.print("UID: ");
    for (uint8_t i = 0; i < uidLength; i++) {
      Serial.print(" 0x"); Serial.print(uid[i], HEX);
    }
    Serial.println("");
    delay(1000); // Espera 1 segundo antes da proxima leitura
  }
} //Modulo queimado...