#pragma once

#include "Event.hpp"

namespace Aq {

	class WindowResizeEvent : public Event
	{
	public:
		WindowResizeEvent(unsigned int width, unsigned int height)
			: m_Width(width), m_Height(height) {}

		inline unsigned int GetWidth() const { return m_Width; }
		inline unsigned int GetHeight() const { return m_Height; }

		std::string ToString() const override
		{
			std::stringstream ss;
			ss << "WindowResizeEvent: " << m_Width << ", " << m_Height;
			return ss.str();
		}



		EVENT_CLASS_TYPE(WindowResize)
	private:
		unsigned int m_Width, m_Height;
	};

    class MousePositionEvent : public Event
    {
    public:
        MousePositionEvent(double xpos, double ypos)
        : m_xpos(xpos), m_ypos(ypos)
        {

        }

        std::string ToString() const override
        {
            std::stringstream ss;
            ss << "Mouse Position: " << m_xpos << ", " << m_ypos;
            return ss.str();
        }

        EVENT_CLASS_TYPE(MousePosition)

    private:
        double m_xpos, m_ypos;
    };

	class WindowCloseEvent : public Event
	{
	public:
		WindowCloseEvent() {}

		EVENT_CLASS_TYPE(WindowClose)

	};

	class KeyboardKeysEvent : public Event
	{
	public:
	    KeyboardKeysEvent(int key, int scancode, int action, int mods)
            : m_Key(key), m_Scancode(scancode), m_Action(action), m_Mods(mods)
	    {

	    }

        std::string ToString() const override
        {
            std::stringstream ss;
            ss << "Key: " << m_Key << ", " << "Scancode: " << m_Scancode << ", " << "Action: " << m_Action << ", " << "Mods: " << m_Mods;
            return ss.str();
        }

        EVENT_CLASS_TYPE(KeyboardKeys)
    private:
        int m_Key, m_Scancode, m_Action, m_Mods;
	};

}
