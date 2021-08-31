#pragma once

#include "Event.hpp"

namespace Aq {

	class WindowPosEvent : public Event
	{
	public:
		WindowPosEvent(int xpos, int ypos)
			: m_Xpos(xpos), m_Ypos(ypos) {}

		inline int GetXpos() const { return m_Xpos; }
		inline int GetYpos() const { return m_Ypos; }

		std::string ToString() const override
		{
			std::stringstream ss;

			ss << "WindowPosEvent: " << "x(" << m_Xpos << ")" << ", " << "y(" << m_Ypos << ")";

			return ss.str();
		}

		EVENT_CLASS_TYPE(WindowPosition)
		EVENT_CLASS_CATEGORY(EventCategoryApplication)

	private:

		int m_Xpos, m_Ypos;
	};

	class WindowSizeEvent : public Event
	{
	public:
		WindowSizeEvent(unsigned int width, unsigned int height)
			: m_Width(width), m_Height(height) {}

		inline unsigned int GetWidth() const { return m_Width; }
		inline unsigned int GetHeight() const { return m_Height; }

		std::string ToString() const override
		{
			std::stringstream ss;
			ss << "WindowSizeEvent: " << "width(" << m_Width << ")" << ", " << "height(" << m_Height << ")";
			return ss.str();
		}

		EVENT_CLASS_TYPE(WindowSize)
		EVENT_CLASS_CATEGORY(EventCategoryApplication)
	private:
		unsigned int m_Width, m_Height;		
	};

	class WindowCloseEvent : public Event
	{
	public:
		WindowCloseEvent() {}

		EVENT_CLASS_TYPE(WindowClose)
		EVENT_CLASS_CATEGORY(EventCategoryApplication)

	};

	class WindowRefreshEvent : public Event
	{
	public:
		WindowRefreshEvent(){}

		EVENT_CLASS_TYPE(WindowRefresh)
		EVENT_CLASS_CATEGORY(EventCategoryApplication)
	};

	class WindowFocusedEvent : public Event
	{
	public:
		WindowFocusedEvent(int focused)
			: m_Focused(focused)
		{}

		EVENT_CLASS_TYPE(WindowFocused)
		EVENT_CLASS_CATEGORY(EventCategoryApplication)

	private:
		int m_Focused;
	};

}
