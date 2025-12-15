#pragma once
#include <Keys.h>

namespace HayKyo_Core {
	enum EventType {
		MOUSE_EVENT,
		KEY_EVENT,
	};

	struct Event {
		EventType e_type;
	};
	

	struct InputEvent : Event {
	};

	struct MouseEvent : Event {
		EventType e_type = MOUSE_EVENT;

		MOUSE_INPUT mouseInput;
		STATE state;
	};
}