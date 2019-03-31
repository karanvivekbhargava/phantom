#include "phantom/inputs/linux_input.hpp"

namespace Phantom
{

Input* Input::s_instance = new LinuxInput();

bool LinuxInput::IsKeyPressedImpl(int32_t keycode)
{
    auto window = static_cast<GLFWwindow*>(Application::Get().GetWindow().GetNativeWindow());
    auto state = glfwGetKey(window, keycode);
    return state == GLFW_PRESS || state == GLFW_REPEAT;
}

bool LinuxInput::IsMouseButtonPressedImpl(int32_t button)
{
    auto window = static_cast<GLFWwindow*>(Application::Get().GetWindow().GetNativeWindow());
    auto state = glfwGetMouseButton(window, button);
    return state == GLFW_PRESS;
}

std::pair<float32_t, float32_t> LinuxInput::GetMousePositionImpl()
{
    auto window = static_cast<GLFWwindow*>(Application::Get().GetWindow().GetNativeWindow());
    float64_t xpos, ypos;
    glfwGetCursorPos(window, &xpos, &ypos);
    return std::make_pair(static_cast<float32_t>(xpos), static_cast<float32_t>(ypos));
}

}
