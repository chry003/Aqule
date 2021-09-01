#pragma once

#include "Layer.hpp"

#include <vector>

namespace Aq {

	class LayerStack
	{
	public:
		LayerStack();
		~LayerStack();

		// Push Layer and Overlay
		void PushLayer(Layer* layer);
		void PushOverlay(Layer* overlay);

		// Pop Layer and Overlay
		void PopLayer(Layer* layer);
		void PopOverlay(Layer* overlay);

		std::vector<Layer*>::iterator begin() { return m_Layers.begin(); }
		std::vector<Layer*>::iterator end() { return m_Layers.end(); }

	private:
		std::vector<Layer*> m_Layers;
		std::vector<Layer*>::iterator m_LayerInsert;
	};

}

