#pragma once

#include "glad/glad.h"
#include "GLFW/glfw3.h"
#include "phantom/windows/window.hpp"

#include "phantom/events/application_event.hpp"
#include "phantom/events/key_event.hpp"
#include "phantom/events/mouse_event.hpp"

struct GLFWwindow;

namespace Phantom
{
    class LinuxWindow : public Window
    {
      public:
        LinuxWindow(const WindowProps& props);
        virtual ~LinuxWindow() override;

        void OnUpdate() override;

        inline uint32_t GetWidth() const override {return m_data.width;}
        inline uint32_t GetHeight() const override {return m_data.height;}

        // Window attributes
        void SetEventCallback(const EventCallbackFn& callback) override {m_data.EventCallback = callback;}
        void SetVSync(bool enabled) override;
        bool IsVSync() const override;

        inline virtual void* GetNativeWindow() const override { return m_window; }
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
