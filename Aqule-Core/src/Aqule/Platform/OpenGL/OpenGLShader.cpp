#include "OpenGLShader.hpp"
#include "Aqule/Utils/FileUtils.hpp"
#include "Aqule/Core/log.hpp"

#include <glm/gtc/type_ptr.hpp>

// Shader -> Load -> Compile -> Create Program -> Delete Shader Source ID -> Bind(client side)


namespace Aq {

	Shader* Shader::Create(const std::string& name, const std::string& vertexSrc, const std::string& fragmentSrc)
	{
		return new OpenGLShader(name, vertexSrc, fragmentSrc);
	}

	OpenGLShader::OpenGLShader(const std::string& name, const std::string& vertexSrc, const std::string& fragmentSrc)
		: m_Name(name)
	{
		Load(vertexSrc, fragmentSrc);
	}

	OpenGLShader::~OpenGLShader() 
	{
		Unbind();
		glDeleteProgram(m_ShaderID);
	}

	void OpenGLShader::Bind() const 
	{
		glUseProgram(m_ShaderID);
	}

	void OpenGLShader::Unbind() const 
	{
		glUseProgram(0);
	}

	void OpenGLShader::SetInt(const std::string& name, int value) 
	{
		glUniform1i(getUniformLocation(name.c_str()), value);
	}

	void OpenGLShader::SetIntArray(const std::string& name, int* values, int count) 
	{
		glUniform1iv(getUniformLocation(name.c_str()), count, values);
	}

	void OpenGLShader::SetFloat(const std::string& name, float value) 
	{
		glUniform1f(getUniformLocation(name.c_str()), value);
	}

	void OpenGLShader::SetFloat2(const std::string& name, const glm::vec2& value) 
	{
		glUniform2f(getUniformLocation(name.c_str()), value.x, value.y);
	}

	void OpenGLShader::SetFloat3(const std::string& name, const glm::vec3& value) 
	{
		glUniform3f(getUniformLocation(name.c_str()), value.x, value.y, value.z);
	}

	void OpenGLShader::SetFloat4(const std::string& name, const glm::vec4& value) 
	{
		glUniform4f(getUniformLocation(name.c_str()), value.x, value.y, value.z, value.w);
	}

	void OpenGLShader::SetMat4(const std::string& name, const glm::mat4& value) 
	{
		glUniformMatrix3fv(getUniformLocation(name.c_str()), 1, GL_FALSE, glm::value_ptr(value));
	}

	void OpenGLShader::Load(const std::string& vertexSrc, const std::string& fragmentSrc) 
	{
		// std::string VertexShaderCode = ReadFile(vertexSrc.c_str());
		// char const* VertexSourcePointer = VertexShaderCode.c_str();

		// std::string FragmentShaderCode = ReadFile(fragmentSrc.c_str());
		// char const* FragmentSourcePointer = FragmentShaderCode.c_str();

		// CompileShader(VertexSourcePointer, FragmentSourcePointer);

		GLuint VertexShaderID = glCreateShader(GL_VERTEX_SHADER);
		GLuint FragmentShaderID = glCreateShader(GL_FRAGMENT_SHADER);

		GLint Result = GL_FALSE;
		int InfoLogLength;

		std::string VertexShaderCode = ReadFile(vertexSrc.c_str());
		char const * VertexSourcePointer = VertexShaderCode.c_str();

		glShaderSource(VertexShaderID, 1, &VertexSourcePointer , NULL);
		glCompileShader(VertexShaderID);

		glGetShaderiv(VertexShaderID, GL_COMPILE_STATUS, &Result);
		glGetShaderiv(VertexShaderID, GL_INFO_LOG_LENGTH, &InfoLogLength);
		if ( InfoLogLength > 0 )
		{
			std::vector<char> VertexShaderErrorMessage(InfoLogLength+1);
			glGetShaderInfoLog(VertexShaderID, InfoLogLength, NULL, &VertexShaderErrorMessage[0]);
			AQ_CORE_ERROR("Failed to create Vertex Shader: {0}", &VertexShaderErrorMessage[0]);
		}

		std::string FragmentShaderCode = ReadFile(fragmentSrc.c_str());
		char const * FragmentSourcePointer = FragmentShaderCode.c_str();
		
		glShaderSource(FragmentShaderID, 1, &FragmentSourcePointer , NULL);
		glCompileShader(FragmentShaderID);

		// Check Fragment Shader
		glGetShaderiv(FragmentShaderID, GL_COMPILE_STATUS, &Result);
		glGetShaderiv(FragmentShaderID, GL_INFO_LOG_LENGTH, &InfoLogLength);
		if ( InfoLogLength > 0 )
		{
			std::vector<char> FragmentShaderErrorMessage(InfoLogLength+1);
			glGetShaderInfoLog(FragmentShaderID, InfoLogLength, NULL, &FragmentShaderErrorMessage[0]);
			AQ_CORE_ERROR("Failed to create Fragment Shader: {0}", &FragmentShaderErrorMessage[0]);
		}

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

		
		glDetachShader(ProgramID, VertexShaderID);
		glDetachShader(ProgramID, FragmentShaderID);
		
		glDeleteShader(VertexShaderID);
		glDeleteShader(FragmentShaderID);

		m_ShaderID = ProgramID;
	}

