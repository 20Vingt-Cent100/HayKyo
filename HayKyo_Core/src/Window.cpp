#include <Window.h>

HayKyo_Core::Window::Window(Window_Settings *param) 
	: m_param(*param), m_renderer()
{
	init();
	loop();
}

HayKyo_Core::Window::~Window()
{
}

int HayKyo_Core::Window::init()
{
	if (!glfwInit())
		return -1;

	glfwWindowHint(GLFW_CLIENT_API, GLFW_NO_API);
	glfwWindowHint(GLFW_RESIZABLE, m_param.resizable);

	m_window = glfwCreateWindow(m_param.width, m_param.height, m_param.application_name, m_param.monitor, NULL);

	if (!m_window)
	{
		glfwTerminate();
		return -1;
	}

	uint32_t glfwExtensionCount = 0;
	const char** glfwExtension;

	glfwExtension = glfwGetRequiredInstanceExtensions(&glfwExtensionCount);

	m_renderer.bindAppInfo(&m_param.appInfo);
	m_renderer.createInstance();

	return 0;
}

int HayKyo_Core::Window::loop()
{
	while (!glfwWindowShouldClose(m_window))
	{
		render();
		swapBuffers();
		pollEvent();
	}

	
	return 0;
}

void HayKyo_Core::Window::render() {
	
}

void HayKyo_Core::Window::cleanup() {
	m_renderer.destroyInstance();

	glfwDestroyWindow(m_window);
	glfwTerminate();
}

void HayKyo_Core::Window::swapBuffers() {
	glfwSwapBuffers(m_window);
}

void HayKyo_Core::Window::pollEvent() {
	glfwPollEvents();
}