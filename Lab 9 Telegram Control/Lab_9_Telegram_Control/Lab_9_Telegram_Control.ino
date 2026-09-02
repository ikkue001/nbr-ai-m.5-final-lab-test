#include <WiFi.h>
#include <WiFiClientSecure.h>
#include <UniversalTelegramBot.h>

const char* ssid = "YOUR_WIFI_SSID";
const char* password = "YOUR_WIFI_PASSWORD";

#define BOTtoken "YOUR_TELEGRAM_BOT_TOKEN"
#define CHAT_ID "YOUR_TELEGRAM_CHAT_ID"

const int ledPin = 2;
WiFiClientSecure secured_client;
UniversalTelegramBot bot(BOTtoken, secured_client);

int botRequestDelay = 1000;
unsigned long lastTimeBotRan;

void handleNewMessages(int numNewMessages) {
  for (int i = 0; i < numNewMessages; i++) {
    String chat_id = String(bot.messages[i].chat_id);
    if (chat_id != CHAT_ID) continue; // ตรวจสอบความปลอดภัยรับเฉพาะเจ้าของ

    String text = bot.messages[i].text;

    if (text == "/led_on") {
      digitalWrite(ledPin, HIGH);
      bot.sendMessage(chat_id, "เปิดไฟ LED เรียบร้อยแล้ว", "");
    } else if (text == "/led_off") {
      digitalWrite(ledPin, LOW);
      bot.sendMessage(chat_id, "ปิดไฟ LED เรียบร้อยแล้ว", "");
    } else if (text == "/status") {
      String status = digitalRead(ledPin) ? "ON" : "OFF";
      bot.sendMessage(chat_id, "สถานะ LED ปัจจุบัน: " + status, "");
    } else {
      bot.sendMessage(chat_id, "คำสั่งที่รองรับ:\n/led_on\n/led_off\n/status", "");
    }
  }
}

void setup() {
  Serial.begin(115200);
  pinMode(ledPin, OUTPUT);
  digitalWrite(ledPin, LOW);

  WiFi.begin(ssid, password);
  while (WiFi.status() != WL_CONNECTED) delay(500);

  secured_client.setInsecure();
}

void loop() {
  if (millis() > lastTimeBotRan + botRequestDelay) {
    int numNewMessages = bot.getUpdates(bot.last_message_received + 1);
    while (numNewMessages) {
      handleNewMessages(numNewMessages);
      numNewMessages = bot.getUpdates(bot.last_message_received + 1);
    }
    lastTimeBotRan = millis();
  }
}
