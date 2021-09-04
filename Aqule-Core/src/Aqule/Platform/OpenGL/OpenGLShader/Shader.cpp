#include "Shader.hpp"
#include "Aqule/Utils/FileUtils.hpp"
#include "Aqule/Core/log.hpp"

namespace Aq {

	Shader::Shader(const char* vertPath, const char* fragPath) 
		: m_VertPath(vertPath), m_FragPath(fragPath)
	{
		m_ShaderID = load();
	}


	Shader::~Shader() 
	{
		glDeleteProgram(m_ShaderID);
	}

	GLuint Shader::load() 
	{
		GLuint VertexShaderID = glCreateShader(GL_VERTEX_SHADER);
		GLuint FragmentShaderID = glCreateShader(GL_FRAGMENT_SHADER);

		GLint Result = GL_FALSE;
		int InfoLogLength;

		std::string VertexShaderCode = ReadFile(m_VertPath);
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

		std::string FragmentShaderCode = ReadFile(m_FragPath);
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

		return ProgramID;

	}

	GLint Shader::getUniformLocation(const GLchar* name) 
	{
		return glGetUniformLocation(m_ShaderID, name);
	}

	void Shader::enable() const
	{
		glUseProgram(m_ShaderID);
	}

	void Shader::disable() const
	{
		glUseProgram(0);
	}

	GLuint Shader::getShader() const
	{
		return m_ShaderID;
	}
}