================================================================================
                    ESP32 IoT Final Lab Test (ม.5)
================================================================================
ชุดการทดลองปฏิบัติการ ESP32 IoT สำหรับการสอบปลายภาค / แบบทดสอบปฏิบัติการ
ประกอบด้วย 10 หัวข้อการทดลอง (LAB 1 - LAB 10)

--------------------------------------------------------------------------------
รายการแบบทดสอบทั้งหมด (Lab Overview)
--------------------------------------------------------------------------------

[LAB 1]
- โฟลเดอร์: Lab 1 WiFi Connection/Lab_1_WiFi_Connection/
- ไฟล์โค้ด: Lab_1_WiFi_Connection.ino
- คำแนะนำ: Instruction.txt
- หัวข้อ: WiFi Connection
- คะแนน: 5 คะแนน
- สรุปเนื้อหา: เชื่อมต่อ WiFi 2.4 GHz และตรวจจับการหลุดเพื่อ Reconnect อัตโนมัติ พร้อมแจ้งเตือน IP เมื่อเชื่อมต่อสำเร็จ

[LAB 2]
- โฟลเดอร์: Lab 2 HTTP Web Server/Lab_2_HTTP_Web_Server/
- ไฟล์โค้ด: Lab_2_HTTP_Web_Server.ino
- คำแนะนำ: Instruction.txt
- หัวข้อ: HTTP Web Server
- คะแนน: 5 คะแนน
- สรุปเนื้อหา: สร้าง Web Server แสดง WiFi SSID, IP Address, RSSI และ Uptime บน Web Browser

[LAB 3]
- โฟลเดอร์: Lab 3 Web Server Control LED/Lab_3_Web_Server_Control_LED/
- ไฟล์โค้ด: Lab_3_Web_Server_Control_LED.ino
- คำแนะนำ: Instruction.txt
- หัวข้อ: Web Server Control LED
- คะแนน: 10 คะแนน
- สรุปเนื้อหา: ควบคุมหลอดไฟ LED (GPIO 2) ผ่านหน้าเว็บ Routing /led/on และ /led/off

[LAB 4]
- โฟลเดอร์: Lab 4 Sensor Monitoring ผ่าน Web/Lab_4_Sensor_Monitoring_via_Web/
- ไฟล์โค้ด: Lab_4_Sensor_Monitoring_via_Web.ino
- คำแนะนำ: Instruction.txt
- หัวข้อ: Sensor Monitoring ผ่าน Web
- คะแนน: 10 คะแนน
- สรุปเนื้อหา: อ่านค่าอุณหภูมิและความชื้นจากเซนเซอร์ DHT และรีเฟรชหน้าเว็บอัตโนมัติทุก 3 วินาที

[LAB 5]
- โฟลเดอร์: Lab 5 MQTT Publisher/Lab_5_MQTT_Publisher/
- ไฟล์โค้ด: Lab_5_MQTT_Publisher.ino
- คำแนะนำ: Instruction.txt
- หัวข้อ: MQTT Publisher
- คะแนน: 10 คะแนน
- สรุปเนื้อหา: ส่งข้อมูล Temp & Hum พร้อมกันในรูปแบบ JSON ไปยัง Broker ทุก 5 วินาที โดยแยก Topic ตาม student_id ผ่านโปรแกรม MQTTX

[LAB 6]
- โฟลเดอร์: Lab 6 MQTT Subscriber/Lab_6_MQTT_Subscriber/
- ไฟล์โค้ด: Lab_6_MQTT_Subscriber.ino
- คำแนะนำ: Instruction.txt
- หัวข้อ: MQTT Subscriber
- คะแนน: 10 คะแนน
- สรุปเนื้อหา: ดักฟัง Topic เฉพาะตัวตาม student_id เพื่อรับคำสั่ง "ON" / "OFF" จากโปรแกรม MQTTX มาสั่งเปิด–ปิด LED (GPIO 2)

[LAB 7]
- โฟลเดอร์: Lab 7 MQTT IoT Control System/Lab_7_MQTT_IoT_Control_System/
- ไฟล์โค้ด: Lab_7_MQTT_IoT_Control_System.ino
- คำแนะนำ: Instruction.txt
- หัวข้อ: MQTT IoT Control System
- คะแนน: 15 คะแนน
- สรุปเนื้อหา: สื่อสารสองทิศทางกับโปรแกรม MQTTX: ส่งค่าเซนเซอร์พร้อมกันเป็น JSON และรับคำสั่งพร้อมส่งสถานะยืนยันกลับแบบไม่ซ้ำกับผู้อื่น

