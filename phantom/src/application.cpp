#include "phantom/application.hpp"
#define BIND_EVENT_FN(x) std::bind(&x, this, std::placeholders::_1)
namespace Phantom
{
    Application::Application()
    {
        m_is_running = true;
        m_window = std::unique_ptr<Window>(Window::Create());
        m_window->SetEventCallback(BIND_EVENT_FN(Application::OnEvent));
    }

    Application::~Application()
    {

    }

    void Application::OnEvent(Event &e)
    {
        EventDispatcher dispatcher(e);
        dispatcher.Dispatch<WindowCloseEvent>(BIND_EVENT_FN(Application::OnWindowClose));
        PHTM_CORE_TRACE("{0}", e);
    }

    void Application::Run()
    {
        while(m_is_running)
        {
            glClear(GL_COLOR_BUFFER_BIT);
            glClearColor(1, 0, 1, 1);
            m_window->OnUpdate();
        }
    }

    bool Application::OnWindowClose(WindowCloseEvent& e)
    {
        m_is_running = false;
        return true;
    }
}
