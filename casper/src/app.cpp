#include "phantom/phantom.hpp"

class ExampleLayer : public Phantom::Layer
{
  public:
    ExampleLayer() : Layer("Example")
    {

    }

    void OnUpdate() override
    {
        if (Phantom::Input::IsKeyPressed(PHTM_KEY_TAB))
        {
            PHTM_CORE_TRACE("Tab is pressed!");
        }
    }

    void OnEvent(Phantom::Event& event) override
    {
//        PHTM_CLIENT_TRACE("{0}", event);
    }
};

class Casper : public Phantom::Application
{
public:
    Casper()
    {
        this->PushLayer(new ExampleLayer);
        this->PushOverlay(new Phantom::ImGuiLayer());
    }

    ~Casper()
    {

    }
};

Phantom::Application* Phantom::CreateApplication()
{
    return new Casper();
}
