#define BLYNK_TEMPLATE_ID ""
#define BLYNK_TEMPLATE_NAME ""
#define BLYNK_AUTH_TOKEN ""

#define BLYNK_PRINT Serial

#include <Wire.h>
#include <WiFi.h>
#include <BlynkSimpleEsp32.h>

char ssid[] = "";   // ✅ Your WiFi SSID
char pass[] = "";              // ✅ Your WiFi Password

const int MPU_addr = 0x68;
int16_t AcX, AcY, AcZ;

BlynkTimer timer;

void setup() {
  Serial.begin(115200);
  Wire.begin(21, 22);  // SDA = 21, SCL = 22

  // Initialize MPU6050
  Wire.beginTransmission(MPU_addr);
  Wire.write(0x6B);
  Wire.write(0);
  Wire.endTransmission(true);

  // Connect to WiFi + Blynk
  Blynk.begin(BLYNK_AUTH_TOKEN, ssid, pass);

  // Read and send sensor data every 1 second
  timer.setInterval(1000L, sendSensorData);
}

void loop() {
  Blynk.run();
  timer.run();
}

void sendSensorData() {
  // Read MPU6050 accelerometer
  Wire.beginTransmission(MPU_addr);
  Wire.write(0x3B);
  Wire.endTransmission(false);
  Wire.requestFrom(MPU_addr, 6, true);

  AcX = Wire.read() << 8 | Wire.read();
  AcY = Wire.read() << 8 | Wire.read();
  AcZ = Wire.read() << 8 | Wire.read();

  // Calculate angles
  double angleX = atan2(AcY, sqrt(pow(AcX, 2) + pow(AcZ, 2))) * 180 / PI;
  double angleY = atan2(AcX, sqrt(pow(AcY, 2) + pow(AcZ, 2))) * 180 / PI;
  double angleZ = atan2(sqrt(pow(AcX, 2) + pow(AcY, 2)), AcZ) * 180 / PI;

  // Debugging in Serial
  Serial.print("X: "); Serial.print(angleX);
  Serial.print(" | Y: "); Serial.print(angleY);
  Serial.print(" | Z: "); Serial.println(angleZ);

  // Send to Blynk app
  Blynk.virtualWrite(V2, angleX);
  Blynk.virtualWrite(V3, angleY);
  Blynk.virtualWrite(V4, angleZ);
}
