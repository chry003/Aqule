#include "aqpcz.hpp"
#include "Application.hpp"

#include <iostream>


namespace Aq{

    Application::Application()
    {
    	// create window
        m_Window = std::unique_ptr<Window>(Window::Create());
    }

    Application::~Application()
    {
        
    }
    
    void Application::Run()
    {
        while(m_Running)
        {
            m_Window->OnUpdate();
        }
    }
}