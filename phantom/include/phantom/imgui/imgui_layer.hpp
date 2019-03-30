#pragma once


#include "phantom/phantom_pch.hpp"
#include "phantom/layers/layer.hpp"

//#include "imgui.h"
#include "platform/opengl/imgui_opengl3_renderer.h"
#include "phantom/application.hpp"
#include "GLFW/glfw3.h"

namespace Phantom
{
    class ImGuiLayer : public Layer
    {
    public:
        ImGuiLayer();
        ~ImGuiLayer() override;
        void OnAttach() override;
        void OnDetach() override;
        void OnUpdate() override;
        void OnEvent(Event& event) override;
    private:
        float32_t m_time = 0.0f;
    };
}
