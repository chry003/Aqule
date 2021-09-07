#include "Aqule.hpp"

#include "imgui.h"

class TriangleLayer : public Aq::Layer
{
public:
	TriangleLayer()
		: Layer("Triangle")
	{

	}

	void OnAttach() override
	{
	}

	void OnUpdate() override
	{
		Aq::VertexArray* m_VertexArray = new Aq::VertexArray(); 
		m_VertexArray->Bind();

		Aq::Shader* m_Shader = new Aq::Shader("Shader", "./assets/shader/shader.vert", "./assets/shader/shader.frag");
		m_Shader->Bind();
		m_Shader->SetFloat4("sh_color", m_Color);

		Aq::VertexBuffer* m_VertexBuffer = new Aq::VertexBuffer(g_vertex_buffer_data, sizeof(g_vertex_buffer_data)); 
		m_VertexBuffer->Bind();

		Aq::BufferLayout layout = 
		{
			{ Aq::ShaderDataType::Float3, "position" }
		};

		m_VertexBuffer->SetLayout(layout);
		m_VertexArray->AddVertexBuffer(m_VertexBuffer);

		Aq::IndexBuffer* m_IndexBuffer = new Aq::IndexBuffer(ind, sizeof(ind)); 
		m_IndexBuffer->Bind();

		m_VertexArray->SetIndexBuffer(m_IndexBuffer);

		glDrawElements(GL_TRIANGLES, sizeof(ind), GL_UNSIGNED_INT, nullptr);
		glDisableVertexAttribArray(0);
	}

	void OnImGuiRender() override
	{
        {
            ImGui::Begin("Hello, world!");

            ImGui::ColorEdit3("clear color", (float*)&m_Color);

            ImGui::Text("Application average %.3f ms/frame (%.1f FPS)", 1000.0f / ImGui::GetIO().Framerate, ImGui::GetIO().Framerate);
            ImGui::End();
        }
	}

private:
	glm::vec4 m_Color = glm::vec4(0.2f, 0.4f, 0.9f, 1);

	GLfloat g_vertex_buffer_data[3 * 3] = {
		-0.5f, -0.5f, 0.0f,
		 0.5f, -0.5f, 0.0f,
		 0.0f,  0.5f, 0.0f,
	};

	unsigned int ind[3] = 
	{
		0, 1, 2
	};
};

class Sandbox : public Aq::Application
{
public:
    Sandbox()
    {
    	PushOverlay(new TriangleLayer());
    }
    ~Sandbox()
    {
        
    }
};

Aq::Application* Aq::CreateApplication()
{
    return new Sandbox();
}