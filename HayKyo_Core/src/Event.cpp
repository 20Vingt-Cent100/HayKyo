#include "Event.h"

void HayKyo_Core::Event::Event::pushEvent(Event e) {
	HayKyo_Core::Event::EVENT_STACK.push_back(e);
}