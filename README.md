# ESP32 IoT Final Lab Test (ม.5)

ชุดการทดลองปฏิบัติการ ESP32 IoT สำหรับการสอบปลายภาค / แบบทดสอบปฏิบัติการ ประกอบด้วย 10 หัวข้อการทดลอง (LAB 1 - LAB 10)

---

## สรุปรายการแบบทดสอบ (Lab Overview)

| ลำดับ | โฟลเดอร์ | หัวข้อการทดลอง | ไฟล์โค้ด (.ino) | ไฟล์คำแนะนำ | คะแนน | สรุปเนื้อหา |
| :---: | :--- | :--- | :--- | :---: | :---: | :--- |
| **Lab 1** | [Lab 1 WiFi Connection](./Lab%201%20WiFi%20Connection/) | ESP32 เชื่อมต่อ WiFi พร้อมระบบ Auto-Reconnect | [`Lab_1_WiFi_Connection.ino`](./Lab%201%20WiFi%20Connection/Lab_1_WiFi_Connection.ino) | [Instruction.txt](./Lab%201%20WiFi%20Connection/Instruction.txt) | 5 | เชื่อมต่อ WiFi 2.4 GHz และตรวจจับการหลุดเพื่อ Reconnect อัตโนมัติใน loop() |
| **Lab 2** | [Lab 2 HTTP Web Server](./Lab%202%20HTTP%20Web%20Server/) | ESP32 HTTP Web Server แสดงข้อมูลระบบ | [`Lab_2_HTTP_Web_Server.ino`](./Lab%202%20HTTP%20Web%20Server/Lab_2_HTTP_Web_Server.ino) | [Instruction.txt](./Lab%202%20HTTP%20Web%20Server/Instruction.txt) | 5 | สร้าง Web Server แสดง WiFi SSID, IP, RSSI และ Uptime บน Web Browser |
| **Lab 3** | [Lab 3 Web Server Control LED](./Lab%203%20Web%20Server%20Control%20LED/) | Web Server ควบคุมเปิด–ปิด LED | [`Lab_3_Web_Server_Control_LED.ino`](./Lab%203%20Web%20Server%20Control%20LED/Lab_3_Web_Server_Control_LED.ino) | [Instruction.txt](./Lab%203%20Web%20Server%20Control%20LED/Instruction.txt) | 5 | ควบคุมหลอดไฟ LED (GPIO 2) ผ่าน Web UI Routing `/led/on` และ `/led/off` |
| **Lab 4** | [Lab 4 Sensor Monitoring ผ่าน Web](./Lab%204%20Sensor%20Monitoring%20%E0%B8%9C%E0%B9%88%E0%B8%B2%E0%B8%99%20Web/) | Web Server แสดงข้อมูล Sensor พร้อม Auto-Refresh | [`Lab_4_Sensor_Monitoring_ผ่าน_Web.ino`](./Lab%204%20Sensor%20Monitoring%20%E0%B8%9C%E0%B9%88%E0%B8%B2%E0%B8%99%20Web/Lab_4_Sensor_Monitoring_%E0%B8%9C%E0%B9%88%E0%B8%B2%E0%B8%99_Web.ino) | [Instruction.txt](./Lab%204%20Sensor%20Monitoring%20%E0%B8%9C%E0%B9%88%E0%B8%B2%E0%B8%99%20Web/Instruction.txt) | 5 | อ่านอุณหภูมิและความชื้นจากเซนเซอร์ DHT และรีเฟรชหน้าเว็บอัตโนมัติทุก 3 วินาที |
| **Lab 5** | [Lab 5 MQTT Publisher](./Lab%205%20MQTT%20Publisher/) | MQTT Publisher ส่งข้อมูล Sensor เข้าสู่ Broker | [`Lab_5_MQTT_Publisher.ino`](./Lab%205%20MQTT%20Publisher/Lab_5_MQTT_Publisher.ino) | [Instruction.txt](./Lab%205%20MQTT%20Publisher/Instruction.txt) | 5 | ส่งข้อมูล Sensor ไปยัง HiveMQ Public Broker ทุก 5 วินาที ผ่านโปรโตคอล MQTT |
| **Lab 6** | [Lab 6 MQTT Subscriber](./Lab%206%20MQTT%20Subscriber/) | MQTT Subscriber รับคำสั่งเปิด–ปิด LED | [`Lab_6_MQTT_Subscriber.ino`](./Lab%206%20MQTT%20Subscriber/Lab_6_MQTT_Subscriber.ino) | [Instruction.txt](./Lab%206%20MQTT%20Subscriber/Instruction.txt) | 5 | ดักฟัง Topic เพื่อรับข้อความคำสั่ง "ON" / "OFF" มาสั่งเปิด–ปิด LED (GPIO 2) |
| **Lab 7** | [Lab 7 MQTT IoT Control System](./Lab%207%20MQTT%20IoT%20Control%20System/) | MQTT IoT Two-Way Control System | [`Lab_7_MQTT_IoT_Control_System.ino`](./Lab%207%20MQTT%20IoT%20Control%20System/Lab_7_MQTT_IoT_Control_System.ino) | [Instruction.txt](./Lab%207%20MQTT%20IoT%20Control%20System/Instruction.txt) | 5 | ระบบสื่อสารสองทิศทาง: ส่งค่า Sensor และรับคำสั่งเปิด-ปิดไฟพร้อมส่งสถานะยืนยันกลับ |
| **Lab 8** | [Lab 8 Telegram Alert](./Lab%208%20Telegram%20Alert/) | ESP32 แจ้งเตือนข้อความผ่าน Telegram Bot | [`Lab_8_Telegram_Alert.ino`](./Lab%208%20Telegram%20Alert/Lab_8_Telegram_Alert.ino) | [Instruction.txt](./Lab%208%20Telegram%20Alert/Instruction.txt) | 5 | แจ้งเตือนข้อความเข้า Telegram เมื่อตรวจพบการกดปุ่มฉุกเฉิน (GPIO 14) |
| **Lab 9** | [Lab 9 Telegram Control](./Lab%209%20Telegram%20Control/) | ควบคุมและเช็กสถานะ ESP32 ผ่าน Telegram Bot | [`Lab_9_Telegram_Control.ino`](./Lab%209%20Telegram%20Control/Lab_9_Telegram_Control.ino) | [Instruction.txt](./Lab%209%20Telegram%20Control/Instruction.txt) | 5 | ควบคุมและอ่านสถานะ ESP32 สองทางผ่านคำสั่งแชต `/led_on`, `/led_off`, `/status` |
| **Lab 10** | [Lab 10 Mini IoT Project](./Lab%2010%20Mini%20IoT%20Project/) | Mini Project — Smart IoT Integrated System | [`Lab_10_Mini_IoT_Project.ino`](./Lab%2010%20Mini%20IoT%20Project/Lab_10_Mini_IoT_Project.ino) | [Instruction.txt](./Lab%2010%20Mini%20IoT%20Project/Instruction.txt) | 10 | ผสาน Web Server + MQTT + Telegram Bot + Buzzer ส่งเสียงและแจ้งเตือนเมื่ออุณหภูมิเกิน 35°C |

