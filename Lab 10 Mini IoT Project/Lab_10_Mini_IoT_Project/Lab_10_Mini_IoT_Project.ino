#include <WiFi.h>
#include <WebServer.h>
#include <PubSubClient.h>
#include <WiFiClientSecure.h>
#include <UniversalTelegramBot.h>
#include <DHT.h>

const char* ssid = "YOUR_WIFI_SSID";
const char* password = "YOUR_WIFI_PASSWORD";

// กำหนดรหัสนักศึกษา หรือชื่อกลุ่ม เพื่อแยก Topic ไม่ให้ซ้ำกับผู้อื่น
const char* student_id = "XXXXX";

// MQTT Broker (ตั้งค่าในโปรแกรม MQTTX เช่นกัน)
const char* mqtt_server = "broker.emqx.io";
const int mqtt_port = 1883;

#define BOTtoken "YOUR_TELEGRAM_BOT_TOKEN"
#define CHAT_ID "YOUR_TELEGRAM_CHAT_ID"

const int temp_target = 35;

const int ledPin = 2;
const int buzzerPin = 18;
#define DHTPIN 4
#define DHTTYPE DHT22 // ถ้าใช้เป็น DHT11 ให้เปลี่ยนเป็น DHT11

DHT dht(DHTPIN, DHTTYPE);
WebServer server(80);

WiFiClient espClient;
PubSubClient mqttClient(espClient);

WiFiClientSecure securedClient;
UniversalTelegramBot bot(BOTtoken, securedClient);

unsigned long lastMqttPub = 0;
bool alertSent = false;
String topic_sensor;

void handleRoot() {
  float t = dht.readTemperature();
  float h = dht.readHumidity();
  String html = "<html><head><meta charset='UTF-8'><meta http-equiv='refresh' content='5'></head><body>";
  html += "<h2>Smart IoT Node</h2>";
  html += "<p>อุณหภูมิ: " + String(t, 1) + " C</p>";
  html += "<p>ความชื้น: " + String(h, 1) + " %</p>";
  html += "<p>สถานะ LED: <b>" + String(digitalRead(ledPin) ? "ON" : "OFF") + "</b></p>";
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

  // กำหนดชื่อ Topic ประจำตัวนักศึกษา
  topic_sensor = "student/" + String(student_id) + "/sensor";

  dht.begin();
  WiFi.begin(ssid, password);
  while (WiFi.status() != WL_CONNECTED) delay(500);

  mqttClient.setServer(mqtt_server, mqtt_port);
  securedClient.setInsecure();

  server.on("/", handleRoot);
  server.on("/toggle", handleToggle);
  server.begin();

  Serial.println("\nWiFi Connected. Server IP: " + WiFi.localIP().toString());
  Serial.println("MQTT Topic: " + topic_sensor);
}

void loop() {
  server.handleClient();

  if (!mqttClient.connected()) {
    String id = "ESP32Lab10-" + String(student_id) + "-" + String(random(0xffff), HEX);
    mqttClient.connect(id.c_str());
  }
  mqttClient.loop();

  unsigned long now = millis();
  if (now - lastMqttPub > 5000) {
    lastMqttPub = now;
    float t = dht.readTemperature();
    float h = dht.readHumidity();

    if (!isnan(t) && !isnan(h)) {
      // ส่งค่าอุณหภูมิและความชื้นพร้อมกันในรูปแบบ JSON ไปยัง Topic ของตนเอง
      String payload = "{\"temp\":" + String(t, 1) + ",\"hum\":" + String(h, 1) + "}";
      mqttClient.publish(topic_sensor.c_str(), payload.c_str());
      Serial.println("Published to [" + topic_sensor + "]: " + payload);

      // ตรวจสอบเงื่อนไขแจ้งเตือนอุณหภูมิสูงเกิน 35 องศา
      if (t > temp_target && !alertSent) {
        digitalWrite(buzzerPin, HIGH);
        bot.sendMessage(CHAT_ID, "คำเตือน: อุณหภูมิสูงเกินกำหนด! (" + String(t, 1) + " C)", "");
        alertSent = true;
      } else if (t <= temp_target && alertSent) {
        digitalWrite(buzzerPin, LOW);
        alertSent = false;
      }
    }
  }
}
