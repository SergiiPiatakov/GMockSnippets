#ifndef SMART_DEVICE_TYPES_H
#define SMART_DEVICE_TYPES_H

namespace SmartDevice
{

using Measurement = int;

enum class Status
{
    Success,
    Alarm
};

enum class Mode
{
    On,
    Off
};

}// namespace SmartDevice

#endif//SMART_DEVICE_TYPES_H
