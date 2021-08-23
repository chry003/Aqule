#include "aqpcz.hpp"
#include "Application.hpp"
#include "Aqule/Event/Event.hpp"
#include "Aqule/Event/ApplicationEvent.hpp"

#include <iostream>

namespace Aq{

#define BIND_EVENT_FN(x) std::bind(&Application::x, this, std::placeholders::_1)

    Application::Application()
    {
    	// create window
        m_Window = std::unique_ptr<Window>(Window::Create());

        m_Window->SetEventCallback(BIND_EVENT_FN(OnEvent));
    }

    Application::~Application()
    {
    }

    void Application::OnEvent(Event& e)
    {
        std::cout << e.GetEventType() << std::endl;
        std::cout << e.ToString() << std::endl;
    }

    
    void Application::Run()
    {
        while(m_Window->IsAlive())
        {
            m_Window->OnUpdate();
        }
    }
}