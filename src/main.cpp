#include <Arduino.h>
#include "mpu.h"
#include <string>

using namespace std;

Mpu *mpu = new Mpu();

void setup() {
  Serial.begin(19200);
  mpu->Initialize();

}

void loop() {
  mpu->Calibrate();
  mpu->PrintAccelOffsets();
  delay(1000);
}