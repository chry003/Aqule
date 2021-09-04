#pragma once

#include <glad/glad.h>

#include "aqpch.hpp"
#include "Aqule/Renderer/Shader.hpp"

namespace Aq {

	class OpenGLShader : public Shader
	{
	public:
		OpenGLShader(const std::string& name, const std::string& vertexSrc, const std::string& fragmentSrc);
		virtual ~OpenGLShader() override;

		virtual void Bind() const override;
		virtual void Unbind() const override;

		virtual void SetInt(const std::string& name, int value) override;
		virtual void SetIntArray(const std::string& name, int* values, int count) override;
		virtual void SetFloat(const std::string& name, float value) override;
		virtual void SetFloat2(const std::string& name, const glm::vec2& value) override;
		virtual void SetFloat3(const std::string& name, const glm::vec3& value) override;
		virtual void SetFloat4(const std::string& name, const glm::vec4& value) override;
		virtual void SetMat4(const std::string& name, const glm::mat4& value) override;

		virtual const std::string& GetName() const override { return m_Name; };
	
	private:
		GLuint m_ShaderID;
		std::string m_Name;

	private:
		void Load(const std::string& vertexSrc, const std::string& fragmentSrc);
		void CompileShader(const char* VertexSourcePointer, const char* FragmentSourcePointer);
		void CreateProgram(GLuint VertexShaderID, GLuint FragmentShaderID);
		void DeleteShader(GLuint ProgramID, GLuint VertexShaderID, GLuint FragmentShaderID);

		void ShaderErr(std::string desc, GLuint ShaderSourceID);

		GLint getUniformLocation(const GLchar* name);
	};

}