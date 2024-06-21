#pragma once

#include "Event.h"

namespace Hazel {

	class HAZEL_API MouseMovedEvent : public Event
	{
	public:
		MouseMovedEvent(const float x, const float y)
			: m_MouseX(x), m_MouseY(y) {}

		[[nodiscard]] float GetX() const { return m_MouseX; }
		[[nodiscard]] float GetY() const { return m_MouseY; }

		[[nodiscard]] std::string ToString() const override
		{
			std::stringstream ss;
			ss << "MouseMovedEvent: " << m_MouseX << ", " << m_MouseY;
			return ss.str();
		}

		EVENT_CLASS_TYPE(MouseMoved)
		EVENT_CLASS_CATEGORY(EventCategoryMouse | EventCategoryInput)
	private:
		float m_MouseX, m_MouseY;
	};

	class HAZEL_API MouseEnteredEvent : public Event
	{
	public:
		MouseEnteredEvent() {}
		
		[[nodiscard]] std::string ToString() const override
		{
			std::stringstream ss;
			ss << "MouseEnteredEvent";
			return ss.str();
		}

		EVENT_CLASS_TYPE(MouseEntered)
		EVENT_CLASS_CATEGORY(EventCategoryMouse | EventCategoryInput)
	};

	class HAZEL_API MouseLeftEvent : public Event
	{
	public:
		MouseLeftEvent() {}
		
		[[nodiscard]] std::string ToString() const override
		{
			std::stringstream ss;
			ss << "MouseLeftEvent";
			return ss.str();
		}

		EVENT_CLASS_TYPE(MouseLeft)
		EVENT_CLASS_CATEGORY(EventCategoryMouse | EventCategoryInput)
	};

	class HAZEL_API MouseScrolledEvent : public Event
	{
	public:
		MouseScrolledEvent(const float xOffset, const float yOffset)
			: m_XOffset(xOffset), m_YOffset(yOffset) {}

		[[nodiscard]] float GetXOffset() const { return m_XOffset; }
		[[nodiscard]] float GetYOffset() const { return m_YOffset; }

		[[nodiscard]] std::string ToString() const override
		{
			std::stringstream ss;
			ss << "MouseScrolledEvent: " << GetXOffset() << ", " << GetYOffset();
			return ss.str();
		}

		EVENT_CLASS_TYPE(MouseScrolled)
		EVENT_CLASS_CATEGORY(EventCategoryMouse | EventCategoryInput)
	private:
		float m_XOffset, m_YOffset;
	};

	class HAZEL_API MouseButtonEvent : public Event
	{
	public:
		[[nodiscard]] int GetMouseButton() const { return m_Button; }

		EVENT_CLASS_CATEGORY(EventCategoryMouse | EventCategoryInput)
	protected:
		MouseButtonEvent(const int & button)
			: m_Button(button) {}

		int m_Button;
	};

	class HAZEL_API MouseButtonPressedEvent : public MouseButtonEvent
	{
	public:
		MouseButtonPressedEvent(const int button)
			: MouseButtonEvent(button) {}

		[[nodiscard]] std::string ToString() const override
		{
			std::stringstream ss;
			ss << "MouseButtonPressedEvent: " << m_Button;
			return ss.str();
		}

		EVENT_CLASS_TYPE(MouseButtonPressed)
	};

	class HAZEL_API MouseButtonReleasedEvent : public MouseButtonEvent
	{
	public:
		MouseButtonReleasedEvent(const int button)
			: MouseButtonEvent(button) {}

		[[nodiscard]] std::string ToString() const override
		{
			std::stringstream ss;
			ss << "MouseButtonReleasedEvent: " << m_Button;
			return ss.str();
		}

		EVENT_CLASS_TYPE(MouseButtonReleased)
	};

}