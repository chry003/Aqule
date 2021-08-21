#pragma once


#include "Event.hpp"

#include <sstream>

namespace Aq {
    
    class KeyEvent : public Event
    {
    public:
        inline int GetKeyCode const { return m_KeyCode; }
        
        EVENT_CLASS_CATEGORY(EventCategoryKeyboard | EventCategoryInput)
    protected:
        KeyEvent(int keycode)
            :m_KeyCode(keycode) {}
        
        int m_KeyCode;
    };
}