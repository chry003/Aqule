#pragma once

#include "aqpcz.hpp"
#include <glad/glad.h>


namespace Aq {

	class Shader {

	private:
		GLuint m_ShaderID;
		const char* m_VertPath;
		const char* m_FragPath;

	public:

		Shader(const char* vertPath, const char* fragPath);
		~Shader();

		void enable() const;
		void disable() const;
		GLuint getShader() const;
	private:
		GLuint load();
		GLint getUniformLocation(const GLchar* name);
	};

}