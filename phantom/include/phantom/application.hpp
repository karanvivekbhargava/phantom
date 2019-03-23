#pragma once

#include "phantom/events/event.hpp"
#include "phantom/log.hpp"

namespace Phantom
{
class Application
{
public:
	Application();
	virtual ~Application();
	void Run();
};

Application* CreateApplication();
}
