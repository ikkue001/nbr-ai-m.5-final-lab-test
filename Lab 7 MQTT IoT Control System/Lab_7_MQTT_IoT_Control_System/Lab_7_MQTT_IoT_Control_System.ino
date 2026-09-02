#include <WiFi.h>
#include <PubSubClient.h>
#include <DHT.h>

const char* ssid = "YOUR_WIFI_SSID";
const char* password = "YOUR_WIFI_PASSWORD";
const char* mqtt_server = "broker.hivemq.com";

const int ledPin = 2;
#define DHTPIN 4
#define DHTTYPE DHT22
DHT dht(DHTPIN, DHTTYPE);

WiFiClient espClient;
PubSubClient client(espClient);
unsigned long lastMsg = 0;

void callback(char* topic, byte* payload, unsigned int length) {
  String message;
  for (int i = 0; i < length; i++) message += (char)payload[i];

  if (message == "ON") {
    digitalWrite(ledPin, HIGH);
    client.publish("lab_test/esp32/led/status", "ON");
  } else if (message == "OFF") {
    digitalWrite(ledPin, LOW);
    client.publish("lab_test/esp32/led/status", "OFF");
  }
}

void reconnect() {
  while (!client.connected()) {
    String clientId = "ESP32Dual-" + String(random(0xffff), HEX);
    if (client.connect(clientId.c_str())) {
      client.subscribe("lab_test/esp32/led/set");
    } else {
      delay(2000);
    }
  }
}

void setup() {
  Serial.begin(115200);
  pinMode(ledPin, OUTPUT);
  dht.begin();
  WiFi.begin(ssid, password);
  while (WiFi.status() != WL_CONNECTED) delay(500);
  client.setServer(mqtt_server, 1883);
  client.setCallback(callback);
}

void loop() {
  if (!client.connected()) reconnect();
  client.loop();

  unsigned long now = millis();
  if (now - lastMsg > 5000) {
    lastMsg = now;
    float temp = dht.readTemperature();
    if (!isnan(temp)) {
      client.publish("lab_test/esp32/temp", String(temp).c_str());
    }
  }
}
