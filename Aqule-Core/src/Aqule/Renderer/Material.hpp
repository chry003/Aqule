#pragma once

#include <glad/glad.h>
#include <glm/glm.hpp>
#include <deque>

#include "Buffer.hpp"
#include "VertexArray.hpp"
#include "Shader.hpp"


namespace Aq {

	class Material
	{
	public:
		Material(const glm::vec3& Position, const glm::vec2& Size, const glm::vec4 Color);

		void SetPosition(glm::vec3 Position) { m_Position = Position; }
		void SetSize(glm::vec2 Size) { m_Size = Size; }
		void SetColor(glm::vec4 Color) { m_Color = Color; }

		const glm::vec3& GetPosition() const { return m_Position; }
		const glm::vec2& GetSize() const { return m_Size; }
		const glm::vec4& GetColor() const { return m_Color; }

		const std::shared_ptr<Shader>& GetShader() const { return m_Shader; }
		const std::shared_ptr<VertexArray>& GetVertexArray() const { return m_VertexArray; }

		void SetBuffer() 
		{
			m_VertexArray->AddVertexBuffer(m_VertexBuffer);
			m_VertexArray->SetIndexBuffer(m_IndexBuffer);

			m_VertexArray->Bind();
		}
	private:
		glm::vec3 m_Position;
		glm::vec2 m_Size;
		glm::vec4 m_Color;

		std::shared_ptr<Shader> m_Shader;
		std::shared_ptr<VertexArray> m_VertexArray;
		std::shared_ptr<VertexBuffer> m_VertexBuffer;
		std::shared_ptr<IndexBuffer> m_IndexBuffer;
	};

}