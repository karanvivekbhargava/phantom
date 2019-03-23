#pragma once

#include <sstream>
#include "event.hpp"

namespace Phantom
{
    /**
     * @brief The KeyEvent class
     * @details This class is like an abstract class in the sense that the
     * constructor is private. So this can't be constructed ever from outside
     * the class, unless it's from a derived class. The only information this
     * class holds is the keycode of the key.
     */
    class KeyEvent : public Event
    {
      public:
        inline int32_t GetKeyCode() {return m_keycode;}
        EVENT_CLASS_CATEGORY(EventCategoryKeyboard | EventCategoryInput)
      protected:
        KeyEvent(int32_t keycode): m_keycode(keycode) {}

        int32_t m_keycode;
    };

    /**
     * @brief The KeyPressedEvent class
     * @details This class is an actual class which implements the KeyEvent
     * class. This has support for the pressed key events as well as the
     * repeated key events via a repeat count.
     */
    class KeyPressedEvent : public KeyEvent
    {
      public:
        KeyPressedEvent(int32_t keycode, uint32_t repeat_count)
            : KeyEvent(keycode), m_repeat_count(repeat_count) {}
        inline int32_t GetRepeatCount() const {return m_repeat_count;}
        std::string ToString() const override
        {
            std::stringstream ss;
            ss << "KeyPressedEvent: " << m_keycode << " (" << m_repeat_count << " repeats)";
            return ss.str();
        }
        EVENT_CLASS_TYPE(KeyPressed)
      private:
        int32_t m_repeat_count;
    };

    /**
     * @brief The KeyReleasedEvent class
     * @details This class creates the KeyReleasedEvents. This doesn't have the
     * repeat functionaliy of the KeyPressedEvent class. Hence this is simpler.
     */
    class KeyReleasedEvent : public KeyEvent
    {
      public:
        KeyReleasedEvent(int32_t keycode): KeyEvent(keycode) {}
        std::string ToString() const override
        {
            std::stringstream ss;
            ss << "KeyReleasedEvent: " << m_keycode;
            return ss.str();
        }
        EVENT_CLASS_TYPE(KeyReleased)
    };

}
