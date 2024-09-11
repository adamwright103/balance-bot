

#include "pidcontroller.h"

PidController::PidController(std::array<double, 3> k_params) : k_params_{
    k_params}, prev_error_{0}, integral_{0}, setpoint_{0} {
  // Constructor for the PID controller
}


