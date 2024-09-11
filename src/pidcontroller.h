#ifndef BALANCE_BOT_SRC_PIDCONTROLLER_H_
#define BALANCE_BOT_SRC_PIDCONTROLLER_H_

#include <ArduinoSTL.h>
#include <array>

class PidController {
 private:
  std::array<double, 3> k_params_;

  double *input_;
  double *output_;
  double *set_point_;

  unsigned long prev_time_;
  unsigned int sample_time_;
  int last_theta_;

 public:
  PidController(std::array<double, 3> &k_params);

};

#endif //BALANCE_BOT_SRC_PIDCONTROLLER_H_
