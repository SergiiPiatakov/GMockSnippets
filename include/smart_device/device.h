#ifndef SMART_DEVICE_DEVICE_H
#define SMART_DEVICE_DEVICE_H

#include <smart_device/types.h>

namespace SmartDevice
{

class IDevice
{
    public:
        IDevice                             () = default;
        virtual ~IDevice                    () = default;

        virtual Measurement GetMeasurement  () = 0;
};

}// namespace SmartDevice

#endif//SMART_DEVICE_DEVICE_H
