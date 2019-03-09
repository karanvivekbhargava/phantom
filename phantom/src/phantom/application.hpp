#pragma once

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
