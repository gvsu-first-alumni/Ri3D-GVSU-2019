#include "libraries/FangvPIDController.h"

FangvPIDController::FangvPIDController(double outputUpperLim, double outputLowerLim,
  const double kp, const double ki, const double kd, const double kff) {
  this->m_kp = kp;
  this->m_ki = ki;
  this->m_kd = kd;
  this->m_kff = kff;

  this->m_upperOutputLimit = outputUpperLim;
  this->m_lowerOutputLimit = outputLowerLim;

  this->m_lastTime = m_timer.GetFPGATimestamp();
}

void FangvPIDController::SetOutput(double outputUpper, double outputLower) {
  this->m_upperOutputLimit = outputUpper;
  this->m_lowerOutputLimit = outputLower;
}

void FangvPIDController::SetPIDF(double kp, double ki, double kd, double kff) {
  this->m_kp = kp;
  this->m_ki = ki;
  this->m_kd = kd;
  this->m_kff = kff;
}

double FangvPIDController::Process(double setpoint, double input) {
  double dt = m_timer.GetFPGATimestamp() - m_lastTime;
  double error = setpoint - input;

  double p = m_kp * error;

  // Integral Accumulation limits
  m_iAccum += error * dt;
  if (m_iAccum > kIAccumLimit) m_iAccum = kIAccumLimit;
  else if (-m_iAccum > kIAccumLimit) m_iAccum = -kIAccumLimit;
  double i = m_ki * m_iAccum;

  double d = m_kd * error / dt;
  
  // "Ideal" PID Algorithm with velocity damping instead of adding
  double ret = p + i - d;
  if (ret > m_upperOutputLimit) return m_upperOutputLimit;
  else if (ret < m_lowerOutputLimit) return m_lowerOutputLimit;
  else return ret;
}

void FangvPIDController::ResetIAccum() {
  m_iAccum = 0;
}