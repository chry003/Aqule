#pragma once

#include "aqpcz.hpp"
#include "Aqule/Core/Core.hpp"

// TODO: add event dispather

namespace Aq {

	enum EventType
	{
		None = 0,
		WindowClose, WindowResize,
		MousePosition,
		KeyboardKeys
	};


#define EVENT_CLASS_TYPE(type) static EventType GetStaticType() { return EventType::type; }\
								virtual EventType GetEventType() const override { return GetStaticType(); }\
								virtual const char* GetName() const override { return #type; }

	class Event
	{
	public:

		virtual EventType GetEventType() const = 0;
		virtual const char* GetName() const = 0;
		virtual std::string ToString() const { return GetName(); }

	};

}
