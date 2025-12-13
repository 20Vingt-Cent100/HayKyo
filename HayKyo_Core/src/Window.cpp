#include <Window.h>

HayKyo_Core::WindowObject::WindowObject(WindowInfo& wInfo, std::function<void(Event&)> EventReceiver)
	: sendEvent(EventReceiver)
{
	if (!glfwInit()) {
		std::printf("GLFW not initialized");
		glfwTerminate();
	}

	m_window = glfwCreateWindow(wInfo.width, wInfo.height, wInfo.name, NULL, NULL);

	setCallBacks();
}

void HayKyo_Core::WindowObject::setCallBacks() {
	glfwSetKeyCallback(m_window, keyInputCallbacks);
	glfwSetMouseButtonCallback(m_window, mouseInputCallbacks);
}

void HayKyo_Core::WindowObject::keyInputCallbacks(GLFWwindow* window, int key, int scancode, int action, int mods) {
	
}

void HayKyo_Core::WindowObject::mouseInputCallbacks(GLFWwindow* window, int button, int action, int mods) {

}

void HayKyo_Core::WindowObject::pollEvents() {
	glfwPollEvents();
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