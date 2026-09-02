#include <WiFi.h>
#include <WebServer.h>

const char* ssid = "YOUR_WIFI_SSID";
const char* password = "YOUR_WIFI_PASSWORD";

WebServer server(80);

void handleRoot() {
  String html = "<!DOCTYPE html><html><head><meta charset='UTF-8'>";
  html += "<meta name='viewport' content='width=device-width, initial-scale=1.0'>";
  html += "<title>ESP32 Web Server</title>";
  html += "<style>body{font-family:Arial;text-align:center;margin-top:50px;}";
  html += ".card{display:inline-block;padding:20px;border-radius:10px;box-shadow:0 0 10px rgba(0,0,0,0.1);}</style></head>";
  html += "<body><div class='card'>";
  html += "<h2>ESP32 Dashboard</h2>";
  html += "<p><b>WiFi:</b> " + String(ssid) + "</p>";
  html += "<p><b>IP Address:</b> " + WiFi.localIP().toString() + "</p>";
  html += "<p><b>RSSI:</b> " + String(WiFi.RSSI()) + " dBm</p>";
  html += "<p><b>Uptime:</b> " + String(millis() / 1000) + " seconds</p>";
  html += "</div></body></html>";

  server.send(200, "text/html", html);
}

void setup() {
  Serial.begin(115200);
  WiFi.begin(ssid, password);
  while (WiFi.status() != WL_CONNECTED) {
    delay(500);
    Serial.print(".");
  }
  Serial.println("\nConnected to WiFi");
  Serial.println(WiFi.localIP());

  server.on("/", handleRoot);
  server.begin();
  Serial.println("HTTP server started");
}

void loop() {
  server.handleClient();
}
