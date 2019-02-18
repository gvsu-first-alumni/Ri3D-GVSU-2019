#pragma once

#include <frc/Timer.h>

class FangvPIDController {
public:
  FangvPIDController(double outputUpperLim, double outputLowerLim, const double kp,
                      const double ki, const double kd, const double kff = 1);
  void SetOutput(double outputUpper, double outputLower);
  void SetPIDF(double kp, double ki, double kd, double kff = -1);
  double Process(double setpoint, double input);

  void ResetIAccum();
  
private:
  const double kIAccumLimit = 100; // Arbitrary

  frc::Timer m_timer;
  double m_lastTime = -1;

  double m_upperOutputLimit;
  double m_lowerOutputLimit;

  double m_kp;
  double m_ki;
  double m_kd;
  double m_kff;

  double m_iAccum;
};