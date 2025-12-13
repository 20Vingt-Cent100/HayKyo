/*----------Includes----------*/
#pragma once

//GLFW related Lib
#define GLFW_INCLUDE_VULKAN
#include <GLFW/glfw3.h>

//HayKyo_Core Lib
#include <Event.h>

//Standard Lib
#include <functional>
/*--------------------------*/

namespace HayKyo_Core {
	/*-- Enum for videoMode --*/
	enum VideoMode
	{
		FULLSCREEN,
		MAXIMISED,
		WINDOWED_FULLSCREEN,
		WINDOWED,
	};

	struct WindowInfo
	{
		uint16_t width;
		uint16_t height;
		const char* name;


		VideoMode videoMode;
	};

	class WindowObject
	{
	public:
		WindowObject(WindowInfo& wInfo, std::function<void(Event&)> EventReceiver);
		~WindowObject();

		void pollEvents();
		bool isWindowNull();
		int windowShouldClose();
	private:
		GLFWwindow* m_window = nullptr;
		std::function<void(Event&)>& sendEvent;

		void setCallBacks();

		void static keyInputCallbacks(GLFWwindow* window, int key, int scancode, int action, int mods);
		void static mouseInputCallbacks(GLFWwindow* window, int button, int action, int mods);
	};
}