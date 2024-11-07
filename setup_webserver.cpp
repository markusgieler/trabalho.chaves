#include <WiFi.h>
#include <WebServer.h>
#include "setup_webserver.h"
#include "setup_wifi.h"

WebServer server(80);

void handleRoot() {
  String message = "<!DOCTYPE html><html>";
  message += "<head>";
  message += " <title>ESP32 C3 A</title>";
  message += "</head>";
  message += "<style>";
  message += " body { background-color: black; color: white; font-family: monospace, Arial, sans-serif; }";
  message += " h1.board { color: red; }";
  message += " span.attribute { color: yellow; }";
  message += "</style>";
  message += "<h1 class='board'>ESP32-C3 A</h1>";
  message += "<p><b><span class=attribute>MAC ADDRESS_</span></b> " + WiFi.macAddress() + "</p>";
  message += "<p><b><span class=attribute>____NETMASK_</span></b> " + WiFi.subnetMask().toString() + "</p>";
  message += "<p><b><span class=attribute>_________IP_</span></b> " + WiFi.localIP().toString() + "</p>";
  message += "<p><b><span class=attribute>_____GATWAY_</span></b> " + WiFi.gatewayIP().toString() + "</p>";
  message += "<p><b><span class=attribute>________DNS_</span></b> " + WiFi.dnsIP().toString() + "</p>";
  message += "<p><b><span class=attribute>_______SSID_</span></b> " + WiFi.SSID() + "</p>";
  message += "<p><b><span class=attribute>_______RSSI_</span></b> " + String(WiFi.RSSI()) + " dBm</p>";
  message += "<p><b><span class=attribute>_____CHANEL_</span></b> " + String(WiFi.channel()) + "</p>";
  message += "<p><b><span class=attribute>______BSSID_</span></b> " + WiFi.BSSIDstr() + "</p>";
  message += "<p><b><span class=attribute>___HOSTNAME_</span></b> " + String(WiFi.getHostname()) + "</p>";
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