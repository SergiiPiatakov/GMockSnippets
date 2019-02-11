#ifndef SMART_DEVICE_CONTROLLER_H
#define SMART_DEVICE_CONTROLLER_H

#include <smart_device/types.h>

namespace SmartDevice
{

class IDevice;

class IController
{
    public:
        IController             (IDevice *)
        {
        }

        virtual ~IController    () = default;

        virtual Status GetState () = 0;
};

}// namespace SmartDevice

#endif//SMART_DEVICE_CONTROLLER_H
