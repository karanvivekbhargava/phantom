#include "phantom.hpp"

class Casper : public Phantom::Application
{
public:
    Casper()
    {

    }

    ~Casper()
    {

    }
};

Phantom::Application* Phantom::CreateApplication()
{
    return new Casper();
}
