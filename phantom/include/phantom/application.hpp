#pragma once

#include "phantom_pch.hpp"
#include "phantom/log.hpp"
#include "phantom/events/event.hpp"
#include "phantom/events/application_event.hpp"
#include "phantom/windows/linux_window.hpp"
#include "phantom/layers/layer_stack.hpp"
#include "phantom/imgui/imgui_layer.hpp"

namespace Phantom
{
    class Application
    {
      public:
        Application();
        virtual ~Application();

        void Run();

        void OnEvent(Event& e);

        void PushLayer(Layer* layer);
        void PushOverlay(Layer* layer);

        inline static Application& Get() { return *s_instance; }

        inline Window& GetWindow() { return *m_window; }

      private:
        bool OnWindowClose(WindowCloseEvent& e);

        std::unique_ptr<Window> m_window;
        ImGuiLayer* m_ImGuiLayer;
        bool m_is_running;
        LayerStack m_layerstack;

        static Application* s_instance;
    };

    // This gets defined in the client side code
    Application* CreateApplication();
}
