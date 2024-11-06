#include <WiFi.h>
#include <WebServer.h>
#include "setup_webserver.h"
#include "setup_wifi.h"

WebServer server(80);

void handleRoot() {
  String message = "<!DOCTYPE html><html><head>";
  message += "<style>body { background-color: black; color: white; font-family: monospace, Arial, sans-serif; }</style>";
  message += "<h1>ESP32-C3 C</h1>";
  message += "<p><b>MAC ADDRESS_</b> " + WiFi.macAddress() + "</p>";
  message += "<p><b>____NETMASK_</b> " + WiFi.subnetMask().toString() + "</p>";
  message += "<p><b>_________IP_</b> " + WiFi.localIP().toString() + "</p>";
  message += "<p><b>_____GATWAY_</b> " + WiFi.gatewayIP().toString() + "</p>";
  message += "<p><b>________DNS_</b> " + WiFi.dnsIP().toString() + "</p>";
  message += "<p><b>_______SSID_</b> " + WiFi.SSID() + "</p>";
  message += "<p><b>_______RSSI_</b> " + String(WiFi.RSSI()) + " dBm</p>";
  message += "<p><b>_____CHANEL_</b> " + String(WiFi.channel()) + "</p>";
  message += "<p><b>______BSSID_</b> " + WiFi.BSSIDstr() + "</p>";
  message += "<p><b>___HOSTNAME_</b> " + String(WiFi.getHostname()) + "</p>";
  message += "</body></html>";
 server.send(200, "text/html", message);  
}

void handleNotFound() {
  server.send(404, "text/html", "<h1>404: Página não encontrada</h1>");
}

void setup_webserver() {
  setup_wifi();  // Chama a função setup_wifi para configurar a conexão WiFi

  server.on("/", handleRoot);
  server.onNotFound(handleNotFound);
  server.begin();
  Serial.println("Servidor Web iniciado");
}