	void OpenGLShader::CompileShader(const char* VertexSourcePointer, const char* FragmentSourcePointer) 
	{
		GLuint VertexShaderID = glCreateShader(GL_VERTEX_SHADER);
		GLuint FragmentShaderID = glCreateShader(GL_FRAGMENT_SHADER);

		glShaderSource(VertexShaderID, 1, &VertexSourcePointer , NULL);
		glCompileShader(VertexShaderID);

		ShaderErr("Vertex Shader Failed!", VertexShaderID);

		glShaderSource(FragmentShaderID, 1, &FragmentSourcePointer , NULL);
		glCompileShader(FragmentShaderID);

		ShaderErr("Fragment Shader Failed!", FragmentShaderID);

		CreateProgram(VertexShaderID, FragmentShaderID);
	}

	void OpenGLShader::CreateProgram(GLuint VertexShaderID, GLuint FragmentShaderID) 
	{
		GLuint ProgramID = glCreateProgram();
		glAttachShader(ProgramID, VertexShaderID);
		glAttachShader(ProgramID, FragmentShaderID);
		glLinkProgram(ProgramID);

		ShaderErr("Failed To Create Program", ProgramID);

		// DeleteShader(ProgramID, VertexShaderID, FragmentShaderID);

		m_ShaderID = ProgramID;
	}

	void OpenGLShader::DeleteShader(GLuint ProgramID, GLuint VertexShaderID, GLuint FragmentShaderID) 
	{
		glDetachShader(ProgramID, VertexShaderID);
		glDetachShader(ProgramID, FragmentShaderID);
		
		glDeleteShader(VertexShaderID);
		glDeleteShader(FragmentShaderID);		
	}

	void OpenGLShader::ShaderErr(std::string desc, GLuint ShaderSourceID)
	{
		int InfoLogLength;

		glGetShaderiv(ShaderSourceID, GL_INFO_LOG_LENGTH, &InfoLogLength);
		if ( InfoLogLength > 0 )
		{
			std::vector<char> ShaderErrorMessage(InfoLogLength+1);
			glGetShaderInfoLog(ShaderSourceID, InfoLogLength, NULL, &ShaderErrorMessage[0]);
			AQ_CORE_ERROR("{0}", desc);
			ERR(false, &ShaderErrorMessage[0]);
		}
	}

	GLint OpenGLShader::getUniformLocation(const GLchar* name) 
	{
		return glGetUniformLocation(m_ShaderID, name);
	}

}