#include <WiFi.h>
#include <WebServer.h>
#include <DHT.h>

const char* ssid = "YOUR_WIFI_SSID";
const char* password = "YOUR_WIFI_PASSWORD";

#define DHTPIN 4
#define DHTTYPE DHT22 // หรือเปลี่ยนเป็น DHT11
DHT dht(DHTPIN, DHTTYPE);

WebServer server(80);

void handleRoot() {
  float temp = dht.readTemperature();
  float hum = dht.readHumidity();

  String html = "<!DOCTYPE html><html><head><meta charset='UTF-8'>";
  html += "<meta name='viewport' content='width=device-width, initial-scale=1.0'>";
  html += "<meta http-equiv='refresh' content='3'>"; // Auto refresh ทุก 3 วินาที
  html += "<title>Sensor Monitor</title>";
  html += "<style>body{font-family:Arial;text-align:center;margin-top:50px;}";
  html += ".box{border:1px solid #ccc;padding:20px;display:inline-block;border-radius:10px;}</style></head>";
  html += "<body><div class='box'><h2>ESP32 Sensor Monitor</h2>";
  html += "<p>อุณหภูมิ: <b>" + String(temp, 1) + " &deg;C</b></p>";
  html += "<p>ความชื้น: <b>" + String(hum, 1) + " %</b></p>";
  html += "</div></body></html>";

  server.send(200, "text/html", html);
}

void setup() {
  Serial.begin(115200);
  dht.begin();

  WiFi.begin(ssid, password);
  while (WiFi.status() != WL_CONNECTED) {
    delay(500);
    Serial.print(".");
  }

  Serial.println("\nIP Address: ");
  Serial.println(WiFi.localIP());

  server.on("/", handleRoot);
  server.begin();
}

void loop() {
  server.handleClient();
}
