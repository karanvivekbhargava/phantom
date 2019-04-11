#pragma once

#include "phantom/layers/layer.hpp"
#include "phantom/events/key_event.hpp"
#include "phantom/events/mouse_event.hpp"
#include "phantom/events/application_event.hpp"

#include <GLFW/glfw3.h>

//#define IMGUI_IMPL_API

namespace Phantom
{
    class ImGuiLayer : public Layer
    {
    public:
        ImGuiLayer();
        ~ImGuiLayer() override;
        virtual void OnAttach() override;
        virtual void OnDetach() override;
        virtual void OnImGuiRender() override;

        void Begin();
        void End();
    private:
        float32_t m_time = 0.0f;
    };
}
