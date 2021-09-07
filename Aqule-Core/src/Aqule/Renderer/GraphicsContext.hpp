#pragma once

#include <glad/glad.h>
#include <GLFW/glfw3.h>

namespace Aq {

	class GraphicsContext
	{
	public:
		GraphicsContext(GLFWwindow* windowHandle);

		void Init();
		void SwapBuffers();

	private:
		GLFWwindow* m_WindowHandle;
	};

}