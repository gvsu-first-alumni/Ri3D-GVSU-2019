#include "subsystems/CameraSubsystem.h"
#include "frc/WPILib.h"

namespace Camera
{
    CameraSubsystem::CameraSubsystem() : frc::Subsystem("CameraSubsystem")
    {
        mCamera = frc::CameraServer::GetInstance()->StartAutomaticCapture(0);
        mCameraServer = frc::CameraServer::GetInstance()->GetServer();

        mCameraServer.SetSource(mCamera);
    
    }

    void CameraSubsystem::InitDefaultCommand()
    {

    }

    void CameraSubsystem::SetExposureLow()
    {
        mCamera.SetExposureManual(LOW_EXPOSURE);
    }

    void CameraSubsystem::SetExposureHigh()
    {
        mCamera.SetExposureManual(HIGH_EXPOSURE);
    }
} // namespace CameraSubsystem
