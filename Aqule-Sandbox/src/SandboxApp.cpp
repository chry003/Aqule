#include "Aqule.hpp"

#include "imgui.h"

class TriangleLayer : public Aq::Layer
{
public:
	TriangleLayer()
		: Layer("Triangle"), m_Camera(-3.5f, 3.5f, -3.5f, 3.5f)
	{

	}

	void OnAttach() override
	{
		Aq::RendererCommand::SetClearColor({0.1f, 0.1f, 0.1f, 1.0f});

		for (float y = 0; y < 4.0f; y += 0.5)
		{
			for (float x = 0; x < 8.0f; x += 0.5)
			{
				m_MaterialVec.push_back(std::make_shared<Aq::Material>(
					glm::vec3(x, y, 0.0f),
					glm::vec2(0.4f, 0.4f), 
					glm::vec4(rand() % 1000 / 1000.0f, 0.0f, 1.0f, 1.0f)
				));
			}
		}
	}

	void OnUpdate() override
	{
		{
	        if (Aq::Input::IsKeyPressed(Aq::Key::A))
	        {
	        	pos.x += speed;
	        }
	        else if (Aq::Input::IsKeyPressed(Aq::Key::D))
	        {
	        	pos.x -= speed;
	        }
	        else if (Aq::Input::IsKeyPressed(Aq::Key::W))
	        {
	        	pos.y -= speed;
	        }
	        else if (Aq::Input::IsKeyPressed(Aq::Key::S))
	        {
	        	pos.y += speed;
	        }

	        if (Aq::Input::IsKeyPressed(Aq::Key::Q))
	        {
	        	cameraRatio.x -= cameraRatioSpeed;
	        	cameraRatio.y += cameraRatioSpeed;
	        	cameraRatio.z -= cameraRatioSpeed;
	        	cameraRatio.w += cameraRatioSpeed;
	        	m_Camera.SetRatio(cameraRatio);
	        }
	        else if (Aq::Input::IsKeyPressed(Aq::Key::E))
	        {
	        	cameraRatio.x += cameraRatioSpeed;
	        	cameraRatio.y -= cameraRatioSpeed;
	        	cameraRatio.z += cameraRatioSpeed;
	        	cameraRatio.w -= cameraRatioSpeed;
	        	m_Camera.SetRatio(cameraRatio);
	        }
		}

		m_Camera.SetPosition(pos);
		
		Aq::Renderer::Begin(m_Camera);

		for (auto item: m_MaterialVec)
		{
			Aq::Renderer::Submit(item);
		}

		Aq::Renderer::End();
		
		Aq::Renderer::Flush();
	}

	void OnImGuiRender() override
	{
        {
            ImGui::Begin("Hello, world!");
            ImGui::SliderFloat("float", &cameraRatioSpeed, 0.0f, 0.5f);
            ImGui::SliderFloat("float2", &speed, 0.0f, 0.5f);
            ImGui::Text("Application average %.3f ms/frame (%.1f FPS)", 1000.0f / ImGui::GetIO().Framerate, ImGui::GetIO().Framerate);
            ImGui::End();
        }
	}

private:
	Aq::OrthographicCamera m_Camera;
	glm::vec4 cameraRatio = glm::vec4(-3.5f, 3.5f, -3.5f, 3.5f);
	glm::vec3 pos = glm::vec3(0.0f, 0.0f, 0.0f);
	float speed = 0.03f;
	float cameraRatioSpeed = 0.3f;

	std::vector<std::shared_ptr<Aq::Material>> m_MaterialVec;
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