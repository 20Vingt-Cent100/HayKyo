#include <Application.h>

HayKyo_Core::App::App(WindowInfo& wInfo)
	: m_winObj(std::make_unique<WindowObject>(wInfo, [this](Event& e) {this->onEvent(e); }))
{

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