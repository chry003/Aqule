#pragma once

#include "Core.hpp"
#include "Window.hpp"

namespace Aq{
    class Application
    {
    public:
        Application();
        virtual ~Application();

        void OnEvent(Event& e);
    
        void Run();
    private:
    	std::unique_ptr<Window> m_Window;
    	bool m_Running = true;
    };
    
    Application* CreateApplication();
}