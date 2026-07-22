#include <WiFi.h>
#include <WebServer.h>

const char* ssid = "ESP32_Rede";
const char* password = "12345678";

WebServer server(80);

const int ledPin = 2;   // built-in LED on many ESP32 boards
bool ledState = false;

void handleRoot() {
  String html = "<!DOCTYPE html><html><head>";
  html += "<meta name='viewport' content='width=device-width, initial-scale=1'>";
  html += "<style>";
  html += "html { font-family: Helvetica; text-align: center; margin-top: 50px; }";
  html += ".button { background-color: #4CAF50; border: none; color: white; padding: 16px 40px; font-size: 24px; margin: 10px; cursor: pointer; }";
  html += ".off { background-color: #555555; }";
  html += "</style></head><body>";
  html += "<h1>ESP32 Web Server</h1>";
  html += "<p>LED State: " + String(ledState ? "ON" : "OFF") + "</p>";

  if (ledState) {
    html += "<p><a href='/led/off'><button class='button off'>OFF</button></a></p>";
  } else {
    html += "<p><a href='/led/on'><button class='button'>ON</button></a></p>";
  }

  html += "</body></html>";
  server.send(200, "text/html", html);
}

void handleLedOn() {
  ledState = true;
  digitalWrite(ledPin, HIGH);
  handleRoot();
}

void handleLedOff() {
  ledState = false;
  digitalWrite(ledPin, LOW);
  handleRoot();
}

void setup() {
  Serial.begin(115200);

  pinMode(ledPin, OUTPUT);
  digitalWrite(ledPin, LOW);

  WiFi.mode(WIFI_AP);
  WiFi.softAP(ssid, password);

  Serial.println("Access Point created!");
  Serial.print("ESP32 IP: ");
  Serial.println(WiFi.softAPIP());

  server.on("/", handleRoot);
  server.on("/led/on", handleLedOn);
  server.on("/led/off", handleLedOff);
  server.begin();

  Serial.println("Web server started");
}

void loop() {
  server.handleClient();
}
  
