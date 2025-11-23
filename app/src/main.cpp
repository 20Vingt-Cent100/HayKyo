#include <Application.h>

int main()
{
	HayKyo_Core::Application_Param param;
		param.window_settings.height = 900;
		param.window_settings.width = 1800;
		param.window_settings.application_name = "HayKyo_Engine!";
		param.window_settings.monitor = NULL;
		param.frame_rate = 60;

	HayKyo_Core::Application app(&param);

}