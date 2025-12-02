#pragma once
#include <cstdint>
#define GLFW_INCLUDE_VULKAN
#include <GLFW/glfw3.h>
#include "Renderer.h"

namespace HayKyo_Core {
	struct Window_Settings {
		std::uint16_t width;
		std::uint16_t height;
		const char* application_name;
		GLFWmonitor* monitor;
		bool resizable;

		ApplicationInfo appInfo;
	};

	class Window {
	private:
		GLFWwindow* m_window = nullptr;
		Renderer m_renderer;
		Window_Settings& m_param;

		int init();
		int loop();
		void render();
		void swapBuffers();
		void pollEvent();
		void cleanup();

	public:
		Window(Window_Settings* param);
		~Window();
	};
}