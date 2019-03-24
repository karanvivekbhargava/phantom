#include "phantom/application.hpp"

namespace Phantom
{
    Application::Application()
    {
        m_is_running = true;
        m_window = std::unique_ptr<Window>(Window::Create());
    }

    Application::~Application()
    {

    }

    void Application::Run()
    {
//        PHTM_CORE_TRACE("Welcome to Phantom Engine!");
//        WindowResizeEvent e(1280, 720);
//        PHTM_CORE_TRACE(e);
        while(m_is_running)
        {
            m_window->OnUpdate();
        }
    }
}
