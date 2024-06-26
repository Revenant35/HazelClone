#pragma once

#include "Event.h"


namespace Hazel {

    class HAZEL_API KeyEvent : public Event
    {
    public:
        [[nodiscard]] int GetKeyCode() const { return m_KeyCode; }

        EVENT_CLASS_CATEGORY(EventCategoryKeyboard | EventCategoryInput)
    protected:
        KeyEvent(const int & keycode)
            : m_KeyCode(keycode) {}

        int m_KeyCode;
    };

    class HAZEL_API KeyPressedEvent : public KeyEvent
    {
    public:
        KeyPressedEvent(const int keycode, const int repeatCount)
            : KeyEvent(keycode), m_RepeatCount(repeatCount) {}

        [[nodiscard]] int GetRepeatCount() const { return m_RepeatCount; }

        [[nodiscard]] std::string ToString() const override
        {
            std::stringstream ss;
            ss << "KeyPressedEvent: " << m_KeyCode << " (" << m_RepeatCount << " repeats)";
            return ss.str();
        }

        EVENT_CLASS_TYPE(KeyPressed)
    private:
        int m_RepeatCount;
    };

    class HAZEL_API KeyReleasedEvent : public KeyEvent
    {
    public:
        KeyReleasedEvent(const int keycode)
            : KeyEvent(keycode) {}

        [[nodiscard]] std::string ToString() const override
        {
            std::stringstream ss;
            ss << "KeyReleasedEvent: " << m_KeyCode;
            return ss.str();
        }

        EVENT_CLASS_TYPE(KeyReleased)
    };

    class HAZEL_API KeyTypedEvent : public KeyEvent
    {
    public:
        KeyTypedEvent(const int keycode)
            : KeyEvent(keycode) {}

        [[nodiscard]] std::string ToString() const override
        {
            std::stringstream ss;
            ss << "KeyTypedEvent: " << m_KeyCode;
            return ss.str();
        }

        EVENT_CLASS_TYPE(KeyTyped)
    };
}