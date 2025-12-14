/*-- Includes --*/
#pragma once

/*-- HayKyo_Core Librairies --*/
#include <Window.h>
#include <Event.h>
#include <Renderer.h>

/*-- Standard C++ librairies --*/
#include <memory>

/*-- Start of Application.h code --*/

namespace HayKyo_Core {
	class App
	{
	public:
		App(WindowInfo&);
		~App();

		void run();

	private:
		std::unique_ptr<WindowObject> m_winObj = nullptr;
		std::unique_ptr<Renderer> m_renderer = nullptr;

		void setupRenderer(const char* appName);

		void onEvent(Event&); //Method to redistribute events to layers
		void appLoop();	//Main application loop
	};

	
}