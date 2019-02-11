#ifndef SMART_DEVICE_MOCK_DEVICE_H
#define SMART_DEVICE_MOCK_DEVICE_H

#include <smart_device/device.h>
#include <smart_device/types.h>
#include <gmock/gmock.h>

class MockDevice : public SmartDevice::IDevice
{
    public:
        MockDevice     () = default;
         ~MockDevice   () = default;

        MOCK_METHOD0(GetMeasurement, SmartDevice::Measurement());
};

#endif//SMART_DEVICE_MOCK_DEVICE_H
