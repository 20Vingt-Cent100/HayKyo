#include <vector>

namespace HayKyo_Core {
	class Event
	{
	public:
		static void pushEvent(Event e);
	private:
		static std::vector<Event>EVENT_STACK;
	};

	class InputEvent : Event {

	};
}