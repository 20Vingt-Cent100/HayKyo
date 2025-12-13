#include <Window.h>

HayKyo_Core::WindowObject::WindowObject(WindowInfo& wInfo, std::function<void(Event&)> EventReceiver)
	: sendEvent(EventReceiver)
{
	if (!glfwInit()) {
		std::printf("GLFW not initialized");
		glfwTerminate();
	}

	GLFWmonitor* monitor;

	switch (wInfo.videoMode)
	{
	FULLSCREEN: monitor = glfwGetPrimaryMonitor();
		break;
	default: monitor = NULL;
			break;
	}

	m_window = glfwCreateWindow(wInfo.width, wInfo.height, wInfo.name, monitor, NULL);

}

int HayKyo_Core::WindowObject::windowShouldClose() {
	return glfwWindowShouldClose(m_window);
}

bool HayKyo_Core::WindowObject::isWindowNull() {
	return (!m_window);
}

HayKyo_Core::WindowObject::~WindowObject() {
	glfwDestroyWindow(m_window);
	glfwTerminate();
}