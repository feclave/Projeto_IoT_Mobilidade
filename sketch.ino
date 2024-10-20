#include <Ultrasonic.h>
#include <WiFi.h>
#include <WiFiClient.h>
#include "ThingSpeak.h"

// Configurações Wi-Fi
const char* ssid = "Wokwi-GUEST";
const char* password = "";
const int channel = 6;

// Configurações ThingSpeak
const char* clientID = "seu_cliente_id";
const char* writeAPIKey = "OHOMO6XRRUEQEDH8";
const char* server = "api.thingspeak.com";
const int myChannelNumber = 2693519;

// Pinos do sensor ultrassônico
const int trigPin = 12;
const int echoPin = 14;

// LED para indicar alerta
const int ledPin = 2; // Adapte ao pino do seu LED
// Pino do buzzer
const int buzzerPin = 4; // Adapte ao pino do seu buzzer

// Instâncias
WiFiClient client;
Ultrasonic ultrasonic(trigPin, echoPin);

void setup() {
  Serial.begin(115200);
  pinMode(ledPin, OUTPUT);
  connectToWiFi();
}

void loop() {
  int distance = ultrasonic.read();
  
  if (distance >= 0) { // Verifica se a leitura foi válida
    Serial.print("Distância: ");
    Serial.print(distance);
    Serial.println(" cm");

    // Envia dados para o ThingSpeak
    if (ThingSpeak.writeField(myChannelNumber, 1, distance, writeAPIKey)) {
      Serial.println("Dados enviados com sucesso");
    } else {
      Serial.println("Erro ao enviar dados");
    }

    // Aciona o LED se a distância for menor que um determinado valor
    if (distance <= 50) { // Ajuste o valor de acordo com sua necessidade
      digitalWrite(ledPin, HIGH);
      tone(buzzerPin, 1000); // Aciona o buzzer com frequência de 1000 Hz
    } else {
      digitalWrite(ledPin, LOW);
      noTone(buzzerPin); // Desliga o buzzer
    }
  } else {
    Serial.println("Erro ao ler o sensor ultrassônico");
  }

  delay(1000); // Ajuste o intervalo de leitura conforme necessário
}

void connectToWiFi() {
  WiFi.begin(ssid, password, channel);
  while (WiFi.status() != WL_CONNECTED) {
    delay(500);
    Serial.print(".");
  }
  Serial.println("Conectado ao Wi-Fi");
  ThingSpeak.begin(client);
}