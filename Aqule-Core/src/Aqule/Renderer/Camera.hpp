#pragma once

#include <glm/glm.hpp>
#include <glm/ext/matrix_transform.hpp>
#include <glm/ext/matrix_clip_space.hpp>

namespace Aq {

	class OrthographicCamera
	{
	public:
		OrthographicCamera(float left, float right, float bottom, float top);

		void SetPosition(const glm::vec3& pos) 
		{ 
			m_Position = pos;
			CalculateViewMatrix();
		}

		void SetRotation(float rotation) 
		{ 
			m_Rotation = rotation;
			CalculateViewMatrix();
		}

		void SetRatio(glm::vec4 ratio)
		{
			m_ProjectionMatrix = glm::ortho(ratio.x, ratio.y, ratio.z, ratio.w, -1.0f, 1.0f);
			m_ViewMatrix = glm::mat4(1.0f);
			m_ViewProjectionMatrix = m_ProjectionMatrix * m_ViewMatrix;
		}

		const glm::vec3 GetPosition() { return m_Position; }
		float GetRotation() { return m_Rotation; }

		const glm::mat4& GetProjectionMatrix() const { return m_ProjectionMatrix; }
		const glm::mat4& GetViewMatrix() const { return m_ViewMatrix; }
		const glm::mat4& GetViewProjectionMatrix() const { return m_ViewProjectionMatrix; }

	private:
		void CalculateViewMatrix();

	private:
		glm::vec3 m_Position = glm::vec3(1.0f);
		float m_Rotation = 0.0f;

		glm::mat4 m_ProjectionMatrix;
		glm::mat4 m_ViewMatrix;
		glm::mat4 m_ViewProjectionMatrix;
	};

}