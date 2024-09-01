#ifndef BALANCE_BOT_SRC_MPU_H_
#define BALANCE_BOT_SRC_MPU_H_

#include <ArduinoSTL.h>
#include <array>

class Mpu {
 private:
  std::array<double, 3> accel_data_;
  std::array<double, 3> accel_offsets_;

  std::array<double, 3> ReadUncalibratedAccelData();

 public:
  Mpu();
  bool Initialize();

  void Calibrate();
  void PrintAccelData() const;
  void PrintAccelOffsets() const;
  std::array<double, 3> GetAccelData() const;
};

#endif //BALANCE_BOT_SRC_MPU_H_
