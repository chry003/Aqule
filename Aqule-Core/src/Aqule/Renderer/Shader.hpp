#pragma once

#include <glad/glad.h>
#include <glm/glm.hpp>

#include "aqpch.hpp"

namespace Aq {

	class Shader
	{
	public:
		Shader(const std::string& name, const std::string& vertexSrc, const std::string& fragmentSrc);
		~Shader();

		void Bind() const;
		void Unbind() const;

		void SetInt(const std::string& name, int value);
		void SetIntArray(const std::string& name, int* values, int count);
		void SetFloat(const std::string& name, float value);
		void SetFloat2(const std::string& name, const glm::vec2& value);
		void SetFloat3(const std::string& name, const glm::vec3& value);
		void SetFloat4(const std::string& name, const glm::vec4& value);
		void SetMat4(const std::string& name, const glm::mat4& value);

		const std::string& GetName() const { return m_Name; };
	
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