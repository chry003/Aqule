#include "Shader.hpp"
#include "Aqule/Utils/FileUtils.hpp"
#include "Aqule/Core/log.hpp"

#include <glm/gtc/type_ptr.hpp>

namespace Aq {

	Shader::Shader(const std::string& name, const std::string& vertexSrc, const std::string& fragmentSrc)
		: m_Name(name)
	{
		Load(vertexSrc, fragmentSrc);
	}

	Shader::~Shader() 
	{
		Unbind();
		glDeleteProgram(m_ShaderID);
	}

	void Shader::Bind() const 
	{
		glUseProgram(m_ShaderID);
	}

	void Shader::Unbind() const 
	{
		glUseProgram(0);
	}

	void Shader::SetInt(const std::string& name, int value) 
	{
		glUniform1i(getUniformLocation(name.c_str()), value);
	}

	void Shader::SetIntArray(const std::string& name, int* values, int count) 
	{
		glUniform1iv(getUniformLocation(name.c_str()), count, values);
	}

	void Shader::SetFloat(const std::string& name, float value) 
	{
		glUniform1f(getUniformLocation(name.c_str()), value);
	}

	void Shader::SetFloat2(const std::string& name, const glm::vec2& value) 
	{
		glUniform2f(getUniformLocation(name.c_str()), value.x, value.y);
	}

	void Shader::SetFloat3(const std::string& name, const glm::vec3& value) 
	{
		glUniform3f(getUniformLocation(name.c_str()), value.x, value.y, value.z);
	}

	void Shader::SetFloat4(const std::string& name, const glm::vec4& value) 
	{
		glUniform4f(getUniformLocation(name.c_str()), value.x, value.y, value.z, value.w);
	}

	void Shader::SetMat4(const std::string& name, const glm::mat4& value) 
	{
		glUniformMatrix4fv(getUniformLocation(name.c_str()), 1, GL_FALSE, glm::value_ptr(value));
	}

	void Shader::Load(const std::string& vertexSrc, const std::string& fragmentSrc) 
	{
		std::string VertexShaderCode = ReadFile(vertexSrc.c_str());
		char const* VertexSourcePointer = VertexShaderCode.c_str();

		std::string FragmentShaderCode = ReadFile(fragmentSrc.c_str());
		char const* FragmentSourcePointer = FragmentShaderCode.c_str();

		CompileShader(VertexSourcePointer, FragmentSourcePointer);
	}

	void Shader::CompileShader(const char* VertexSourcePointer, const char* FragmentSourcePointer) 
	{

		GLuint VertexShaderID = glCreateShader(GL_VERTEX_SHADER);
		GLuint FragmentShaderID = glCreateShader(GL_FRAGMENT_SHADER);


		glShaderSource(VertexShaderID, 1, &VertexSourcePointer , NULL);
		glCompileShader(VertexShaderID);

		ShaderErr("Failed to create Vertex Shader", VertexShaderID);
		
		glShaderSource(FragmentShaderID, 1, &FragmentSourcePointer , NULL);
		glCompileShader(FragmentShaderID);

		ShaderErr("Failed to create Fragment Shader", FragmentShaderID);

		CreateProgram(VertexShaderID, FragmentShaderID);

	}

	void Shader::CreateProgram(GLuint VertexShaderID, GLuint FragmentShaderID) 
	{
		GLint Result = GL_FALSE;
		int InfoLogLength;

		GLuint ProgramID = glCreateProgram();
		glAttachShader(ProgramID, VertexShaderID);
		glAttachShader(ProgramID, FragmentShaderID);
		glLinkProgram(ProgramID);

		// Check the program
		glGetProgramiv(ProgramID, GL_LINK_STATUS, &Result);
		glGetProgramiv(ProgramID, GL_INFO_LOG_LENGTH, &InfoLogLength);
		if ( InfoLogLength > 0 )
		{
			std::vector<char> ProgramErrorMessage(InfoLogLength+1);
			glGetProgramInfoLog(ProgramID, InfoLogLength, NULL, &ProgramErrorMessage[0]);
			AQ_CORE_ERROR("Failed to create Shader program: {0}", &ProgramErrorMessage[0]);
		}

		DeleteShader(ProgramID, VertexShaderID, FragmentShaderID);

		m_ShaderID = ProgramID;
	}

	void Shader::DeleteShader(GLuint ProgramID, GLuint VertexShaderID, GLuint FragmentShaderID) 
	{
		glDetachShader(ProgramID, VertexShaderID);
		glDetachShader(ProgramID, FragmentShaderID);
		
		glDeleteShader(VertexShaderID);
		glDeleteShader(FragmentShaderID);
	}

	void Shader::ShaderErr(std::string desc, GLuint ShaderSourceID)
	{
		int InfoLogLength;

		glGetShaderiv(ShaderSourceID, GL_INFO_LOG_LENGTH, &InfoLogLength);
		if ( InfoLogLength > 0 )
		{
			std::vector<char> ShaderErrorMessage(InfoLogLength+1);
			glGetShaderInfoLog(ShaderSourceID, InfoLogLength, NULL, &ShaderErrorMessage[0]);
			AQ_CORE_ERROR("{0}", desc);
			ERR(0, &ShaderErrorMessage[0]);
		}
	}

	GLint Shader::getUniformLocation(const GLchar* name) 
	{
		return glGetUniformLocation(m_ShaderID, name);
	}

}