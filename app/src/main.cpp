#include <Application.h>

int main()
{
	HayKyo_Core::WindowInfo appInfo;
	appInfo.width = 200;
	appInfo.height = 1000;
	appInfo.videoMode = HayKyo_Core::WINDOWED;
	appInfo.name = "Vulkan";

	HayKyo_Core::App game(appInfo);
	game.Run();
}