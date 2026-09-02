#include <WiFi.h>
#include <WiFiClientSecure.h>
#include <UniversalTelegramBot.h>

const char* ssid = "YOUR_WIFI_SSID";
const char* password = "YOUR_WIFI_PASSWORD";

#define BOTtoken "YOUR_TELEGRAM_BOT_TOKEN"
#define CHAT_ID "YOUR_TELEGRAM_CHAT_ID"

const int buttonPin = 14;
int lastButtonState = HIGH;

WiFiClientSecure secured_client;
UniversalTelegramBot bot(BOTtoken, secured_client);

void setup() {
  Serial.begin(115200);
  pinMode(buttonPin, INPUT_PULLUP);

  WiFi.begin(ssid, password);
  while (WiFi.status() != WL_CONNECTED) delay(500);

  secured_client.setInsecure(); // ข้ามการตรวจสอบ Root CA เพื่อความรวดเร็วในการทดลอง
  bot.sendMessage(CHAT_ID, "ระบบ ESP32 เริ่มทำงานแล้ว", "");
}

void loop() {
  int buttonState = digitalRead(buttonPin);
  if (buttonState == LOW && lastButtonState == HIGH) {
    bot.sendMessage(CHAT_ID, "แจ้งเตือน: ตรวจพบการกดปุ่มฉุกเฉิน!", "");
    delay(500); // Debounce ป้องกันการกดเบิ้ล
  }
  lastButtonState = buttonState;
}
