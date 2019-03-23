#include "phantom/entry_point.hpp"

extern Phantom::Application* Phantom::CreateApplication();

int main(int argc, char** argv)
{
    Phantom::Log::Init();
    PHTM_CORE_ERROR("App!");
    int a = 100;
    PHTM_CLIENT_TRACE("Core: var={0}!", a);
	auto app = Phantom::CreateApplication();
	app->Run();
	delete app;
}
