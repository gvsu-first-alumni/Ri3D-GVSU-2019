#include "subsystems/CameraSubsystem.h"
#include "frc/WPILib.h"
#include "RobotMap.h"

namespace Camera
{
    CameraSubsystem::CameraSubsystem() : frc::Subsystem("CameraSubsystem")
    {
        m_clawCamera = frc::CameraServer::GetInstance()->StartAutomaticCapture(0);
        m_clawCamera.SetResolution(kResolutionX, kResolutionY);
        m_clawCamera.SetFPS(kFPSLimit);
        m_lineCamera = frc::CameraServer::GetInstance()->StartAutomaticCapture(1);
        m_lineCamera.SetResolution(kResolutionX, kResolutionY);
        m_lineCamera.SetFPS(kFPSLimit);
        m_cameraServer = frc::CameraServer::GetInstance()->GetServer();

        m_clawCamera.SetConnectionStrategy(cs::VideoSource::ConnectionStrategy::kConnectionKeepOpen);
        m_lineCamera.SetConnectionStrategy(cs::VideoSource::ConnectionStrategy::kConnectionKeepOpen);

        m_cameraServer.SetSource(m_clawCamera);
    }

    void CameraSubsystem::InitDefaultCommand()
    {

    }

    void CameraSubsystem::SetExposureLow()
    {
        m_lineCamera.SetExposureManual(LOW_EXPOSURE);
    }

    void CameraSubsystem::SetExposureHigh()
    {
        m_lineCamera.SetExposureManual(HIGH_EXPOSURE);
    }

    void CameraSubsystem::UseClawCamera()
    {
        m_cameraServer.SetSource(m_clawCamera);
    }

    void CameraSubsystem::UseLineCamera()
    {
        m_cameraServer.SetSource(m_lineCamera);
    }
} // namespace CameraSubsystem
