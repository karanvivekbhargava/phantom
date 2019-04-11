#include "phantom/phantom.hpp"
#include "imgui.h"
#include <glm/vec3.hpp> // glm::vec3
#include <glm/vec4.hpp> // glm::vec4
#include <glm/mat4x4.hpp> // glm::mat4
#include <glm/ext/matrix_transform.hpp> // glm::translate, glm::rotate, glm::scale
#include <glm/ext/matrix_clip_space.hpp> // glm::perspective
//#include <glm/ext/constants.hpp> // glm::pi

glm::mat4 camera(float Translate, glm::vec2 const& Rotate)
{
    glm::mat4 Projection = glm::perspective(glm::pi<float>() * 0.25f, 4.0f / 3.0f, 0.1f, 100.f);
    glm::mat4 View = glm::translate(glm::mat4(1.0f), glm::vec3(0.0f, 0.0f, -Translate));
    View = glm::rotate(View, Rotate.y, glm::vec3(-1.0f, 0.0f, 0.0f));
    View = glm::rotate(View, Rotate.x, glm::vec3(0.0f, 1.0f, 0.0f));
    glm::mat4 Model = glm::scale(glm::mat4(1.0f), glm::vec3(0.5f));
    return Projection * View * Model;
}

class ExampleLayer : public Phantom::Layer
{
  public:
    ExampleLayer() : Layer("Example")
    {
        auto cam = camera(5.0f, {0.5f, 0.6f});
    }

    virtual void OnImGuiRender() override
    {
        ImGui::Begin("Test");
        ImGui::Text("Hello World");
        ImGui::End();
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
        PushLayer(new ExampleLayer);
        PushOverlay(new Phantom::ImGuiLayer());
    }

    ~Casper()
    {

    }
};

Phantom::Application* Phantom::CreateApplication()
{
    return new Casper();
}
