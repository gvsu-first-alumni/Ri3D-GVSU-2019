#include "subsystems\VisionSystem.h"
#include "cscore.h"
#include <frc/WPILib.h>

namespace Camera{
    AligmentCamera::AligmentCamera() : frc::Subsystem("AligmentCamera"){
        //camera = frc::CameraServer::GetInstance()->StartAutomaticCapture();
        //camera.SetResolution(640,480);
        //cameraSink = frc::CameraServer::GetInstance()->GetVideo();
    }
    
    void AligmentCamera::runThread(){
        //std::thread(&AligmentCamera::findDistance, this);
    }

    void AligmentCamera::findDistance(){
        while (true){
            cameraSink.GrabFrame(sourceFrame);
            processPipline.Process(sourceFrame);
            distance = processPipline.getDistance();
        }
    }

    int AligmentCamera::getDistance(){
        m_lock.lock();
        int currDistance = distance;
        m_lock.unlock();
        return currDistance;
    }
}

