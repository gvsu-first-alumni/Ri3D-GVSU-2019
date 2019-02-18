#pragma once

#include <frc/commands/Subsystem.h>
#include "cscore.h"
#include <opencv2/imgproc/imgproc.hpp>
#include <opencv2/core/core.hpp>
#include <mutex>

#include "libraries/GroundTapePipline.h"

namespace Camera{
    class AligmentCamera : public frc::Subsystem{
    public:
        AligmentCamera();
        void InitDefaultCommand() override{}
        void runThread();
        int getDistance();
    private:
        cs::UsbCamera camera;
        cs::CvSink cameraSink;
        cv::Mat sourceFrame;
        grip::GroundTapePipline processPipline;
        int distance{0};
        std::mutex m_lock;

        void findDistance();
    };
}
