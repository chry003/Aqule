#include "Material.hpp"

namespace Aq {
	
	Material::Material(const glm::vec3& Position, const glm::vec2& Size, const glm::vec4 Color)
		: m_Position(Position), m_Size(Size), m_Color(Color)
	{

		GLfloat vertices[3 * 4] = {
			0, 0, 0,
			0, Size.y, 0,
			Size.x, Size.y, 0,
			Size.x, 0, 0
		};

		unsigned int indices[6] = 
		{
			0, 1, 2, 2, 3, 0
		};

		m_Shader 		= std::make_shared<Shader>("Common Shader", "./assets/shader/shader.vert", "./assets/shader/shader.frag");
		m_VertexArray 	= std::make_shared<VertexArray>();
		m_VertexBuffer	= std::make_shared<VertexBuffer>(vertices, sizeof(vertices));
		m_IndexBuffer	= std::make_shared<IndexBuffer>(indices, sizeof(indices));

		m_VertexBuffer->SetLayout(
			{
				{ Aq::ShaderDataType::Float3, "position"}
			}
		);
	}
}