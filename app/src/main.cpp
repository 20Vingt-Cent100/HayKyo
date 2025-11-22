#include <Application.h>

int main()
{
	HayKyo_Core::Application_Param param;
		param.window_settings.height = 400;
		param.window_settings.width = 600;
		param.window_settings.application_name = "Hello World!";
		param.frame_rate = 60;

	HayKyo_Core::Application app(&param);

}