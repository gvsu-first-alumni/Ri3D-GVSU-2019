#pragma once

#include <frc/commands/Subsystem.h>
#include "cscore.h"

namespace Camera
{
class CameraSubsystem : public frc::Subsystem
{
  public:
    CameraSubsystem();
    void InitDefaultCommand() override;
    void SetExposureLow();
    void SetExposureHigh();
    void UseClawCamera();
    void UseLineCamera();

  private:
    static const int HIGH_EXPOSURE = 13;
    static const int LOW_EXPOSURE = 0;

    private:
        cs::UsbCamera m_clawCamera;
        cs::UsbCamera m_lineCamera;
        cs::VideoSink m_cameraServer;
};
} // namespace CameraSubsystem
