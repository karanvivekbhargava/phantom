#include "entry_point.hpp"

extern Phantom::Application* Phantom::CreateApplication();

int main(int argc, char** argv)
{
	auto app = Phantom::CreateApplication();
	app->Run();
	delete app;
}
