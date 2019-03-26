#pragma once

#include "phantom/events/event.hpp"
#include "phantom/log.hpp"
#include "phantom/events/application_event.hpp"
#include "phantom/windows/linux_window.hpp"

namespace Phantom
{
    class Application
    {
      public:
        Application();
        virtual ~Application();
        void Run();
        void OnEvent(Event& e);

      private:
        bool OnWindowClose(WindowCloseEvent& e);

        bool m_is_running;
        std::unique_ptr<Window> m_window;
    };

    // This gets defined in the client side code
    Application* CreateApplication();
}
