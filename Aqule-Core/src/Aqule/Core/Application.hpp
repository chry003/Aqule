#pragma once

#include "Core.hpp"

#include "Window.hpp"
#include "Aqule/Event/Event.hpp"
#include "Aqule/Event/ApplicationEvent.hpp"
#include "Aqule/Core/LayerStack.hpp"

namespace Aq{
    class Application
    {
    public:
        Application();
        virtual ~Application();

        void OnEvent(Event& e);

        void PushLayer(Layer* layer);
        void PushOverlay(Layer* overlay);
    
        void Run();
    private:
        bool OnWindowClose(WindowCloseEvent& e);

    	std::unique_ptr<Window> m_Window;
    	bool m_Running = true;
        LayerStack m_LayerStack;
    };
    
    Application* CreateApplication();
}