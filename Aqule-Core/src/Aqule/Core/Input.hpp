#pragma once

#include "Aqule/Core/KeyCodes.hpp"
#include "Aqule/Core/MouseCodes.hpp"

namespace Aq {

	class Input
	{
	public:
		static bool IsKeyPressed(KeyCode key);

		static bool IsMouseButtonPressed(MouseCode button);
		static std::pair<float, float> GetMousePosition();
		static float GetMouseX();
		static float GetMouseY();
	};


}