[LAB 8]
- โฟลเดอร์: Lab 8 Telegram Alert/Lab_8_Telegram_Alert/
- ไฟล์โค้ด: Lab_8_Telegram_Alert.ino
- คำแนะนำ: Instruction.txt
- หัวข้อ: Telegram Alert
- คะแนน: 10 คะแนน
- สรุปเนื้อหา: แจ้งเตือนข้อความเข้า Telegram เมื่อตรวจพบการกดปุ่มฉุกเฉิน (GPIO 23)

[LAB 9]
- โฟลเดอร์: Lab 9 Telegram Control/Lab_9_Telegram_Control/
- ไฟล์โค้ด: Lab_9_Telegram_Control.ino
- คำแนะนำ: Instruction.txt
- หัวข้อ: Telegram Control
- คะแนน: 10 คะแนน
- สรุปเนื้อหา: ควบคุมและอ่านสถานะ ESP32 สองทางผ่านคำสั่งแชต /led_on, /led_off, /status

[LAB 10]
- โฟลเดอร์: Lab 10 Mini IoT Project/Lab_10_Mini_IoT_Project/
- ไฟล์โค้ด: Lab_10_Mini_IoT_Project.ino
- คำแนะนำ: Instruction.txt
- หัวข้อ: Mini IoT Project
- คะแนน: 15 คะแนน
- สรุปเนื้อหา: ผสาน Web Server + MQTT (ส่ง JSON แยกตาม student_id) + Telegram Bot + Buzzer ส่งเสียงและแจ้งเตือนเมื่ออุณหภูมิเกิน 35°C

================================================================================
รวมคะแนนทั้งหมด: 100 คะแนน
================================================================================

--------------------------------------------------------------------------------
ตารางการต่อขาฮาร์ดแวร์ (GPIO Assignment Summary)
--------------------------------------------------------------------------------
+--------------------------+-----------+---------------+--------------------------------------+
| อุปกรณ์ / เซนเซอร์       | ขา ESP32  | โหมด          | Lab ที่ใช้งาน                        |
+--------------------------+-----------+---------------+--------------------------------------+
| LED                      | GPIO 2    | OUTPUT        | Lab 3, Lab 6, Lab 7, Lab 9, Lab 10   |
| DHT11 / DHT22 (Data)     | GPIO 4    | INPUT         | Lab 4, Lab 5, Lab 7, Lab 10          |
| Push Button (สวิตช์กด)   | GPIO 23   | INPUT_PULLUP  | Lab 8                                |
| Active Buzzer (ลำโพง)    | GPIO 18   | OUTPUT        | Lab 10                               |
+--------------------------+-----------+---------------+--------------------------------------+

--------------------------------------------------------------------------------
การทดสอบ MQTT ด้วยโปรแกรม MQTTX (Lab 5, Lab 6, Lab 7, Lab 10)
--------------------------------------------------------------------------------
ดาวน์โหลดโปรแกรม: https://mqttx.app/ หรือใช้งานเว็บ: https://mqttx.app/web

การตั้งค่าการเชื่อมต่อ (New Connection):
- Name: ESP32-Lab
- Host / Broker: broker.hivemq.com
- Port: 1883
- กดปุ่ม Connect

การแยก Topic เฉพาะตัวของผู้เรียน (Distinct Subscription & Publish Topics):
ในโค้ด Lab 5, 6, 7, 10 ให้ผู้เรียนแก้ไข:
const char* student_id = "65012345";  // ใส่รหัสนักศึกษาของตนเอง

หัวข้อ Topic สำหรับทดสอบ:
- Lab 5 (MQTT Publisher):
  * ส่งค่าพร้อมกัน: ส่งค่าอุณหภูมิและความชื้นพร้อมกันในรูปแบบ JSON เช่น {"temp": 28.5, "hum": 60.0}
  * Subscribe ใน MQTTX: student/<student_id>/sensor หรือ student/<student_id>/#

- Lab 6 (MQTT Subscriber):
  * บอร์ด Subscribe รอรับคำสั่งที่: student/<student_id>/led/set
  * Publish ใน MQTTX: ส่งข้อความ "ON" หรือ "OFF" ไปยัง Topic: student/<student_id>/led/set

- Lab 7 (Two-Way Control):
  * Subscribe ใน MQTTX: student/<student_id>/#
  * Publish ใน MQTTX: ส่งคำสั่ง "ON" หรือ "OFF" ไปยัง Topic: student/<student_id>/led/set
  * ดูการตอบกลับสถานะที่ Topic: student/<student_id>/led/status และค่า sensor ที่ส่งมาพร้อมกัน

- Lab 10 (Mini IoT Project):
  * ส่งค่าอุณหภูมิและความชื้นพร้อมกันในรูปแบบ JSON เช่น {"temp": 28.5, "hum": 60.0} ไปยัง Topic: student/<student_id>/sensor
  * Subscribe ใน MQTTX: student/<student_id>/# หรือ student/<student_id>/sensor

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
