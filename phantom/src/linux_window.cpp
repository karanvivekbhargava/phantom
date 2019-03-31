#include "phantom/windows/linux_window.hpp"

namespace Phantom
{
    static bool s_glfw_initialized = false;

    static void GLFWErrorCallback(int32_t error, const char* description)
    {
        PHTM_CORE_ERROR("GLFW Error ({0}): {1}", error, description);
    }

    Window* Window::Create(const WindowProps& props)
    {
        return new LinuxWindow(props);
    }

    LinuxWindow::LinuxWindow(const WindowProps& props)
    {
        Init(props);
    }

    LinuxWindow::~LinuxWindow() {Shutdown();}

    void LinuxWindow::Init(const WindowProps& props)
    {
        m_data.title = props.title;
        m_data.width = props.width;
        m_data.height = props.height;

        PHTM_CORE_INFO("Creating window {0} ({1}, {2})", props.title, props.width, props.height);

        if (!s_glfw_initialized)
        {
            // TODO: glfw terminate on shutdown
            int32_t success = glfwInit();
            glfwSetErrorCallback(GLFWErrorCallback);
            PHTM_CORE_ASSERT(success, "Could not initialize GLFW!");
            s_glfw_initialized = true;
        }

        m_window = glfwCreateWindow(static_cast<int32_t>(props.width),
                                    static_cast<int32_t>(props.height),
                                    m_data.title.c_str(),
                                    nullptr,
                                    nullptr);
        glfwMakeContextCurrent(m_window);
        int32_t status = gladLoadGLLoader((GLADloadproc)glfwGetProcAddress);
        PHTM_CORE_ASSERT(status, "Could not initialize Glad!");
        glfwSetWindowUserPointer(m_window, &m_data);
        SetVSync(true);

        // Set glfw callbacks
        glfwSetWindowSizeCallback(m_window, [](GLFWwindow* window, int32_t width, int32_t height)
        {
            WindowData& data = *(WindowData*)glfwGetWindowUserPointer(window);
            data.width = static_cast<uint32_t>(width);
            data.height = static_cast<uint32_t>(height);
            WindowResizeEvent event(data.width, data.height);
            data.EventCallback(event);
        });

        glfwSetWindowCloseCallback(m_window, [](GLFWwindow* window)
        {
            WindowData& data = *(WindowData*)glfwGetWindowUserPointer(window);
            WindowCloseEvent event;
            data.EventCallback(event);
        });

        glfwSetKeyCallback(m_window, [](GLFWwindow* window, int32_t key, int32_t scancode, int32_t action, int32_t mods)
        {
            WindowData& data = *(WindowData*)glfwGetWindowUserPointer(window);
            switch(action)
            {
                case GLFW_PRESS:
                {
                    KeyPressedEvent event(key, 0);
                    data.EventCallback(event);
                    break;
                }
                case GLFW_RELEASE:
                {
                    KeyReleasedEvent event(key);
                    data.EventCallback(event);
                    break;
                }
                case GLFW_REPEAT:
                {
                    KeyPressedEvent event(key, 1);
                    data.EventCallback(event);
                    break;
                }
            }
        });

        glfwSetCharCallback(m_window, [](GLFWwindow* window, uint32_t keycode)
        {
            WindowData& data = *(WindowData*)glfwGetWindowUserPointer(window);
            KeyTypedEvent event(static_cast<int32_t>(keycode));
            data.EventCallback(event);
        });

        glfwSetMouseButtonCallback(m_window, [](GLFWwindow* window, int32_t button, int32_t action, int32_t mods)
        {
            WindowData& data = *(WindowData*)glfwGetWindowUserPointer(window);
            switch(action)
            {
                case GLFW_PRESS:
                {
                    MouseButtonPressedEvent event(button);
                    data.EventCallback(event);
                    break;
                }
                case GLFW_RELEASE:
                {
                    MouseButtonReleasedEvent event(button);
                    data.EventCallback(event);
                    break;
                }
            }
        });

        glfwSetScrollCallback(m_window, [](GLFWwindow* window, float64_t x_offset, float64_t y_offset)
        {
            WindowData& data = *(WindowData*)glfwGetWindowUserPointer(window);
            MouseScrolledEvent event(static_cast<float32_t>(x_offset), static_cast<float32_t>(y_offset));
            data.EventCallback(event);
        });

        glfwSetCursorPosCallback(m_window, [](GLFWwindow* window, float64_t x_pos, float64_t y_pos)
        {
            WindowData& data = *(WindowData*)glfwGetWindowUserPointer(window);
            MouseMovedEvent event(static_cast<float32_t>(x_pos), static_cast<float32_t>(y_pos));
            data.EventCallback(event);
        });
    }

    void LinuxWindow::Shutdown() {glfwDestroyWindow(m_window);}

    void LinuxWindow::OnUpdate()
    {
        glfwPollEvents();
        glfwSwapBuffers(m_window);
    }

    void LinuxWindow::SetVSync(bool enabled)
    {
        if (enabled)
            glfwSwapInterval(1);
        else
            glfwSwapInterval(0);
        m_data.vsync = enabled;
    }

    bool LinuxWindow::IsVSync() const
    {
        return m_data.vsync;
    }
}
