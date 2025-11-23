#include <Window.h>
#define GLFW_INCLUDE_VULKAN
#include <GLFW/glfw3.h>

HayKyo_Core::Window::Window(Window_Settings *param) : m_param(*param)
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

	m_window = glfwCreateWindow(m_param.width, m_param.height, m_param.application_name, m_param.monitor, NULL);

	if (!m_window)
	{
		glfwTerminate();
		return -1;
	}

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
	glfwDestroyWindow(m_window);
	glfwTerminate();
	return 0;
}

void HayKyo_Core::Window::render() {
	
}

void HayKyo_Core::Window::swapBuffers() {
	glfwSwapBuffers(m_window);
}

void HayKyo_Core::Window::pollEvent() {
	glfwPollEvents();
}