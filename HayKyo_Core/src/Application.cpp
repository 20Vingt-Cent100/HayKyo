#include <Application.h>

HayKyo_Core::Application::Application(Application_Param *param)
    : m_param(*param), m_window(std::make_unique<Window>(&m_param.window_settings))
{

}

HayKyo_Core::Application::~Application()
{
    
}