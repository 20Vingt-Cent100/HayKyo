#pragma once
#include <cstdint>
#include <Window.h>
#include <memory>

namespace HayKyo_Core{
	struct Application_Param {
		HayKyo_Core::Window_Settings window_settings;
		uint16_t frame_rate;
	};

	class Application
	{
	public:
		Application(Application_Param* param);
		~Application();

	private:
		Application_Param& m_param;
		std::unique_ptr<Window> m_window;
	};
}