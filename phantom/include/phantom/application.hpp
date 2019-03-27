#pragma once

#include "phantom/log.hpp"
#include "phantom/events/event.hpp"
#include "phantom/events/application_event.hpp"
#include "phantom/windows/linux_window.hpp"
#include "phantom/layers/layer_stack.hpp"

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

      private:
        bool OnWindowClose(WindowCloseEvent& e);

        std::unique_ptr<Window> m_window;
        bool m_is_running;
        LayerStack m_layerstack;
    };

    // This gets defined in the client side code
    Application* CreateApplication();
}
