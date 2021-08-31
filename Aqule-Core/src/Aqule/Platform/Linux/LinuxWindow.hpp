#pragma once

#include "Aqule/Core/Window.hpp"

#include <GLFW/glfw3.h>

namespace Aq {

	class LinuxWindow : public Window
	{
	public:
		LinuxWindow(const WindowProps& props);
		virtual ~LinuxWindow();

		void OnUpdate() override;
		void OnClear() override;

		inline uint32_t GetWidth() const override { return m_Data.Width; };
		inline uint32_t GetHeight() const override { return m_Data.Height; };

		inline void SetEventCallback(const EventCallbackFn& callback) override { m_Data.EventCallback = callback; };
		void SetVSync(bool enabled) override;
		bool IsVSync() const override;
		bool IsAlive() const override;

	private:
		virtual void Init(const WindowProps& props);
		virtual void Terminate();

	private:
		GLFWwindow* m_Window;

		struct WindowData
		{
			std::string Title;
			uint32_t Width, Height;
			bool VSync;
			bool IsAlive;

			EventCallbackFn EventCallback;
		};

		WindowData m_Data;
	};

}