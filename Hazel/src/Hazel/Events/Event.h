#pragma once

#include "hzpch.h"
#include "Hazel/Core.h"

#include <spdlog/fmt/bundled/core.h>

namespace Hazel {

	// Events in Hazel are currently blocking, meaning when an event occurs it
	// immediately gets dispatched and must be dealt with right then an there.
	// For the future, a better strategy might be to buffer events in an event
	// bus and process them during the "event" part of the update stage.

	enum class EventType
	{
		None = 0,
		AppTick, AppUpdate, AppRender,
		WindowClose, WindowResize, WindowFocus, WindowLostFocus, WindowMoved,
		KeyPressed, KeyReleased, KeyTyped,
		MouseButtonPressed, MouseButtonReleased, MouseMoved, MouseScrolled, MouseEntered, MouseLeft
	};

	enum EventCategory
	{
		None = 0,
		EventCategoryApplication    = BIT(0),
		EventCategoryWindow         = BIT(1),
		EventCategoryInput          = BIT(2),
		EventCategoryKeyboard       = BIT(3),
		EventCategoryMouse          = BIT(4),
		EventCategoryMouseButton    = BIT(5)
	};

#define EVENT_CLASS_TYPE(type) static EventType GetStaticType() { return EventType::##type; }\
								virtual EventType GetEventType() const override { return GetStaticType(); }\
								virtual const char* GetName() const override { return #type; }

#define EVENT_CLASS_CATEGORY(category) virtual int GetCategoryFlags() const override { return category; }

	class HAZEL_API Event
	{
		friend class EventDispatcher;
	public:
		[[nodiscard]] virtual EventType GetEventType() const = 0;
		[[nodiscard]] virtual const char* GetName() const = 0;
		[[nodiscard]] virtual int GetCategoryFlags() const = 0;
		[[nodiscard]] virtual std::string ToString() const { return GetName(); }

		[[nodiscard]] bool IsInCategory(const EventCategory & category) const
		{
			return GetCategoryFlags() & category;
		}

		[[nodiscard]] bool IsHandled() const { return m_Handled; }
		
	protected:
		bool m_Handled = false;
	};

	class EventDispatcher
	{
		template<typename T>
		using EventFn = std::function<bool(T&)>;
	public:
		EventDispatcher(Event& event)
			: m_Event(event)
		{
		}

		template<typename T>
		bool Dispatch(EventFn<T> func)
		{
			if (m_Event.GetEventType() == T::GetStaticType())
			{
				m_Event.m_Handled = func(*static_cast<T *>(&m_Event));
				return true;
			}
			return false;
		}
	
	private:
		Event& m_Event;
	};

	inline std::ostream& operator<<(std::ostream& os, const Event& e)
	{
		return os << e.ToString();
	}
}
