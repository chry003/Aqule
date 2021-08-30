#pragma once

#include "Event.hpp"

namespace Aq {

	class KeyPressedEvent : public Event
	{
	public:
		KeyPressedEvent(int key, int count)
			: m_Key(key), m_Count(count) {}

		std::string ToString() const override
		{
			std::stringstream ss;
			ss << "KeyPressedEvent: " << "key(" << m_Key << ") " << "repeat(" << m_Count << ")";
			return ss.str();
		}

		EVENT_CLASS_TYPE(KeyPressed)
		EVENT_CLASS_CATEGORY(EventCategoryKeyboard | EventCategoryInput)
	private:
		int m_Key, m_Count;
	};

	class KeyReleasedEvent : public Event
	{
	public:
		KeyReleasedEvent(int key)
			: m_Key(key) {}

		std::string ToString() const override
		{
			std::stringstream ss;
			ss << "KeyReleasedEvent: " << "key(" << m_Key << ")";
			return ss.str();
		}

		EVENT_CLASS_TYPE(KeyReleased)
		EVENT_CLASS_CATEGORY(EventCategoryKeyboard | EventCategoryInput)
	private:
		int m_Key;
	};
}