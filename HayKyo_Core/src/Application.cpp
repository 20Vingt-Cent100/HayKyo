#include <Application.h>

HayKyo_Core::App::App(WindowInfo& wInfo)
	: m_winObj(std::make_unique<WindowObject>(wInfo, [this](Event& e) {this->onEvent(e); }))
{

}

void HayKyo_Core::App::Run() {
	if (m_winObj->isWindowNull()) {
		glfwTerminate();
		std::printf("Window could not be created");
	}

	while (m_winObj->windowShouldClose()) {

	}

	this->~App();
}


void HayKyo_Core::App::onEvent(Event& e) {

}

HayKyo_Core::App::~App() {
	m_winObj->~WindowObject();
}