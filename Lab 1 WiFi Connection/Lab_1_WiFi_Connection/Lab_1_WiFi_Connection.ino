#include <WiFi.h>

const char* ssid = "YOUR_WIFI_SSID";
const char* password = "YOUR_WIFI_PASSWORD";

unsigned long previousMillis = 0;
const unsigned long interval = 10000; // ตรวจสอบสถานะทุก 10 วินาที
bool wasConnected = true;

void connectToWiFi() {
  WiFi.mode(WIFI_STA);
  WiFi.begin(ssid, password);
  Serial.print("Connecting to WiFi");
  while (WiFi.status() != WL_CONNECTED) {
    Serial.print('.');
    delay(500);
  }
  Serial.println("");
  Serial.println("WiFi Connected!");
  Serial.print("IP Address: ");
  Serial.println(WiFi.localIP());
  wasConnected = true;
}

void setup() {
  Serial.begin(115200);
  connectToWiFi();
}

void loop() {
  unsigned long currentMillis = millis();

  // ตรวจสอบเมื่อ WiFi หลุดการเชื่อมต่อ
  if (WiFi.status() != WL_CONNECTED) {
    if (wasConnected) {
      Serial.println("\nWiFi connection lost!");
      wasConnected = false;
    }

    if (currentMillis - previousMillis >= interval) {
      Serial.println("WiFi connection lost. Reconnecting...");
      WiFi.disconnect();
      WiFi.reconnect();
      previousMillis = currentMillis;
    }
  } 
  // เมื่อกลับมาเชื่อมต่อได้สำเร็จ
  else {
    if (!wasConnected) {
      Serial.println("\nWiFi Reconnected!");
      Serial.print("IP Address: ");
      Serial.println(WiFi.localIP());
      wasConnected = true;
    }
  }
}
