#pragma once
#include <cstdint>
#include "GLFW/glfw3.h"

namespace HayKyo_Core {
	struct Window_Settings {
		std::uint16_t width;
		std::uint16_t height;
		const char* application_name;
	};

	class Window {


	public:
		Window();
		~Window();
	};
}