#include <Adafruit_MPU6050.h>
#include <Adafruit_Sensor.h>
#include <Wire.h>

Adafruit_MPU6050 mpu;

/* ========= TUNABLE PARAMETERS ========= */
#define UP_ANGLE_DEG       70.0    // Curl completed (near vertical)
#define DOWN_ANGLE_DEG     25.0    // Arm returned down
#define HOLD_TIME_MS      150      // Angle must stay high this long
#define LOOP_DELAY_MS     20
/* ===================================== */

bool armUp = false;
unsigned long aboveThresholdTime = 0;

void setup() {
  Serial.begin(115200);
  delay(100);

  Serial.println("Finding MPU6050 chip...");

  if (!mpu.begin(0x69)) {
    Serial.println("Failed at 0x69, trying 0x68...");
    if (!mpu.begin(0x68)) {
      Serial.println("MPU6050 not found!");
      while (1) delay(10);
    }
  }

  Serial.println("MPU6050 Found!");

  mpu.setAccelerometerRange(MPU6050_RANGE_8_G);
  mpu.setGyroRange(MPU6050_RANGE_500_DEG);
  mpu.setFilterBandwidth(MPU6050_BAND_21_HZ);

  Serial.println("Hold arm DOWN...");
  delay(2000);
  Serial.println("Ready!");
}

void loop() {
  sensors_event_t a, g, temp;
  mpu.getEvent(&a, &g, &temp);

  float ax = a.acceleration.x;
  float ay = a.acceleration.y;

  // ---- Compute tilt angle (0° = down, 90° = up) ----
  float angleDeg = atan2(ay, ax) * 180.0 / PI;
  if (angleDeg < 0) angleDeg = 0;   // clamp, we only care about 0–90°

  /* ============ STATE MACHINE ============ */

  // ---- Detect curl completion (stable hold at top) ----
  if (!armUp && angleDeg > UP_ANGLE_DEG && angleDeg < 120) {
    if (aboveThresholdTime == 0) {
      aboveThresholdTime = millis();   // start timing
    }
    else if (millis() - aboveThresholdTime >= HOLD_TIME_MS) {
      Serial.println("JUMP");
      armUp = true;
      aboveThresholdTime = 0;
    }
  }
  else {
    aboveThresholdTime = 0;  // reset if angle drops
  }

  // ---- Detect arm returned to rest ----
  if (armUp && angleDeg < DOWN_ANGLE_DEG) {
    armUp = false;
  }

  /* ====================================== */

  delay(LOOP_DELAY_MS);
}