#include <Arduino.h>
#include <ESP8266WiFi.h>
#include <WiFiUdp.h>
#include <WakeOnLan.h>
#include <ESP8266WebServer.h>

WiFiUDP UDP;
WakeOnLan WOL(UDP);

// ESPECIFICA A PORTA EM QUE O SERVIDOR FUNCIONARÁ.
ESP8266WebServer server(80);

// INFORME AS CONFIGURAÇÕES DO WIFI
const char *ssid = "xxxxx";
const char *password = "xxxxxxx";

// INFORME O MACADDRESS
const char *MACAddress = "xxxxxxxxxxx";

void wakeMyPC()
{
  // ACENDE O LED NATIVO DO NODEMCU
  digitalWrite(LED_BUILTIN, LOW);
  Serial.print("Enviando pacote Wake on Lan!");
  WOL.sendMagicPacket(MACAddress);
  delay(1000);
  // APAGA O LED NATIVO DO NODEMCU
  digitalWrite(LED_BUILTIN, HIGH);
  server.send(200, "text/plain", "Pacote mágico enviado. Wake on Lan!");
  Serial.print("Pacote mágico enviado. Wake on Lan!");
}

void setup()
{
  pinMode(LED_BUILTIN, OUTPUT);
  digitalWrite(LED_BUILTIN, HIGH);
  WOL.setRepeat(3, 100);
  Serial.begin(9600);

  // CONECTA NO WIFI
  Serial.print("Conectando em ");
  Serial.println(ssid);
  WiFi.mode(WIFI_STA);
  WiFi.begin(ssid, password);
  while (WiFi.status() != WL_CONNECTED)
  {
    delay(500);
    Serial.print(".");
  }
  Serial.println("");
  Serial.println("WiFi conectado.");
  Serial.println("Endereço IP: ");
  Serial.println(WiFi.localIP());

  // Inicia o servidor
  server.begin();
  Serial.println("Servidor iniciado.");

  WOL.calculateBroadcastAddress(WiFi.localIP(), WiFi.subnetMask());

  // Rotas
  server.on("/wakeMyPC", wakeMyPC);
}

void loop()
{
  server.handleClient();
}
