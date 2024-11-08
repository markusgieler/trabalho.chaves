#include <WiFi.h>
#include "setup_wifi.h"

const char* wifi_ssid = "tcc-markus";
const char* wifi_password = "jble1000";

//extern WiFi WiFi;

void setup_wifi() {
  delay(10);
  Serial.println();
  Serial.print("Conectando-se a ");
  Serial.println(wifi_ssid);

  WiFi.begin(wifi_ssid, wifi_password);

  while (WiFi.status() != WL_CONNECTED) {
    delay(500);
    Serial.print(".");
  }

  Serial.println("");
  Serial.println("WiFi conectado");
  Serial.print("Endereço IP: ");
  Serial.println(WiFi.localIP());
  Serial.print("Máscara de Sub-rede: ");
  Serial.println(WiFi.subnetMask());
  Serial.print("Gateway: ");
  Serial.println(WiFi.gatewayIP());
  Serial.print("DNS Primário: ");
  Serial.println(WiFi.dnsIP());
  Serial.print("MAC Address: ");
  Serial.println(WiFi.macAddress());
  Serial.print("SSID: ");
  Serial.println(WiFi.SSID());
  Serial.print("Intensidade do Sinal (RSSI): ");
  Serial.println(WiFi.RSSI());
  Serial.print("Canal WiFi: ");
  Serial.println(WiFi.channel());
  Serial.print("BSSID: ");
  Serial.println(WiFi.BSSIDstr());
  Serial.print("Hostname: ");
  Serial.println(WiFi.getHostname());
}