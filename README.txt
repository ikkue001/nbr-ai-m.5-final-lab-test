================================================================================
                    ESP32 IoT Final Lab Test (ม.5)
================================================================================
ชุดการทดลองปฏิบัติการ ESP32 IoT สำหรับการสอบปลายภาค / แบบทดสอบปฏิบัติการ
ประกอบด้วย 10 หัวข้อการทดลอง (LAB 1 - LAB 10)

--------------------------------------------------------------------------------
รายการแบบทดสอบทั้งหมด (Lab Overview)
--------------------------------------------------------------------------------

[LAB 1]
- โฟลเดอร์: Lab 1 WiFi Connection
- ไฟล์โค้ด: Lab_1_WiFi_Connection.ino
- คำแนะนำ: Instruction.txt
- หัวข้อ: ESP32 เชื่อมต่อ WiFi พร้อมระบบ Auto-Reconnect
- คะแนน: 5 คะแนน
- สรุปเนื้อหา: เชื่อมต่อ WiFi 2.4 GHz และตรวจจับการหลุดเพื่อ Reconnect อัตโนมัติใน loop()

[LAB 2]
- โฟลเดอร์: Lab 2 HTTP Web Server
- ไฟล์โค้ด: Lab_2_HTTP_Web_Server.ino
- คำแนะนำ: Instruction.txt
- หัวข้อ: ESP32 HTTP Web Server แสดงข้อมูลระบบ
- คะแนน: 5 คะแนน
- สรุปเนื้อหา: สร้าง Web Server แสดง WiFi SSID, IP Address, RSSI และ Uptime บน Web Browser

[LAB 3]
- โฟลเดอร์: Lab 3 Web Server Control LED
- ไฟล์โค้ด: Lab_3_Web_Server_Control_LED.ino
- คำแนะนำ: Instruction.txt
- หัวข้อ: Web Server ควบคุมเปิด–ปิด LED
- คะแนน: 5 คะแนน
- สรุปเนื้อหา: ควบคุมหลอดไฟ LED (GPIO 2) ผ่านหน้าเว็บ Routing /led/on และ /led/off

[LAB 4]
- โฟลเดอร์: Lab 4 Sensor Monitoring ผ่าน Web
- ไฟล์โค้ด: Lab_4_Sensor_Monitoring_ผ่าน_Web.ino
- คำแนะนำ: Instruction.txt
- หัวข้อ: Web Server แสดงข้อมูล Sensor พร้อม Auto-Refresh
- คะแนน: 5 คะแนน
- สรุปเนื้อหา: อ่านค่าอุณหภูมิและความชื้นจากเซนเซอร์ DHT และรีเฟรชหน้าเว็บอัตโนมัติทุก 3 วินาที

[LAB 5]
- โฟลเดอร์: Lab 5 MQTT Publisher
- ไฟล์โค้ด: Lab_5_MQTT_Publisher.ino
- คำแนะนำ: Instruction.txt
- หัวข้อ: MQTT Publisher ส่งข้อมูล Sensor เข้าสู่ Broker
- คะแนน: 5 คะแนน
- สรุปเนื้อหา: ส่งข้อมูล Sensor ไปยัง HiveMQ Public Broker ทุก 5 วินาที ผ่านโปรโตคอล MQTT

[LAB 6]
- โฟลเดอร์: Lab 6 MQTT Subscriber
- ไฟล์โค้ด: Lab_6_MQTT_Subscriber.ino
- คำแนะนำ: Instruction.txt
- หัวข้อ: MQTT Subscriber รับคำสั่งเปิด–ปิด LED
- คะแนน: 5 คะแนน
- สรุปเนื้อหา: ดักฟัง Topic เพื่อรับข้อความคำสั่ง "ON" / "OFF" มาสั่งเปิด–ปิด LED (GPIO 2)

