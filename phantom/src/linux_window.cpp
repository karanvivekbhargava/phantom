#include "phantom/windows/linux_window.hpp"

namespace Phantom
{
    static bool s_glfw_initialized = false;

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
            PHTM_CORE_ASSERT(success, "Could not initialize GLFW!");
            s_glfw_initialized = true;
        }

        m_window = glfwCreateWindow(static_cast<int32_t>(props.width),
                                    static_cast<int32_t>(props.height),
                                    m_data.title.c_str(),
                                    nullptr,
                                    nullptr);
        glfwMakeContextCurrent(m_window);
        glfwSetWindowUserPointer(m_window, &m_data);
        SetVSync(true);
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

    bool LinuxWindow::IsVSync() const {return m_data.vsync;}
}
