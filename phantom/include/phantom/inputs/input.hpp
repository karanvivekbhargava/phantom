#pragma once

#include "phantom/phantom_pch.hpp"
#include "phantom/core.hpp"

namespace Phantom
{
    class Input
    {
    public:
        static bool IsKeyPressed(int32_t keycode)
        {
            return s_instance->IsKeyPressedImpl(keycode);
        }

        static bool IsMouseButtonPressed(int32_t button)
        {
            return s_instance->IsMouseButtonPressedImpl(button);
        }

        static std::pair<float32_t, float32_t> GetMousePosition()
        {
            return s_instance->GetMousePositionImpl();
        }

    protected:
        virtual bool IsKeyPressedImpl(int32_t keycode) = 0;
        virtual bool IsMouseButtonPressedImpl(int32_t button) = 0;
        virtual std::pair<float32_t, float32_t> GetMousePositionImpl() = 0;
    private:
        static Input* s_instance;
    };

}
