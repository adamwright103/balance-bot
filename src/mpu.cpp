#include "mpu.h"
#include <ArduinoSTL.h>
#include <array>
#include <Wire.h>

using namespace std;

const int MPU_ADDRESS = 0x68;

Mpu::Mpu() : accel_data_{0, 0, 0}, accel_offsets_{-0.01, -0.01, 0.11} {
  // offsets based on previous calibration
}

bool Mpu::Initialize() {
  // Initialize the MPU6050
  Wire.begin();
  Wire.beginTransmission(MPU_ADDRESS);
  Wire.write(0x6B);  // PWR_MGMT_1 register
  Wire.write(0);     // set to zero (wakes up the MPU-6050)

  // attempt to end transmission
  if (Wire.endTransmission(true)) {
    return false; // transmission fails when != 0
  }

  return true;
}

std::array<double, 3> Mpu::ReadUncalibratedAccelData() {
  /** Read the accelerometer data, this function does
   * not account for offsets, so use with caution
   * */

  // begin transmission
  Wire.beginTransmission(MPU_ADDRESS);

  /** registers to read from:
   *  0x3B (ACCEL_XOUT_H) + 0x3C (ACCEL_XOUT_L)
   *  0x3D (ACCEL_YOUT_H) + 0x3E (ACCEL_YOUT_L)
   *  0x3F (ACCEL_ZOUT_H) + 0x40 (ACCEL_ZOUT_L)
   * */
  Wire.write(0x3B);  // start with 0x3B
  Wire.endTransmission(false);


  // request from 6 registers (3 axes * 2 bytes each)
  Wire.requestFrom(MPU_ADDRESS, 6, true);
  double accel_x = Wire.read() << 8 | Wire.read();
  double accel_y = Wire.read() << 8 | Wire.read();
  double accel_z = Wire.read() << 8 | Wire.read();

  // convert the raw data to g
  return {accel_x / 16384.0, accel_y / 16384.0, accel_z / 16384.0};
}

void Mpu::Calibrate() {
  // Calibrate the accelerometer by taking avg of 50 samples
  array<double, 3> accel_sum{0, 0, 0};
  array<double, 3> collected_accel_data = ReadUncalibratedAccelData();
  for (int i = 0; i < 49; i++) {
    accel_sum[0] += collected_accel_data[0];
    accel_sum[1] += collected_accel_data[1];

    // z axis should be 1g when flat
    accel_sum[2] += (1 - collected_accel_data[2]);

    collected_accel_data = ReadUncalibratedAccelData();
    delay(10);
  }

  accel_offsets_[0] = accel_sum[0] / 50.0;
  accel_offsets_[1] = accel_sum[1] / 50.0;
  accel_offsets_[2] = accel_sum[2] / 50.0;
}

void Mpu::PrintAccelData() const {
  // Print the accelerometer data
  Serial.print("X: ");
  Serial.print(accel_data_[0]);

  Serial.print(" Y: ");
  Serial.print(accel_data_[1]);

  Serial.print(" Z: ");
  Serial.println(accel_data_[2]);

  Serial.println();
}

void Mpu::PrintAccelOffsets() const {
  // Print the accelerometer offsets
  Serial.print("X: ");
  Serial.print(accel_offsets_[0]);

  Serial.print(" Y: ");
  Serial.print(accel_offsets_[1]);

  Serial.print(" Z: ");
  Serial.println(accel_offsets_[2]);

  Serial.println();
}

array<double, 3> Mpu::GetAccelData() const { return accel_data_; }