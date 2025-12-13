#pragma once
#include <Window.h>
#include <Event.h>

#include <memory>

namespace HayKyo_Core {
	class App
	{
	public:
		App(WindowInfo&);
		~App();

		void Run();

	private:
		std::unique_ptr<WindowObject> m_winObj = nullptr;
		void onEvent(Event&);
	};

	
}