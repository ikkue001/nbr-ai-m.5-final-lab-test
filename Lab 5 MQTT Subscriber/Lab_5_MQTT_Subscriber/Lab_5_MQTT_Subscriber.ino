#include <WiFi.h>
#include <PubSubClient.h>
#include <DHT.h>

const char* ssid = "YOUR_WIFI_SSID";
const char* password = "YOUR_WIFI_PASSWORD";

// กำหนดรหัสนักศึกษา หรือชื่อกลุ่ม เพื่อแยก Topic ไม่ให้ซ้ำกับผู้อื่น
const char* student_id = "XXXXX"; 

// MQTT Broker
const char* mqtt_server = "broker.emqx.io";
const int mqtt_port = 1883;

#define DHTPIN 4
#define DHTTYPE DHT22 // เปลี่ยนเป็น DHT11 หากใช้งานบอร์ด DHT11
DHT dht(DHTPIN, DHTTYPE);

WiFiClient espClient;
PubSubClient client(espClient);

unsigned long lastMsg = 0;
String topic_sensor;

void reconnect() {
  while (!client.connected()) {
    Serial.print("Attempting MQTT connection...");
    String clientId = "ESP32Pub-" + String(student_id) + "-" + String(random(0xffff), HEX);
    if (client.connect(clientId.c_str())) {
      Serial.println("connected");
    } else {
      Serial.print("failed, rc=");
      Serial.print(client.state());
      delay(2000);
    }
  }
}

void setup() {
  Serial.begin(115200);
  dht.begin();

  // กำหนดชื่อ Topic ตาม student_id
  topic_sensor = "student/" + String(student_id) + "/sensor";

  WiFi.begin(ssid, password);
  while (WiFi.status() != WL_CONNECTED) {
    delay(500);
    Serial.print(".");
  }
  client.setServer(mqtt_server, mqtt_port);
  Serial.println("\nWiFi Connected. Ready to publish to: " + topic_sensor);
}

void loop() {
  if (!client.connected()) {
    reconnect();
  }
  client.loop();

  unsigned long now = millis();
  if (now - lastMsg > 5000) { // ส่งข้อมูลทุก 5 วินาที
    lastMsg = now;
    float temp = dht.readTemperature();
    float hum = dht.readHumidity();

    if (!isnan(temp) && !isnan(hum)) {
      // ส่งค่าอุณหภูมิและความชื้นพร้อมกันในรูปแบบ JSON
      // ในโปรแกรม MQTTX ให้ Subscribe Topic: student/<student_id>/sensor หรือ student/<student_id>/#
      String payload = "{\"temp\":" + String(temp, 1) + ",\"hum\":" + String(hum, 1) + "}";
      client.publish(topic_sensor.c_str(), payload.c_str());
      Serial.println("Published to [" + topic_sensor + "]: " + payload);
    }
  }
}
