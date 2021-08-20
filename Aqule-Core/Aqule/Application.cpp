#include "Application.hpp"
#include <iostream>

namespace Aq {
    
    
    Application::Application()
    {
    }

    Application::~Application()
    {
    }
    
    void Application::aqMessage()
    {
        std::cout << "Aqule Engine" << std::endl;
    }
    
}