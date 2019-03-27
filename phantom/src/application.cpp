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

        // We need to go backwards through the layers to handle events
        for (auto it = m_layerstack.end(); it != m_layerstack.begin(); )
        {
            (*--it)->OnEvent(e);
            if (e.handled)
                break;
        }
    }

    void Application::Run()
    {
        while(m_is_running)
        {
            glClear(GL_COLOR_BUFFER_BIT);
            glClearColor(1, 0, 1, 1);
            // Update the layers
            for (auto& layer: m_layerstack)
            {
                layer->OnUpdate();
            }
            // Update the window
            m_window->OnUpdate();
        }
    }

    bool Application::OnWindowClose(WindowCloseEvent& e)
    {
        m_is_running = false;
        return true;
    }

    void Application::PushLayer(Layer *layer)
    {
        m_layerstack.PushLayer(layer);
    }

    void Application::PushOverlay(Layer *layer)
    {
        m_layerstack.PushOverlay(layer);
    }
}
