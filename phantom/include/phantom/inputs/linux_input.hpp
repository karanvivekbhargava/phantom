#pragma once

#include "GLFW/glfw3.h"
#include "phantom/application.hpp"
#include "phantom/inputs/input.hpp"

namespace Phantom
{

    class LinuxInput : public Input
    {
    protected:
        virtual bool IsKeyPressedImpl(int32_t keycode) override;
        virtual bool IsMouseButtonPressedImpl(int32_t button) override;
        virtual std::pair<float32_t, float32_t> GetMousePositionImpl() override;
    };
}
