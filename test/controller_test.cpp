#include <gtest/gtest.h>
#include "controller.h"


class ControllerTest : public ::testing::Test
{
    public:
        ControllerTest  () = default;
        ~ControllerTest () = default;
};

TEST_F (ControllerTest, CreateController)
{
    SmartDevice::IController * controller = new BestSolution::Controller (nullptr);

    delete controller;
}
