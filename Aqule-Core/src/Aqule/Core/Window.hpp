#pragma once

#include "Aqule/Core/Core.hpp"
#include "aqpcz.hpp"

namespace Aq {

	struct WindowProps
	{
		std::string Title;
		uint32_t Width;
		uint32_t Height;

		WindowProps(const std::string& title = "Aqule Engine",
			        uint32_t width = 800,
			        uint32_t height = 600)
			: Title(title), Width(width), Height(height)
		{
		}
	};

	class Window
	{
	public:
		using EventCallbackFn = std::function<void(std::string&)>;

		virtual ~Window()
		{
			
		}

		virtual void OnUpdate() = 0;

		virtual uint32_t GetWidth() const = 0;
		virtual uint32_t GetHeight() const = 0;

		virtual void SetEventCallback(const EventCallbackFn& callback) = 0;
		virtual void SetVSync(bool enabled) = 0;
		// virtual void IsVSync() const = 0;

		static Window* Create(const WindowProps& props = WindowProps());
	};


}