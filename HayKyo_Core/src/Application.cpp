#include <Application.h>

HayKyo_Core::App::App(WindowInfo& wInfo)
	: m_winObj(std::make_unique<WindowObject>(wInfo, [this](Event& e) {this->onEvent(e); })), m_renderer(std::make_unique<Renderer>())
{
	setupRenderer(wInfo.name);
}

void HayKyo_Core::App::setupRenderer(const char* appName) {

	try {
		m_renderer->initVulkan(appName, m_winObj->ext.extensions);
	}
	catch (std::runtime_error err) {
		std::printf(err.what());
	}
	
}

void HayKyo_Core::App::run() {
	if (m_winObj->isWindowNull()) {
		glfwTerminate();
		std::printf("Window could not be created");
	}
	appLoop();
}

void HayKyo_Core::App::appLoop() {
	while (!m_winObj->windowShouldClose()) {


		m_winObj->pollEvents();
	}
}


void HayKyo_Core::App::onEvent(Event& e) {

}

HayKyo_Core::App::~App() {

}