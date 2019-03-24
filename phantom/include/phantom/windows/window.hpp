#pragma once

#include "phantom/phantom_pch.hpp"
#include "phantom/core.hpp"
#include "phantom/log.hpp"
#include "phantom/events/event.hpp"

namespace Phantom
{
    struct WindowProps
    {
        std::string title;
        uint32_t width, height;

        WindowProps(const std::string& title = "Phantom_Engine",
                    uint32_t width = 1280,
                    uint32_t height = 720)
            : title(title), width(width), height(height)
        {}
    };

    /**
     * @brief The Window class
     */
    class Window
    {
      public:
        using EventCallbackFn = std::function<void(Event&)>;

        virtual ~Window() {}

        virtual void OnUpdate()=0;

        virtual uint32_t GetWidth() const = 0;
        virtual uint32_t GetHeight() const = 0;

        // Window attributes
        virtual void SetEventCallback(const EventCallbackFn& callback) = 0;
        virtual void SetVSync(bool enabled) = 0;
        virtual bool IsVSync() const = 0;

        static Window* Create(const WindowProps& props = WindowProps());


    };

}
