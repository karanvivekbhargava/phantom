#include "phantom/application.hpp"

#include "phantom/events/application_event.hpp"
#include "phantom/log.hpp"

namespace Phantom
{
Application::Application()
{

}

Application::~Application()
{

}

void Application::Run()
{
    PHTM_CORE_TRACE("Welcome to Phantom Engine!");
    WindowResizeEvent e(1280, 720);
    PHTM_CORE_TRACE(e);
	while(true)
	{
	
	}
}
}
