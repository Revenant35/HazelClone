#pragma once

#include "Event.h"

#include <spdlog/fmt/ostr.h>
#include <spdlog/spdlog.h>

namespace Hazel
{
    class HAZEL_API WindowResizeEvent : public Event
    {
    public:
        WindowResizeEvent(const unsigned int width, const unsigned int height)
            : m_Width(width), m_Height(height) {}

        [[nodiscard]] unsigned int GetWidth() const { return m_Width; }
        [[nodiscard]] unsigned int GetHeight() const { return m_Height; }

        [[nodiscard]] std::string ToString() const override
        {
            std::stringstream ss;
            ss << "WindowResizeEvent: " << m_Width << ", " << m_Height;
            return ss.str();
        }
        
        EVENT_CLASS_TYPE(WindowResize)
        EVENT_CLASS_CATEGORY(EventCategoryWindow)
    private:
        unsigned int m_Width, m_Height;
    };

    class HAZEL_API WindowCloseEvent : public Event
    {
    public:
        WindowCloseEvent() {}
        
        [[nodiscard]] std::string ToString() const override
        {
            std::stringstream ss;
            ss << "WindowCloseEvent";
            return ss.str();
        }
        
        EVENT_CLASS_TYPE(WindowClose)
        EVENT_CLASS_CATEGORY(EventCategoryWindow)
    };

    class HAZEL_API WindowFocusEvent : public Event
    {
    public:
        WindowFocusEvent() {}
        
        [[nodiscard]] std::string ToString() const override
        {
            std::stringstream ss;
            ss << "WindowFocusEvent";
            return ss.str();
        }
        
        EVENT_CLASS_TYPE(WindowFocus)
        EVENT_CLASS_CATEGORY(EventCategoryWindow)
    };

    class HAZEL_API WindowLostFocusEvent : public Event
    {
    public:
        WindowLostFocusEvent() {}
        
        [[nodiscard]] std::string ToString() const override
        {
            std::stringstream ss;
            ss << "WindowLostFocusEvent";
            return ss.str();
        }
        
        EVENT_CLASS_TYPE(WindowLostFocus)
        EVENT_CLASS_CATEGORY(EventCategoryWindow)
    };
}