[LAB 7]
- โฟลเดอร์: Lab 7 MQTT IoT Control System
- ไฟล์โค้ด: Lab_7_MQTT_IoT_Control_System.ino
- คำแนะนำ: Instruction.txt
- หัวข้อ: MQTT IoT Two-Way Control System
- คะแนน: 5 คะแนน
- สรุปเนื้อหา: ระบบสื่อสารสองทิศทาง: ส่งค่า Sensor และรับคำสั่งเปิด-ปิดไฟพร้อมส่งสถานะยืนยันกลับ

[LAB 8]
- โฟลเดอร์: Lab 8 Telegram Alert
- ไฟล์โค้ด: Lab_8_Telegram_Alert.ino
- คำแนะนำ: Instruction.txt
- หัวข้อ: ESP32 แจ้งเตือนข้อความผ่าน Telegram Bot
- คะแนน: 5 คะแนน
- สรุปเนื้อหา: แจ้งเตือนข้อความเข้า Telegram เมื่อตรวจพบการกดปุ่มฉุกเฉิน (GPIO 14)

[LAB 9]
- โฟลเดอร์: Lab 9 Telegram Control
- ไฟล์โค้ด: Lab_9_Telegram_Control.ino
- คำแนะนำ: Instruction.txt
- หัวข้อ: ควบคุมและเช็กสถานะ ESP32 ผ่าน Telegram Bot
- คะแนน: 5 คะแนน
- สรุปเนื้อหา: ควบคุมและอ่านสถานะ ESP32 สองทางผ่านคำสั่งแชต /led_on, /led_off, /status

[LAB 10]
- โฟลเดอร์: Lab 10 Mini IoT Project
- ไฟล์โค้ด: Lab_10_Mini_IoT_Project.ino
- คำแนะนำ: Instruction.txt
- หัวข้อ: Mini Project — Smart IoT Integrated System
- คะแนน: 10 คะแนน
- สรุปเนื้อหา: ผสาน Web Server + MQTT + Telegram Bot + Buzzer ส่งเสียงและแจ้งเตือนเมื่ออุณหภูมิเกิน 35°C

--------------------------------------------------------------------------------
ตารางการต่อขาฮาร์ดแวร์ (GPIO Assignment Summary)
--------------------------------------------------------------------------------
+--------------------------+-----------+---------------+--------------------------------------+
| อุปกรณ์ / เซนเซอร์       | ขา ESP32  | โหมด          | Lab ที่ใช้งาน                        |
+--------------------------+-----------+---------------+--------------------------------------+
| LED                      | GPIO 2    | OUTPUT        | Lab 3, Lab 6, Lab 7, Lab 9, Lab 10   |
| DHT11 / DHT22 (Data)     | GPIO 4    | INPUT         | Lab 4, Lab 5, Lab 7, Lab 10          |
| Push Button (สวิตช์กด)   | GPIO 14   | INPUT_PULLUP  | Lab 8                                |
| Active Buzzer (ลำโพง)    | GPIO 18   | OUTPUT        | Lab 10                               |
+--------------------------+-----------+---------------+--------------------------------------+

--------------------------------------------------------------------------------
ไลบรารีที่จำเป็นสำหรับ Arduino IDE (Required Libraries)
--------------------------------------------------------------------------------
ติดตั้งผ่าน Library Manager ใน Arduino IDE (Ctrl + Shift + I):
1. DHT sensor library (โดย Adafruit)
2. Adafruit Unified Sensor (โดย Adafruit)
3. PubSubClient (โดย Nick O'Leary)
4. UniversalTelegramBot (โดย Brian Lough)
5. ArduinoJson (โดย Benoit Blanchon)

--------------------------------------------------------------------------------
การตั้งค่าเริ่มต้นทั่วไป (General Configuration)
--------------------------------------------------------------------------------
- Baud Rate ของ Serial Monitor: 115200
- WiFi Network: ต้องเป็นเครือข่ายความถี่ 2.4 GHz เท่านั้น
- MQTT Public Broker: broker.hivemq.com (Port: 1883)
- Telegram Bot: สร้างผ่าน @BotFather และค้นหา Chat ID ผ่าน @userinfobot
