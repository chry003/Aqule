#pragma once

#include <glad/glad.h>
#include <glm/glm.hpp>
#include <deque>

#include "Buffer.hpp"
#include "VertexArray.hpp"
#include "Shader.hpp"
#include "Camera.hpp"
#include "Material.hpp"

namespace Aq {

	class RendererCommand
	{
	public:
		inline static void SetClearColor(const glm::vec4& color)
		{
			glClearColor(color.r, color.g, color.b, color.a);
		}

		inline static void Draw(const std::shared_ptr<VertexArray>& vertexArray)
		{
			glDrawElements(GL_TRIANGLES, vertexArray->GetIndexBuffer()->GetCount(), GL_UNSIGNED_INT, nullptr);
		}
	};

	class Renderer
	{
	public:
		static void Begin(OrthographicCamera& camera);
		static void Submit(const std::shared_ptr<Material>& material);
		// @todo: work on submit, end and flush!
		static void End();
		// @todo: queue to queue
		static void Flush();
		// @todo: loop

	private:
		struct OrthographicCameraMatrix
		{
			glm::mat4 ViewProjectionMatrix;
		};

		static OrthographicCameraMatrix* m_RendererElements;
	};

}

/*

begin it takes camera
submit it takes material but it doesn't queue it

if you don't end the submition it won't take more space creating new instance of vertex array... or anything it will re-declare with the new value

and end will queue it
flush will go thru all the elem and draw it one by one
*/