#include "aqpcz.hpp"
#include "Application.hpp"
#include "log.hpp"

#include <glad/glad.h>
#include "Aqule/Platform/OpenGL/OpenGLShader/Shader.hpp"

#include "Input.hpp"

namespace Aq{

    Application* Application::s_Instance = nullptr;

    Application::Application()
    {
    	// create window

        s_Instance = this;

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

        glClearColor(0.0f, 0.0f, 0.4f, 0.0f);

        GLuint VertexArrayID;
        glGenVertexArrays(1, &VertexArrayID);
        glBindVertexArray(VertexArrayID);

        static const GLfloat g_vertex_buffer_data[] = { 
            -1.0f, -1.0f, 0.0f,
             1.0f, -1.0f, 0.0f,
             0.0f,  1.0f, 0.0f,
        };

        GLuint vertexbuffer;
        glGenBuffers(1, &vertexbuffer);
        glBindBuffer(GL_ARRAY_BUFFER, vertexbuffer);
        glBufferData(GL_ARRAY_BUFFER, sizeof(g_vertex_buffer_data), g_vertex_buffer_data, GL_STATIC_DRAW);


        // Create and compile our GLSL program from the shaders
        Shader shader("./Aqule-Core/src/Aqule/Platform/OpenGL/OpenGLShader/VertexShader.aq_shader", "./Aqule-Core/src/Aqule/Platform/OpenGL/OpenGLShader/FragmentShader.aq_shader");

        shader.enable();


        while(m_Running)
        {
            m_Window->OnClear();

            glEnableVertexAttribArray(0);
            glBindBuffer(GL_ARRAY_BUFFER, vertexbuffer);
            glVertexAttribPointer(
                0,                  // attribute 0. No particular reason for 0, but must match the layout in the shader.
                3,                  // size
                GL_FLOAT,           // type
                GL_FALSE,           // normalized?
                0,                  // stride
                0            // array buffer offset
            );
            // 1rst attribute buffer : vertices
            // Draw the triangle !
            glDrawArrays(GL_TRIANGLES, 0, 3); // 3 indices starting at 0 -> 1 triangle
            glDisableVertexAttribArray(0);

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
