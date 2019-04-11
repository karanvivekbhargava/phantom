#pragma once

#include "phantom/core.hpp"
#include "phantom/layers/layer.hpp"

#include <vector>

namespace Phantom
{
    /**
     * @brief The LayerStack class
     * @details This is just a plain wrapper over the vector class to give
     * access to the layers. Also, we might need to iterate through either
     * end. We could use shared ptrs, however, this is a simple manager which
     * doesn't require much management. Layers generally live throughout the
     * lifetime of the application.
     */
    class LayerStack
    {
      public:
        LayerStack();
        ~LayerStack();

        void PushLayer(Layer* layer);
        void PushOverlay(Layer* overlay);
        void PopLayer(Layer* layer);
        void PopOverlay(Layer* overlay);

        std::vector<Layer*>::iterator begin() { return m_layers.begin(); }
        std::vector<Layer*>::iterator end() { return m_layers.end(); }

      private:
        std::vector<Layer*> m_layers;
        uint32_t m_layer_insert_index = 0;
    };
}
