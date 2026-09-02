#include <WiFi.h>
#include <PubSubClient.h>
#include <DHT.h>

const char* ssid = "YOUR_WIFI_SSID";
const char* password = "YOUR_WIFI_PASSWORD";

// กำหนดรหัสนักศึกษา หรือชื่อกลุ่ม เพื่อแยก Topic ไม่ให้ซ้ำกับผู้อื่น
const char* student_id = "XXXXX";

const char* mqtt_server = "broker.emqx.io";
const int ledPin = 2;

#define DHTPIN 4
#define DHTTYPE DHT22 //ถ้าใช้ DHT11 ให้แก้ไขตรงนี้ด้วย
DHT dht(DHTPIN, DHTTYPE);

// กำหนด Topic ตาม student_id
String topic_sensor;
String topic_led_set;
String topic_led_status;

WiFiClient espClient;
PubSubClient client(espClient);
unsigned long lastMsg = 0;

void callback(char* topic, byte* payload, unsigned int length) {
  String message = "";
  for (int i = 0; i < length; i++) message += (char)payload[i];

  Serial.println("Message arrived [" + String(topic) + "]: " + message);

  // เมื่อได้รับคำสั่งเปิด/ปิดไฟจาก MQTTX จะส่งสถานะยืนยันกลับไปยัง Topic ของผู้ใช้ทันที
  if (message == "ON") {
    digitalWrite(ledPin, HIGH);
    client.publish(topic_led_status.c_str(), "ON");
    Serial.println("Published to [" + topic_led_status + "]: ON");
  } else if (message == "OFF") {
    digitalWrite(ledPin, LOW);
    client.publish(topic_led_status.c_str(), "OFF");
    Serial.println("Published to [" + topic_led_status + "]: OFF");
  }
}

void reconnect() {
  while (!client.connected()) {
    String clientId = "ESP32Dual-" + String(student_id) + "-" + String(random(0xffff), HEX);
    if (client.connect(clientId.c_str())) {
      Serial.println("connected");
      // สั่ง Subscribe เฉพาะ Topic ของตนเอง
      client.subscribe(topic_led_set.c_str());
      Serial.println("Subscribed to: " + topic_led_set);
    } else {
      delay(2000);
    }
  }
}

void setup() {
  Serial.begin(115200);
  pinMode(ledPin, OUTPUT);
  digitalWrite(ledPin, LOW);
  dht.begin();

  // กำหนดชื่อ Topic ตาม student_id
  topic_sensor = "student/" + String(student_id) + "/sensor";
  topic_led_set = "student/" + String(student_id) + "/led/set";
  topic_led_status = "student/" + String(student_id) + "/led/status";

  WiFi.begin(ssid, password);
  while (WiFi.status() != WL_CONNECTED) delay(500);

  client.setServer(mqtt_server, 1883);
  client.setCallback(callback);
  Serial.println("\nReady. Sensor Topic: " + topic_sensor);
}

void loop() {
  if (!client.connected()) reconnect();
  client.loop();

  unsigned long now = millis();
  if (now - lastMsg > 5000) {
    lastMsg = now;
    float temp = dht.readTemperature();
    float hum = dht.readHumidity();

    if (!isnan(temp) && !isnan(hum)) {
      // ส่งค่าอุณหภูมิและความชื้นพร้อมกันในรูปแบบ JSON
      String payload = "{\"temp\":" + String(temp, 1) + ",\"hum\":" + String(hum, 1) + "}";
      client.publish(topic_sensor.c_str(), payload.c_str());
      Serial.println("Published to [" + topic_sensor + "]: " + payload);
    }
  }
}
