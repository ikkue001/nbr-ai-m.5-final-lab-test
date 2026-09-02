#include <WiFi.h>
#include <WebServer.h>

const char* ssid = "YOUR_WIFI_SSID";
const char* password = "YOUR_WIFI_PASSWORD";

const int ledPin = 2;
bool ledState = false;

WebServer server(80);

void sendWebPage() {
  String html = "<!DOCTYPE html><html><head><meta charset='UTF-8'>";
  html += "<meta name='viewport' content='width=device-width, initial-scale=1.0'>";
  html += "<title>LED Control</title>";
  html += "<style>body{font-family:Arial;text-align:center;margin-top:50px;}";
  html += ".btn{display:inline-block;padding:15px 30px;font-size:20px;margin:10px;border-radius:8px;text-decoration:none;color:white;}";
  html += ".on{background:#28a745;}.off{background:#dc3545;}</style></head>";
  html += "<body><h1>ESP32 LED Control</h1>";
  html += "<p>สถานะ LED: <b>" + String(ledState ? "เปิด (ON)" : "ปิด (OFF)") + "</b></p>";
  html += "<a href='/led/on' class='btn on'>เปิดไฟ (ON)</a>";
  html += "<a href='/led/off' class='btn off'>ปิดไฟ (OFF)</a>";
  html += "</body></html>";
  server.send(200, "text/html", html);
}

void handleRoot() {
  sendWebPage();
}

void handleLedOn() {
  ledState = true;
  digitalWrite(ledPin, HIGH);
  server.sendHeader("Location", "/");
  server.send(303);
}

void handleLedOff() {
  ledState = false;
  digitalWrite(ledPin, LOW);
  server.sendHeader("Location", "/");
  server.send(303);
}

void setup() {
  Serial.begin(115200);
  pinMode(ledPin, OUTPUT);
  digitalWrite(ledPin, LOW);

  WiFi.begin(ssid, password);
  while (WiFi.status() != WL_CONNECTED) {
    delay(500);
    Serial.print(".");
  }

  Serial.println("\nServer IP: ");
  Serial.println(WiFi.localIP());

  server.on("/", handleRoot);
  server.on("/led/on", handleLedOn);
  server.on("/led/off", handleLedOff);
  server.begin();
}

void loop() {
  server.handleClient();
}
