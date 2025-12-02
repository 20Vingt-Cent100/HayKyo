#include <Application.h>

int main()
{
	HayKyo_Core::Application_Param param;
		param.window_settings.height = 1200;
		param.window_settings.width = 1800;
		param.window_settings.application_name = "Vulkan Render";
		param.window_settings.monitor = NULL;
		param.window_settings.resizable = false;
		//param.frame_rate = 60;
		param.window_settings.appInfo.applicationName = "Vulkan";
		param.window_settings.appInfo.applicationVersion = 1;


	HayKyo_Core::Application app(&param);
}