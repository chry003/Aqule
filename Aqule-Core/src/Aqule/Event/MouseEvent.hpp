#pragma once

#include "Event.hpp"

namespace Aq {

    class MousePositionEvent : public Event
    {
    public:
        MousePositionEvent(float xpos, float ypos)
        : m_xpos(xpos), m_ypos(ypos)
        {

        }

        std::string ToString() const override
        {
            std::stringstream ss;
            ss << "MousePositionEvent: " << m_xpos << ", " << m_ypos;
            return ss.str();
        }

        EVENT_CLASS_TYPE(MousePosition)
        EVENT_CLASS_CATEGORY(EventCategoryMouse | EventCategoryInput)

    private:
        float m_xpos, m_ypos;
    };

    class MouseButtonPressedEvent : public Event
    {
    public:

    	MouseButtonPressedEvent(int button)
    		: m_Button(button) {}

        std::string ToString() const override
        {
            std::stringstream ss;
            ss << "MouseButtonPressedEvent: " << m_Button;
            return ss.str();
        }

    	EVENT_CLASS_TYPE(MouseButtonPressed)
        EVENT_CLASS_CATEGORY(EventCategoryMouse | EventCategoryInput)

    private:
    	int m_Button;
    };

    class MouseButtonReleasedEvent : public Event
    {
    public:

    	MouseButtonReleasedEvent(int button)
    		: m_Button(button) {}

        std::string ToString() const override
        {
            std::stringstream ss;
            ss << "MouseButtonReleasedEvent: " << m_Button;
            return ss.str();
        }

    	EVENT_CLASS_TYPE(MouseButtonReleased)
        EVENT_CLASS_CATEGORY(EventCategoryMouse | EventCategoryInput)

    private:
    	int m_Button;
    };

    class MouseScrollEvent : public Event
    {
    public:

    	MouseScrollEvent(float xoffset, float yoffset)
    		: m_Xoffset(xoffset), m_Yoffset(yoffset) {}


        std::string ToString() const override
        {
            std::stringstream ss;
            ss << "MouseScrollEvent: " << m_Xoffset << ", " << m_Yoffset;
            return ss.str();
        }

    	EVENT_CLASS_TYPE(MouseScroll)
        EVENT_CLASS_CATEGORY(EventCategoryMouse | EventCategoryInput)

    private:
    	float m_Xoffset, m_Yoffset;
    };

}