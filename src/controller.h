#ifndef SMART_DEVICE_CONCRETE_CONTROLLER_H
#define SMART_DEVICE_CONCRETE_CONTROLLER_H

#include <smart_device/controller.h>
#include <smart_device/types.h>

namespace BestSolution
{

class Controller : public SmartDevice::IController
{
    public:
        Controller              (SmartDevice::IDevice *);
        ~Controller             () override;

        SmartDevice::Status GetState
                                () override;

    protected:
        SmartDevice::IDevice * device;
};

}// namespace BestSolution

#endif//SMART_DEVICE_CONCRETE_CONTROLLER_H
