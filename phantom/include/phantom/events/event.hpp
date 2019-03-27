#pragma once

#include "phantom/core.hpp"
#include "phantom/phantom_pch.hpp"

namespace Phantom
{
    // Events are blocking, this means that one event needs to be processed
    // before another one is touched. This can be processed on a queue in
    // regular intervals too. This is also called an event bus.
    enum class EventType
    {
        None=0,
        WindowClose, WindowResize, WindowFocus, WindowLostFocus, WindowMoved,
        AppTick, AppUpdate, AppRender,
        KeyPressed, KeyReleased,
        MouseButtonPressed, MouseButtonReleased, MouseMoved, MouseScrolled
    };

    enum EventCategory
    {
        None=0,
        EventCategoryApplication    = BIT(0),
        EventCategoryInput          = BIT(1),
        EventCategoryKeyboard       = BIT(2),
        EventCategoryMouse          = BIT(3),
        EventCategoryMouseButton    = BIT(4)

    };

// These are some macros which will help prototyping multiple classes
#define EVENT_CLASS_TYPE(type)  static EventType GetStaticType() {return EventType::type;}\
                                virtual EventType GetEventType() const override {return GetStaticType();}\
                                virtual const char* GetName() const override {return #type;}

#define EVENT_CLASS_CATEGORY(category)  virtual int32_t GetCategoryFlags() const override {return category;}

    /**
     * @brief The Event class
     */
    class Event
    {
        friend class EventDispatcher;
      public:
        virtual EventType GetEventType() const = 0;
        virtual const char* GetName() const = 0;
        virtual int32_t GetCategoryFlags() const = 0;
        virtual std::string ToString() const {return GetName();}

        inline bool IsInCategory(EventCategory category)
        {
            return GetCategoryFlags() & category;
        }

        // Usually gets used by layers while handling events
        bool handled = false;
    };

    class EventDispatcher
    {
        template<typename T>
        using EventFn = std::function<bool(T&)>;
      public:
        EventDispatcher(Event& event) : m_event(event) {}

        template<typename T>
        bool Dispatch(EventFn<T> func)
        {
            bool ret_val = false;
            if (m_event.GetEventType() == T::GetStaticType())
            {
                m_event.handled = func(*(T*)&m_event);
                ret_val = true;
            }
            return ret_val;
        }
      private:
        Event& m_event;
    };

    inline std::ostream& operator<<(std::ostream& os, const Event& e)
    {
        return os << e.ToString();
    }

}

