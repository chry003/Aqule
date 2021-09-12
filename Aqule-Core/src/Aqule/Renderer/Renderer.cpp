#include "Renderer.hpp"

namespace Aq {

	Renderer::OrthographicCameraMatrix* Renderer::m_RendererElements = new Renderer::OrthographicCameraMatrix;

	void Renderer::Begin(OrthographicCamera& camera) 
	{
		m_RendererElements->ViewProjectionMatrix = camera.GetViewProjectionMatrix();
	}

	void Renderer::Submit(const std::shared_ptr<Material>& material)
	{
		material->GetShader()->Bind();
		material->GetShader()->SetMat4("u_ViewPorjectionMatrix", m_RendererElements->ViewProjectionMatrix);
		material->GetShader()->SetMat4("u_ModalViewMatrix", glm::translate(glm::mat4(1.0f), material->GetPosition()));
		material->GetShader()->SetFloat4("sh_color", material->GetColor());

		material->SetBuffer();

		RendererCommand::Draw(material->GetVertexArray());

	}

	void Renderer::End() 
	{
	}

	void Renderer::Flush() 
	{
	}
}