---

## ตารางการต่อขาใช้งาน (Pin Assignment Summary)

| อุปกรณ์ / เซนเซอร์ | ขา ESP32 (GPIO) | โหมดการทำงาน | หมายเหตุ / Lab ที่ใช้งาน |
| :--- | :---: | :---: | :--- |
| **LED** | `GPIO 2` | `OUTPUT` | Active HIGH (Lab 3, Lab 6, Lab 7, Lab 9, Lab 10) |
| **DHT11 / DHT22 (Data)** | `GPIO 4` | `INPUT` | ข้อมูลอุณหภูมิและความชื้น (Lab 4, Lab 5, Lab 7, Lab 10) |
| **Push Button (สวิตช์กด)** | `GPIO 14` | `INPUT_PULLUP` | กดแล้วต่อลง GND (Lab 8) |
| **Active Buzzer (ลำโพง)** | `GPIO 18` | `OUTPUT` | ส่งเสียงเตือนภัยเมื่ออุณหภูมิสูง (Lab 10) |

---

## ไลบรารีที่จำเป็นสำหรับ Arduino IDE (Required Libraries)

สามารถติดตั้งผ่านเมนู **Library Manager** (`Ctrl + Shift + I`):

1. **DHT sensor library** (โดย *Adafruit*) — สำหรับอ่านค่าเซนเซอร์ DHT11 / DHT22
2. **Adafruit Unified Sensor** (โดย *Adafruit*) — Dependency สำหรับเซนเซอร์ DHT
3. **PubSubClient** (โดย *Nick O'Leary*) — สำหรับการเชื่อมต่อโปรโตคอล MQTT
4. **UniversalTelegramBot** (โดย *Brian Lough*) — สำหรับการเชื่อมต่อ Telegram Bot API
5. **ArduinoJson** (โดย *Benoit Blanchon*) — รองรับการแปลง JSON (จำเป็นสำหรับ UniversalTelegramBot)

---

## การตั้งค่าเริ่มต้นทั่วไป

- **Baud Rate ของ Serial Monitor**: `115200`
- **WiFi Network**: ต้องเป็นเครือข่ายความถี่ **2.4 GHz** เท่านั้น (ESP32 รุ่นมาตรฐานไม่รองรับ 5 GHz)
- **MQTT Public Broker**: `broker.hivemq.com` พอร์ต `1883`
- **Telegram Bot**: ต้องสร้างบอทผ่าน `@BotFather` เพื่อรับ Token และหา Chat ID ผ่าน `@userinfobot`
