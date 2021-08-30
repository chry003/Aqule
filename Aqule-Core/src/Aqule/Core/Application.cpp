#include "aqpcz.hpp"
#include "Application.hpp"
#include "log.hpp"

// FIXME:

namespace Aq{

    Application::Application()
    {
    	// create window
        m_Window = std::unique_ptr<Window>(Window::Create());
        m_Window->SetEventCallback(BIND_EVENT_FN(Application::OnEvent));
    }

    Application::~Application()
    {
    }

    void Application::PushLayer(Layer* layer) 
    {
        m_LayerStack.PushLayer(layer);
    }

    void Application::PushOverlay(Layer* overlay) 
    {
        m_LayerStack.PushOverlay(overlay);
    }

    void Application::OnEvent(Event& e)
    {
        EventDispatcher dispatcher(e);
        dispatcher.Dispatch<WindowCloseEvent>(BIND_EVENT_FN(Application::OnWindowClose));

        // AQ_CORE_INFO("{0}", e.ToString());
        
        for (auto it = m_LayerStack.end(); it != m_LayerStack.begin(); )
        {
            (*--it)->OnEvent(e);
            if(e.Handled())
                break;
        }
    }


    void Application::Run()
    {
        while(m_Running)
        {
            m_Window->OnUpdate();


            for (Layer* layer : m_LayerStack)
                layer->OnUpdate();
        }
    }

    bool Application::OnWindowClose(WindowCloseEvent& e)
    {
        m_Running = false;
        return true;
    }
}
