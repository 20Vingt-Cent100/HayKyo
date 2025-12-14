#include <Application.h>

int main()
{
	HayKyo_Core::WindowInfo appInfo;
	appInfo.width = 1000;
	appInfo.height = 600;
	appInfo.videoMode = HayKyo_Core::WINDOWED;
	appInfo.name = "Vulkan";
	appInfo.resizable = false;

	HayKyo_Core::App game(appInfo);
	game.run();
}