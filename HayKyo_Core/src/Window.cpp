#include <Window.h>

HayKyo_Core::WindowObject::WindowObject(WindowInfo& wInfo, std::function<void(Event&)> EventReceiver)
	: sendEvent(EventReceiver)
{
	if (!glfwInit()) {
		std::printf("GLFW not initialized");
		glfwTerminate();
	}

	m_window = glfwCreateWindow(wInfo.width, wInfo.height, wInfo.name, NULL, NULL);

	glfwSetWindowUserPointer(m_window, this);

	setCallBacks();
}

void HayKyo_Core::WindowObject::setCallBacks() {
	glfwSetKeyCallback(m_window, keyInputCallbacks);
	glfwSetMouseButtonCallback(m_window, mouseInputCallbacks);
	glfwSetCursorPosCallback(m_window, mouseMovementCallbacks);
}

void HayKyo_Core::WindowObject::keyInputCallbacks(GLFWwindow* window, int key, int scancode, int action, int mods) {
	
}

void HayKyo_Core::WindowObject::mouseInputCallbacks(GLFWwindow* window, int button, int action, int mods) {
	auto* self = static_cast<WindowObject*>(glfwGetWindowUserPointer(window));

	if (!self)
		return;

	self->handleMouseInput(button, action, mods);
}

void HayKyo_Core::WindowObject::mouseMovementCallbacks(GLFWwindow* window, double xpos, double ypos) {

}

void HayKyo_Core::WindowObject::pollEvents() {
	glfwPollEvents();
}

void HayKyo_Core::WindowObject::handleMouseInput(int button, int action, int mods) {
	MOUSE_INPUT Mbutton;
	STATE state;

	switch (button)
	{
	case GLFW_MOUSE_BUTTON_LEFT: Mbutton = LEFT_CLICK_BUTTON;
		break;
	case GLFW_MOUSE_BUTTON_RIGHT: Mbutton = RIGHT_CLICK_BUTTON;
		break;
	case GLFW_MOUSE_BUTTON_3: Mbutton = BUTTON_1;
		break;
	case GLFW_MOUSE_BUTTON_4: Mbutton = BUTTON_2;
		break;
	case GLFW_MOUSE_BUTTON_5: Mbutton = BUTTON_3;
		break;
	case GLFW_MOUSE_BUTTON_6: Mbutton = BUTTON_4;
		break;
	case GLFW_MOUSE_BUTTON_7: Mbutton = BUTTON_5;
		break;
	case GLFW_MOUSE_BUTTON_8: Mbutton = BUTTON_6;
		break;
	default: Mbutton = UNKNOWN_BUTTON;
		break;
	}

	switch (action)
	{
	case GLFW_PRESS: state = PRESSED;
		break;
	case GLFW_RELEASE: state = RELEASED;
		break;
	default: state = UNKNOWN;
		break;
	}

	MouseEvent mouseInputEvent;
	mouseInputEvent.mouseInput = Mbutton;
	mouseInputEvent.state = state;

	sendEvent(mouseInputEvent);
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