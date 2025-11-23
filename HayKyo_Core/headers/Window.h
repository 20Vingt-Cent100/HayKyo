#pragma once
#include <cstdint>
#include <GLFW/glfw3.h>

namespace HayKyo_Core {
	struct Window_Settings {
		std::uint16_t width;
		std::uint16_t height;
		const char* application_name;
		GLFWmonitor* monitor;
	};

	class Window {
	private:
		GLFWwindow* m_window = nullptr;
		Window_Settings& m_param;

		int init();
		int loop();
		void render();
		void swapBuffers();
		void pollEvent();

	public:
		Window(Window_Settings* param);
		~Window();
	};
}