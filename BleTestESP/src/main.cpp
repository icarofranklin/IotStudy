#include <Arduino.h>
#include <BLEDevice.h>
#include <BLEUtils.h>
#include <BLEServer.h>

BLEAdvertising* pAdvertising = nullptr;

void setup() {
  Serial.begin(115200);
  Serial.println("Inicializando Testes BLE...");

  BLEDevice::init("Dispositivos de Teste Educativo");

  BLEServer* pServer = BLEDevice::createServer();

  pAdvertising = BLEDevice::getAdvertising();

  pAdvertising->setMinInterval(0x20);
  pAdvertising->setMaxInterval(0x20);

  BLEAdvertisementData oAdvertisementData;
  oAdvertisementData.setFlags(ESP_BLE_ADV_FLAG_GEN_DISC | ESP_BLE_ADV_FLAG_BREDR_NOT_SPT);

  oAdvertisementData.setName("TESTE_SATURACAO_CANAL_BLE_LAB");

  pAdvertising->setAdvertisementData(oAdvertisementData);

  Serial.println("[+] Parametros carregados. Iniciando saturacao dos canais 37, 38 e 39...");

  pAdvertising->start();
}

void loop() {  
  static unsigned long tempoAnterior = 0;
  if (millis() - tempoAnterior > 5000) {
    Serial.println("[!] Transmitindo pacotes BLE continuamente no espectro local...");
    tempoAnterior = millis();
  }
  
  delay(10); 
}