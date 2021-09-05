#include "aqpcz.hpp"
#include "Application.hpp"
#include "log.hpp"

#include "Input.hpp"

#include "Aqule/ImGui/ImGuiLayer.hpp"

#include "glm/glm.hpp"

namespace Aq{

    Application* Application::s_Instance = nullptr;

    Application::Application()
    {
    	// create window
        s_Instance = this;

        m_Window = std::unique_ptr<Window>(Window::Create());
        m_Window->SetEventCallback(BIND_EVENT_FN(Application::OnEvent));
        // PushOverlay(new ImGuiLayer);
    }

    Application::~Application()
    {
    }

    void Application::PushLayer(Layer* layer) 
    {
        m_LayerStack.PushLayer(layer);
        layer->OnAttach();
    }

    void Application::PushOverlay(Layer* overlay) 
    {
        m_LayerStack.PushOverlay(overlay);
        overlay->OnAttach();
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
        PushOverlay(new ImGuiLayer);
        
        while(m_Running)
        {
            m_Window->OnClear();

            for (Layer* layer : m_LayerStack)
                layer->OnUpdate();

            m_Window->OnUpdate();
        }
    }

    bool Application::OnWindowClose(WindowCloseEvent& e)
    {
        m_Running = false;
        return true;
    }
}