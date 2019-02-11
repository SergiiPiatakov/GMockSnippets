#ifndef SMART_DEVICE_STUB_DEVICE_H
#define SMART_DEVICE_STUB_DEVICE_H

#include <smart_device/device.h>
#include <smart_device/types.h>

class StubDevice : public SmartDevice::IDevice
{
    public:
        StubDevice     () = default;
         ~StubDevice   () = default;

        SmartDevice::Measurement GetMeasurement () override
        {
            return -1;
        }
};

#endif//SMART_DEVICE_STUB_DEVICE_H
