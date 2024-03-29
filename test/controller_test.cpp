#include <gtest/gtest.h>
#include "controller.h"
#include "device_mock.h"

using ::testing::Return;
using ::testing::InSequence;
using ::testing::_;

class ControllerTest : public ::testing::Test
{
    public:
        ControllerTest  () = default;
        ~ControllerTest () = default;

        void SetUp () override
        {
            device     = new MockDevice ();
            controller = new BestSolution::Controller (device);
        }

        void TearDown () override
        {
            delete controller;
            delete device;
        }

    protected:
        SmartDevice::IDevice     * device       {nullptr};
        SmartDevice::IController * controller   {nullptr};
};

TEST_F (ControllerTest, CreateController)
{
    SmartDevice::IController * controller = new BestSolution::Controller (nullptr);

    delete controller;
}

TEST_F (ControllerTest, GetState_Alarm)
{
    // Arrange.
    InSequence s;   // We worry about the sequence!

    EXPECT_CALL (* (static_cast <MockDevice *> (device) ), GetMeasurement () )
                .WillOnce (Return (-1) );
    EXPECT_CALL (* (static_cast <MockDevice *> (device) ), SetMode (SmartDevice::Mode::Off) )
                .Times (1);
    EXPECT_CALL (* (static_cast <MockDevice *> (device) ), SetMode (SmartDevice::Mode::On) )
                .Times (1);
    const SmartDevice::Status etalon {SmartDevice::Status::Alarm};

    // Act.
    const SmartDevice::Status test = controller->GetState ();

    // Assert.
    EXPECT_EQ (etalon, test);
}

TEST_F (ControllerTest, GetState_Success)
{
    // Arrange.
    EXPECT_CALL (* (static_cast <MockDevice *> (device) ), GetMeasurement () )
                .WillOnce (Return (+1) );
    EXPECT_CALL (* (static_cast <MockDevice *> (device) ), SetMode (_) )
                .Times (0);
    const SmartDevice::Status etalon {SmartDevice::Status::Success};

    // Act.
    const SmartDevice::Status test = controller->GetState ();

    // Assert.
    EXPECT_EQ (etalon, test);
}
