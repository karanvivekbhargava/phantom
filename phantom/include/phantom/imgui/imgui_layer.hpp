#pragma once


#include "phantom/phantom_pch.hpp"
#include "phantom/layers/layer.hpp"
#include "phantom/events/event.hpp"
#include "phantom/events/key_event.hpp"
#include "phantom/events/mouse_event.hpp"
#include "phantom/events/application_event.hpp"
//#include "imgui.h"
#include "platform/opengl/imgui_opengl3_renderer.h"
#include "phantom/application.hpp"
#include "glad/glad.h"
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
        bool MouseMovedCallback(MouseMovedEvent& e);
        bool MouseScrolledCallback(MouseScrolledEvent& e);
        bool MouseButtonPressedCallback(MouseButtonPressedEvent& e);
        bool MouseButtonReleasedCallback(MouseButtonReleasedEvent& e);
        bool KeyPressedCallback(KeyPressedEvent& e);
        bool KeyTypedCallback(KeyTypedEvent& e);
        bool KeyReleasedCallback(KeyReleasedEvent& e);
        bool WindowResizeCallback(WindowResizeEvent& e);
    private:
        float32_t m_time = 0.0f;
    };
}
