#pragma once
#include <Keys.h>

namespace HayKyo_Core {
	struct Event {

	};
	

	struct InputEvent : Event {

	};

	struct MouseEvent : Event {
		MOUSE_INPUT mouseInput;
		STATE state;
	};
}