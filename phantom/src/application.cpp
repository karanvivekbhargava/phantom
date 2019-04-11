#include "phantom/phantom_pch.hpp"
#include "phantom/application.hpp"
#include "phantom/inputs/linux_input.hpp"

namespace Phantom
{

    Application* Application::s_instance = nullptr;

    Application::Application()
    {
        PHTM_CORE_ASSERT(!s_instance, "Tried to launch multiple Application instances")
        s_instance = this;
        m_is_running = true;
        m_window = std::unique_ptr<Window>(Window::Create());
        m_window->SetEventCallback(BIND_EVENT_FN(Application::OnEvent));

        m_ImGuiLayer = new ImGuiLayer();
        PushOverlay(m_ImGuiLayer);
    }

    Application::~Application()
    {

    }

    void Application::OnEvent(Event &e)
    {
        EventDispatcher dispatcher(e);
        dispatcher.Dispatch<WindowCloseEvent>(BIND_EVENT_FN(Application::OnWindowClose));

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

            m_ImGuiLayer->Begin();
            for (auto& layer: m_layerstack)
            {
                layer->OnImGuiRender();
            }
            m_ImGuiLayer->End();

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
        layer->OnAttach();
    }

    void Application::PushOverlay(Layer *layer)
    {
        m_layerstack.PushOverlay(layer);
        layer->OnAttach();
    }
}
