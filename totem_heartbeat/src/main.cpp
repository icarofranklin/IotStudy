#include <Arduino.h>

// GPIO2 é o pino do LED embutido na maioria das placas ESP32
const int PINO_STATUS = 2; 

unsigned long tempoAnterior = 0; // Variável para armazenar o tempo do último piscar
const unsigned long INTERVALO = 1000; // Intervalo de tempo para piscar o LED (em milissegundos)

// Variável para armazenar o estado atual do pino
bool estadoPino = false; 

void setup() {
    // Inicia a comunicação serial para monitorar o status do LED
    Serial.begin(115200); 
    // Aguarda a conexão da porta serial para garantir que as mensagens sejam exibidas no monitor serial
    while (!Serial) { delay(10); } 
    // Tudo escrito roda apenas uma vez quando a placa é ligada ou resetada
    pinMode(PINO_STATUS, OUTPUT);

    // Garante que o LED comece desligado
    digitalWrite(PINO_STATUS, LOW); 
}
void loop(){
    // Tudo escrito aqui roda repetidamente enquanto a placa estiver ligada
    unsigned long tempoAtual = millis(); // Obtém o tempo atual em milissegundos

    if (tempoAtual - tempoAnterior>= INTERVALO){ //lógica para verificar se o intervalo de tempo passou
        
        tempoAnterior = tempoAtual; // Atualiza o tempo do último piscar
        
        estadoPino = !estadoPino; // Alterna o estado do pino
        
        digitalWrite(PINO_STATUS, estadoPino ? HIGH : LOW); // Escreve o novo estado no pino

        Serial.print("{\"status\": \"vivo\", \"uptime_ms\"): ");
        Serial.print(tempoAtual);
        Serial.print(", \"pino_ativo\": ");
        Serial.print(estadoPino ? "true" : "false");
        Serial.println("}");
    }
}