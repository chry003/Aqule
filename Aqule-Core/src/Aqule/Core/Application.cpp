#include "aqpcz.hpp"
#include "Application.hpp"
#include "Aqule/Event/Event.hpp"
#include "Aqule/Event/ApplicationEvent.hpp"
#include "log.hpp"

#include <iostream>

// FIXME: Application file

namespace Aq{

#define BIND_EVENT_FN(x) std::bind(&Application::x, this, std::placeholders::_1)

    Application::Application()
    {
    	// create window
        // m_Window = std::unique_ptr<Window>(Window::Create());
        m_Window = std::unique_ptr<Window>(Window::Create());

        m_Window->SetEventCallback(BIND_EVENT_FN(OnEvent));
    }

    Application::~Application()
    {
    }

    void Application::OnEvent(Event& e)
    {

        AQ_CORE_INFO("{0}", e.ToString());

        if (e.GetEventType() == 1)
        {
            m_Running = false;
        }
    }


    void Application::Run()
    {
        while(m_Running)
        {
            m_Window->OnUpdate();
        }
    }
}
