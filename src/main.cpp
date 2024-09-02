#include <Arduino.h>
#include "mpu.h"
#include <string>

using namespace std;

Mpu *mpu = new Mpu();
int pitch, roll;
const char *pitch_zero, *roll_zero;

void setup() {
  Serial.begin(19200);
  while (!mpu->Initialize()) {
    Serial.println("MPU6050 not found. Please check wiring.");
    delay(5000);
  }

}

void loop() {
  mpu->UpdateAccelData();
  pitch = int(mpu->CalculatePitch());
  roll = int(mpu->CalculateRoll());
  pitch_zero = pitch < 10 && pitch > -10 ? "0" : "";
  roll_zero = roll < 10 && roll > -10 ? "0" : "";

  Serial.println("pitch | roll");
  Serial.print(" ");
  Serial.print(pitch_zero);
  Serial.print(pitch);
  Serial.print("   |  ");
  Serial.print(roll_zero);
  Serial.println(roll);

  delay(500);
}
