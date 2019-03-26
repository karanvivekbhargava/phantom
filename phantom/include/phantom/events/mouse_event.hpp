#pragma once

#include "phantom/phantom_pch.hpp"
#include "event.hpp"
#include "phantom/core.hpp"

namespace Phantom
{
    /**
     * @brief The MouseMovedEvent class
     * @details This class stores the position of the mouse in x,y
     */
    class MouseMovedEvent : public Event
    {
      public:
        MouseMovedEvent(float32_t x, float32_t y) : m_x(x), m_y(y) {}
        inline float32_t GetX() const {return m_x;}
        inline float32_t GetY() const {return m_y;}
        std::string ToString() const override
        {
            std::stringstream ss;
            ss << "MouseMovedEvent: (" << m_x << ", " << m_y << ")";
            return ss.str();
        }
        EVENT_CLASS_TYPE(MouseMoved)
        EVENT_CLASS_CATEGORY(EventCategoryMouse | EventCategoryInput)
      private:
        float32_t m_x, m_y;
    };

    /**
     * @brief The MouseScrolledEvent class
     * @details This class stores the offsets in x and y for the scrolling of
     * the mouse
     */
    class MouseScrolledEvent : public Event
    {
      public:
        MouseScrolledEvent(float32_t offset_x, float32_t offset_y)
            : m_offset_x(offset_x), m_offset_y(offset_y) {}
        inline float32_t GetXOffset() const {return m_offset_x;}
        inline float32_t GetYOffset() const {return m_offset_y;}
        std::string ToString() const override
        {
            std::stringstream ss;
            ss << "MouseScrolledEvent: (" << m_offset_x << ", " << m_offset_y << ")";
            return ss.str();
        }
        EVENT_CLASS_TYPE(MouseScrolled)
        EVENT_CLASS_CATEGORY(EventCategoryMouse | EventCategoryInput)
      private:
        float32_t m_offset_x, m_offset_y;
    };

    /**
     * @brief The MouseButtonEvent class
     * @details This class is supposed to be abstract. This cannot be constructed
     * without a derived class since the constructor is protected.
     */
    class MouseButtonEvent : public Event
    {
      public:
        inline int32_t GetMouseButton() const {return m_button;}
        EVENT_CLASS_CATEGORY(EventCategoryMouse | EventCategoryInput)
      protected:
        MouseButtonEvent(int32_t button) : m_button(button) {}
        int32_t m_button;
    };

    /**
     * @brief The MouseButtonPressedEvent class
     * @details This class actually implements the MouseButtonEvent class.
     */
    class MouseButtonPressedEvent : public MouseButtonEvent
    {
      public:
        MouseButtonPressedEvent(int32_t button) : MouseButtonEvent(button) {}
        std::string ToString() const override
        {
            std::stringstream ss;
            ss << "MouseButtonPressed: " << m_button;
            return ss.str();
        }
        EVENT_CLASS_TYPE(MouseButtonPressed)
    };

    /**
     * @brief The MouseButtonReleasedEvent class
     * @details This class implements the MouseButtonEvent class
     */
    class MouseButtonReleasedEvent : public MouseButtonEvent
    {
      public:
        MouseButtonReleasedEvent(int32_t button) : MouseButtonEvent(button) {}
        std::string ToString() const override
        {
            std::stringstream ss;
            ss << "MouseButtonReleased: " << m_button;
            return ss.str();
        }
        EVENT_CLASS_TYPE(MouseButtonReleased)
    };
}
