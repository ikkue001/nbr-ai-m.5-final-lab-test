#include <WiFi.h>
#include <WebServer.h>
#include <PubSubClient.h>
#include <WiFiClientSecure.h>
#include <UniversalTelegramBot.h>
#include <DHT.h>

const char* ssid = "YOUR_WIFI_SSID";
const char* password = "YOUR_WIFI_PASSWORD";
const char* mqtt_server = "broker.hivemq.com";

#define BOTtoken "YOUR_TELEGRAM_BOT_TOKEN"
#define CHAT_ID "YOUR_TELEGRAM_CHAT_ID"

const int ledPin = 2;
const int buzzerPin = 18;
#define DHTPIN 4
#define DHTTYPE DHT22

DHT dht(DHTPIN, DHTTYPE);
WebServer server(80);

WiFiClient espClient;
PubSubClient mqttClient(espClient);

WiFiClientSecure securedClient;
UniversalTelegramBot bot(BOTtoken, securedClient);

unsigned long lastMqttPub = 0;
bool alertSent = false;

void handleRoot() {
  float t = dht.readTemperature();
  float h = dht.readHumidity();
  String html = "<html><head><meta charset='UTF-8'><meta http-equiv='refresh' content='5'></head><body>";
  html += "<h2>Smart IoT Node</h2>";
  html += "<p>อุณหภูมิ: " + String(t) + " C</p>";
  html += "<p>ความชื้น: " + String(h) + " %</p>";
  html += "<p><a href='/toggle'>เปิด/ปิด LED</a></p>";
  html += "</body></html>";
  server.send(200, "text/html", html);
}

void handleToggle() {
  digitalWrite(ledPin, !digitalRead(ledPin));
  server.sendHeader("Location", "/");
  server.send(303);
}

void setup() {
  Serial.begin(115200);
  pinMode(ledPin, OUTPUT);
  pinMode(buzzerPin, OUTPUT);
  digitalWrite(buzzerPin, LOW);

  dht.begin();
  WiFi.begin(ssid, password);
  while (WiFi.status() != WL_CONNECTED) delay(500);

  mqttClient.setServer(mqtt_server, 1883);
  securedClient.setInsecure();

  server.on("/", handleRoot);
  server.on("/toggle", handleToggle);
  server.begin();
}

void loop() {
  server.handleClient();

  if (!mqttClient.connected()) {
    String id = "ESP32Project-" + String(random(0xffff), HEX);
    mqttClient.connect(id.c_str());
  }
  mqttClient.loop();

  unsigned long now = millis();
  if (now - lastMqttPub > 5000) {
    lastMqttPub = now;
    float t = dht.readTemperature();
    float h = dht.readHumidity();

    if (!isnan(t)) {
      mqttClient.publish("lab10/temp", String(t).c_str());
      mqttClient.publish("lab10/hum", String(h).c_str());

      // ตรวจสอบเงื่อนไขแจ้งเตือนอุณหภูมิสูงเกิน 35 องศา
      if (t > 35.0 && !alertSent) {
        digitalWrite(buzzerPin, HIGH);
        bot.sendMessage(CHAT_ID, "คำเตือน: อุณหภูมิสูงเกินกำหนด! (" + String(t) + " C)", "");
        alertSent = true;
      } else if (t <= 35.0 && alertSent) {
        digitalWrite(buzzerPin, LOW);
        alertSent = false;
      }
    }
  }
}
