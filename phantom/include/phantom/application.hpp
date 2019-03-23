#pragma once

#include <iostream>

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
