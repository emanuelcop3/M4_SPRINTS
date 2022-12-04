//Adicionando as bibliotecas
#include <WiFi.h>
#include <WebServer.h>
//Definição dasportas dos leds
#define LED_verde 12
#define LED_vermelho 15

//Senha da rede
const char* ssid = "SHARE-RESIDENTE";
const char* password = "Share@residente";

//Porta do servidor
WebServer server(80);

//Acende caso seja a vez do jogador x
void turnX(){
  digitalWrite(LED_verde, LOW);
  digitalWrite(LED_vermelho, HIGH);
}

//Acende caso seja a vez do jogador O
void turnO(){
  digitalWrite(LED_vermelho, LOW);
  digitalWrite(LED_verde, HIGH);
}

void setup() {
  Serial.begin(115200);
  pinMode(LED_vermelho, OUTPUT);
  pinMode(LED_verde, OUTPUT);
  // Connect to Wi-Fi network with SSID and password
  Serial.print("Connecting to ");
  Serial.println(ssid);
  WiFi.begin(ssid, password);
  while (WiFi.status() != WL_CONNECTED) {
    delay(300);
    Serial.print(".");
  }
  // Print local IP address and start web server
  Serial.println("");
  Serial.println("WiFi connected.");
  Serial.println("IP address: ");
  Serial.println(WiFi.localIP());

  //Rotas de  requisições que executam  função no arduíno

  server.on("/turnX", turnX);
  server.on("/turnO", turnO);
  server.begin();

}
void loop() {
server.handleClient();

}