#include "aqpcz.hpp"
#include "LinuxWindow.hpp"

#include "Aqule/Event/Event.hpp"
#include "Aqule/Event/ApplicationEvent.hpp"
#include "Aqule/Event/KeyboardEvent.hpp"
#include "Aqule/Event/MouseEvent.hpp"

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
		m_Data.IsAlive = true;

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

		//////////////////////////////////////////////
		//				Window Event 				//
		//////////////////////////////////////////////

		glfwSetWindowCloseCallback(m_Window, [](GLFWwindow* window)
		{
			WindowData& data = *(WindowData*)glfwGetWindowUserPointer(window);
			data.IsAlive = false;
			WindowCloseEvent event;
			data.EventCallback(event);
		});

		glfwSetWindowSizeCallback(m_Window, [](GLFWwindow* window, int width, int height)
		{
			WindowData& data = *(WindowData*)glfwGetWindowUserPointer(window);
			data.Width = width;
			data.Height = height;

			WindowSizeEvent event(width, height);
			data.EventCallback(event);
		});

		glfwSetWindowPosCallback(m_Window, [](GLFWwindow* window, int xpos, int ypos)
		{
			WindowData& data = *(WindowData*)glfwGetWindowUserPointer(window);

			WindowPosEvent event(xpos, ypos);
			data.EventCallback(event);
		});

		glfwSetWindowRefreshCallback(m_Window, [](GLFWwindow* window)
		{
			WindowData& data = *(WindowData*)glfwGetWindowUserPointer(window);

			WindowRefreshEvent event;
			data.EventCallback(event);

		});

		glfwSetWindowFocusCallback(m_Window, [](GLFWwindow* window, int focused)
		{
			WindowData& data = *(WindowData*)glfwGetWindowUserPointer(window);

			WindowFocusedEvent event(focused);
			data.EventCallback(event);
		});

		//////////////////////////////////////////////
		//				Keyboard Event 				//
		//////////////////////////////////////////////

        glfwSetKeyCallback(m_Window, [](GLFWwindow* window, int key, int scancode, int action, int mods)
        {
            WindowData& data = *(WindowData*)glfwGetWindowUserPointer(window);

            switch (action)
            {
            	case GLFW_PRESS:
            	{
            		KeyPressedEvent event(key, 0);
            		data.EventCallback(event);
            		break;
            	}
            	case GLFW_RELEASE:
            	{
            		KeyReleasedEvent event(key);
            		data.EventCallback(event);
            		break;
            	}
            	case GLFW_REPEAT:
            	{
            		KeyPressedEvent event(key, 1);
            		data.EventCallback(event);
            		break;
            	}
            }

        });


		//////////////////////////////////////////////
		//				Mouse Event 				//
		//////////////////////////////////////////////

		glfwSetCursorPosCallback(m_Window, [](GLFWwindow* window, double xpos, double ypos)
        {
            WindowData& data = *(WindowData*)glfwGetWindowUserPointer(window);
            MousePositionEvent event((float)xpos, (float)ypos);
            data.EventCallback(event);
        });

        glfwSetMouseButtonCallback(m_Window, [](GLFWwindow* window, int button, int action, int mods)
        {
            WindowData& data = *(WindowData*)glfwGetWindowUserPointer(window);

            switch (action)
          	{
          		case GLFW_PRESS:
          		{
		            MouseButtonPressedEvent event(button);
		            data.EventCallback(event);
		            break;
          		}
          		case GLFW_RELEASE:
          		{
		            MouseButtonReleasedEvent event(button);
		            data.EventCallback(event);
		            break;
          		}
          	}
        });

        glfwSetScrollCallback(m_Window, [](GLFWwindow* window, double xoffset, double yoffset)
        {
        	WindowData& data = *(WindowData*)glfwGetWindowUserPointer(window);
        	MouseScrollEvent event((float)xoffset, (float)yoffset);
        	data.EventCallback(event);
        });
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

	bool LinuxWindow::IsVSync() const
	{
		return m_Data.VSync;
	}

	bool LinuxWindow::IsAlive() const
	{
		return m_Data.IsAlive;
	}

}
