#include "aqpcz.hpp"
#include "LinuxWindow.hpp"

namespace Aq {

	static bool isGLFWWindowCreated = false;

	Window* Window::Create(const WindowProps& props)
	{
		return new LinuxWindow(props);
	}

	LinuxWindow::LinuxWindow(const WindowProps& props)
	{
		Init(props);
	}

	LinuxWindow::~LinuxWindow()
	{
		Terminate();
	}

	void LinuxWindow::Init(const WindowProps& props)
	{
		m_Data.Title = props.Title;
		m_Data.Width = props.Width;
		m_Data.Height = props.Height;

		std::cout << props.Title << ", " << props.Width << ", " << props.Height << ", " << std::endl;

		if (!isGLFWWindowCreated)
		{
			int glfwIniti = glfwInit();

			isGLFWWindowCreated = true;
		}

		m_Window = glfwCreateWindow((int)props.Width, (int)props.Height, m_Data.Title.c_str(), nullptr, nullptr);
		glfwMakeContextCurrent(m_Window);
		glfwSetWindowUserPointer(m_Window, &m_Data);
		SetVSync(true);
	}

	void LinuxWindow::Terminate()
	{
		glfwDestroyWindow(m_Window);
	}

	void LinuxWindow::OnUpdate()
	{
		glfwPollEvents();
		glfwSwapBuffers(m_Window);
	}

	void LinuxWindow::SetVSync(bool enabled)
	{
		if(enabled)
			glfwSwapInterval(1);
		else
			glfwSwapInterval(0);

		m_Data.VSync = enabled;
	}

	// bool LinuxWindow::IsVSync() const
	// {
	// 	return m_Data.VSync;
	// }

}