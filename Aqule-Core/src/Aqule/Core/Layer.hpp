#pragma once

#include "Aqule/Core/Core.hpp"
#include "Aqule/Event/Event.hpp"

namespace Aq {

	class Layer
	{
	public:
		Layer(const std::string& name = "Debug Layer");

		virtual ~Layer();
		
		virtual void OnAttach() {}
		virtual void OnDetach() {}
		virtual void OnUpdate() {}
		virtual void OnEvent(Event& event) {}

		inline const std::string& GetName() const { return	m_LayerName; }

	protected:
		std::string m_LayerName;

	};

}