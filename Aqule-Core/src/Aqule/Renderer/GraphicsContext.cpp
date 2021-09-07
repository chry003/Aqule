#include "aqpch.hpp"

#include "GraphicsContext.hpp"

namespace Aq {

	GraphicsContext::GraphicsContext(GLFWwindow* windowHandle)
		: m_WindowHandle(windowHandle)
	{
		ERR(windowHandle, "Window is NULL!");
	}

	void GraphicsContext::Init() 
	{
		glfwMakeContextCurrent(m_WindowHandle);
		int status = gladLoadGLLoader((GLADloadproc)glfwGetProcAddress);
		ERR(status, "GLAD FAILED!!")

		AQ_CORE_INFO("OpenGL Info:");
		AQ_CORE_INFO("Vendor: {0}", glGetString(GL_VENDOR));
		AQ_CORE_INFO("Renderer: {0}", glGetString(GL_RENDERER));
		AQ_CORE_INFO("Version: {0}", glGetString(GL_VERSION));

		ERR(GLVersion.major > 3 || (GLVersion.major == 3 && GLVersion.minor >= 3), "Aqule requires at least OpenGL version 3.3!");
	}

	void GraphicsContext::SwapBuffers() 
	{
		glfwSwapBuffers(m_WindowHandle);
	}

}