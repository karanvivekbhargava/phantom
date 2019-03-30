#pragma once

#include "phantom/layers/layer.hpp"

namespace Phantom
{
    class ImguiLayer : public Layer
    {
    public:
        ImguiLayer();
        ~ImguiLayer() override;
        void OnAttach();
        void OnDetach();
        void OnUpdate() override;
        void OnEvent(Event& event) override;
    private:

    };
}
