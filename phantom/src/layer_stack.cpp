#include "phantom/layers/layer_stack.hpp"

namespace Phantom
{
LayerStack::LayerStack()
{
    m_layer_insert = m_layers.begin();
}

LayerStack::~LayerStack()
{
    for (auto& i: m_layers)
    {
        delete i;
    }
}

void LayerStack::PushLayer(Layer *layer)
{
    m_layer_insert = m_layers.emplace(m_layer_insert, layer);
}

void LayerStack::PushOverlay(Layer *overlay)
{
    m_layers.emplace_back(overlay);
}

void LayerStack::PopLayer(Layer *layer)
{
    auto it = std::find(m_layers.begin(), m_layers.end(), layer);
    if (it != m_layers.end())
    {
        m_layers.erase(it);
//        // Cherno's code, possible error here?
//        m_layer_insert--;
        // My Solution
        if (it <= m_layer_insert)
            m_layer_insert--;
    }
}

void LayerStack::PopOverlay(Layer *overlay)
{
    auto it = std::find(m_layers.begin(), m_layers.end(), overlay);
    if (it != m_layers.end())
    {
        m_layers.erase(it);
    }
}

}
