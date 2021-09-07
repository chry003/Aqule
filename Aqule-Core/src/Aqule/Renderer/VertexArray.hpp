#pragma once

#include <glad/glad.h>
#include "Buffer.hpp"
#include "aqpch.hpp"

namespace Aq {

	class VertexArray
	{
	public:
		VertexArray();
		~VertexArray() {};

		void Bind() const;
		void Unbind() const;

		void AddVertexBuffer(VertexBuffer* vertexBuffer);
		void SetIndexBuffer(IndexBuffer* indexBuffer);

		const std::vector<VertexBuffer*> GetVertexBuffers() const { return m_VertexBuffers; }
		const std::vector<IndexBuffer*> GetIndexBuffer() const { return m_IndexBuffer; }

	private:
		uint32_t m_VertexArrayID;
		std::vector<VertexBuffer*> m_VertexBuffers;
		IndexBuffer* m_IndexBuffer;
	};

}