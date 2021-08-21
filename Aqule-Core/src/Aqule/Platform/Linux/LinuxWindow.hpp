#pragma once

#include "Aqule/Core/Window.hpp"

#include <glad/glad.h>
#include <GLFW/glfw3.h>

namespace Aq {

	class LinuxWindow : public Window
	{
	public:
		LinuxWindow(const WindowProps& props);
		virtual ~LinuxWindow();

		void OnUpdate() override;

		inline uint32_t GetWidth() const override { return m_Data.Width; };
		inline uint32_t GetHeight() const override { return m_Data.Height; };

		inline void SetEventCallback(const EventCallbackFn& callback) override { m_Data.EventCallback = callback; };
		void SetVSync(bool enabled) override;
		// void IsVSync() const override;

	private:
		virtual void Init(const WindowProps& props);
		virtual void Terminate();
		// virtual bool IsAlive() const;

	private:
		GLFWwindow* m_Window;

		struct WindowData
		{
			std::string Title;
			uint32_t Width, Height;
			bool VSync;

			EventCallbackFn EventCallback;
		};

		WindowData m_Data;
	};

}