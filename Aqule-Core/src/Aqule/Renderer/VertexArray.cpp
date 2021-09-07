#include "VertexArray.hpp"

namespace Aq {

	static GLenum ShaderDataTypeToOpenGLType(ShaderDataType type)
	{
		switch(type)
		{
			case ShaderDataType::Float:		return GL_FLOAT;
			case ShaderDataType::Float2:	return GL_FLOAT;
			case ShaderDataType::Float3:	return GL_FLOAT;
			case ShaderDataType::Float4:	return GL_FLOAT;
			case ShaderDataType::Mat3:		return GL_FLOAT;
			case ShaderDataType::Mat4:		return GL_FLOAT;
			case ShaderDataType::Int:		return GL_INT;
			case ShaderDataType::Int2:		return GL_INT;
			case ShaderDataType::Int3:		return GL_INT;
			case ShaderDataType::Int4:		return GL_INT;
			case ShaderDataType::Bool:		return GL_BOOL;
		}
		ERR(false, "Unknown ShaderDataType, ValidTypes: (Float, Float2, Float3, Float4, Mat3, Mat4, Int, Int2, Int3, Int4, Bool)");
		return 0;
	}

	VertexArray::VertexArray() 
	{
		glGenVertexArrays(1, &m_VertexArrayID);
		glBindVertexArray(m_VertexArrayID);
	}

	void VertexArray::Bind() const 
	{
		glBindVertexArray(m_VertexArrayID);
	}

	void VertexArray::Unbind() const 
	{
		glBindVertexArray(0);
	}

	void VertexArray::AddVertexBuffer(VertexBuffer* vertexBuffer) 
	{
		ERR(vertexBuffer->GetLayout().GetElements().size(), "Vertex Buffer has no layout!");

		glBindVertexArray(m_VertexArrayID);
		vertexBuffer->Bind();

		uint32_t index = 0;
		for( const auto& element : vertexBuffer->GetLayout())
		{
			glEnableVertexAttribArray(index);
			glVertexAttribPointer(
				index, 
				element.GetComponentCount(), 
				Aq::ShaderDataTypeToOpenGLType(element.Type), 
				element.Normalized ? GL_TRUE : GL_FALSE, 
				vertexBuffer->GetLayout().GetStride(), 
				(const void*)element.Offset
			);

			index++;
		}

		m_VertexBuffers.push_back(vertexBuffer);
	}

	void VertexArray::SetIndexBuffer(IndexBuffer* indexBuffer) 
	{
		glBindVertexArray(m_VertexArrayID);
		indexBuffer->Bind();

		m_IndexBuffer = indexBuffer;
	}

}