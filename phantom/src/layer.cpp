#include "phantom/layers/layer.hpp"

namespace Phantom
{
    Layer::Layer(const std::string& name)
    {
        m_debug_name = name;
    }

    Layer::~Layer()
    {

    }
}
