#include "controller.h"
#include <smart_device/device.h>

namespace BestSolution
{

Controller::Controller (SmartDevice::IDevice * device)
    : SmartDevice::IController  (device)
    , device                    {device}
{
}

Controller::~Controller ()
{
    device = nullptr;
}

SmartDevice::Status Controller::GetState ()
{
    const SmartDevice::Measurement v = device->GetMeasurement ();
    if (-1 == v) {
        // Restart device.
        device->SetMode (SmartDevice::Mode::Off);
        device->SetMode (SmartDevice::Mode::On);

        return SmartDevice::Status::Alarm;
    }

    return SmartDevice::Status::Success;
}

}// namespace BestSolution
