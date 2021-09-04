#pragma once

#include "Aqule/Core/KeyCodes.hpp"
#include "Aqule/Core/MouseCodes.hpp"

#include <glm/glm.hpp>

namespace Aq {

	class Input
	{
	public:
		static bool IsKeyPressed(KeyCode key);

		static bool IsMouseButtonPressed(MouseCode button);
		static glm::vec2 GetMousePosition();
		static float GetMouseX();
		static float GetMouseY();
	};


}