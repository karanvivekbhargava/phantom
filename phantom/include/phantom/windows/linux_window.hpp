#pragma once

#include "GLFW/glfw3.h"
#include "phantom/windows/window.hpp"

namespace Phantom
{
    class LinuxWindow : public Window
    {
      public:
        LinuxWindow(const WindowProps& props);
        virtual ~LinuxWindow();

        void OnUpdate() override;

        inline uint32_t GetWidth() const override {return m_data.width;}
        inline uint32_t GetHeight() const override {return m_data.height;}

        // Window attributes
        void SetEventCallback(const EventCallbackFn& callback) override {m_data.EventCallback = callback;}
        void SetVSync(bool enabled) override;
        bool IsVSync() const override;
      private:
        void Init(const WindowProps& props);
        void Shutdown();
      private:
        GLFWwindow* m_window;

        struct WindowData : public WindowProps
        {
            bool vsync;
            EventCallbackFn EventCallback;
        };

        WindowData m_data;

    };

}
