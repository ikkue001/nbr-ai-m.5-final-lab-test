#include <WiFi.h>
#include <PubSubClient.h>

const char* ssid = "YOUR_WIFI_SSID";
const char* password = "YOUR_WIFI_PASSWORD";

// กำหนดรหัสนักศึกษา หรือชื่อกลุ่ม เพื่อแยก Topic ไม่ให้ซ้ำกับผู้อื่น
const char* student_id = "XXXXX";

const char* mqtt_server = "broker.emqx.io";
const int ledPin = 2;

// กำหนด Topic สำหรับรอรับคำสั่งเปิด/ปิดไฟตาม student_id
String sub_topic;

WiFiClient espClient;
PubSubClient client(espClient);

void callback(char* topic, byte* payload, unsigned int length) {
  String message = "";
  for (int i = 0; i < length; i++) {
    message += (char)payload[i];
  }
  Serial.println("Message arrived [" + String(topic) + "]: " + message);

  // ควบคุมไฟ LED ตามคำสั่งที่ส่งมาจาก MQTTX ("ON" หรือ "OFF")
  if (message == "ON") {
    digitalWrite(ledPin, HIGH);
  } else if (message == "OFF") {
    digitalWrite(ledPin, LOW);
  }
}

void reconnect() {
  while (!client.connected()) {
    Serial.print("Connecting to MQTT...");
    String clientId = "ESP32Sub-" + String(student_id) + "-" + String(random(0xffff), HEX);
    if (client.connect(clientId.c_str())) {
      Serial.println("connected");
      // สั่ง Subscribe ตาม Topic เฉพาะของตนเอง
      client.subscribe(sub_topic.c_str());
      Serial.println("Subscribed to: " + sub_topic);
    } else {
      delay(2000);
    }
  }
}

void setup() {
  Serial.begin(115200);
  pinMode(ledPin, OUTPUT);
  digitalWrite(ledPin, LOW);

  // กำหนด Topic ตาม student_id
  sub_topic = "student/" + String(student_id) + "/led/set";

  WiFi.begin(ssid, password);
  while (WiFi.status() != WL_CONNECTED) {
    delay(500);
  }
  client.setServer(mqtt_server, 1883);
  client.setCallback(callback);
}

void loop() {
  if (!client.connected()) {
    reconnect();
  }
  client.loop();
}
