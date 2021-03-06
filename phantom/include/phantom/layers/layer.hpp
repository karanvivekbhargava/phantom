#pragma once

#include "phantom/core.hpp"
#include "phantom/events/event.hpp"

namespace Phantom
{
    /**
     * @brief The Layer class
     * @details The base class for layers.
     */
    class Layer
    {
      public:
        Layer(const std::string& name = "Layer");
        virtual ~Layer();

        virtual void OnAttach() {}
        virtual void OnDetach() {}
        virtual void OnUpdate() {}
        virtual void OnImGuiRender() {}
        virtual void OnEvent(Event& event) {}

        inline const std::string& GetName() const { return m_debug_name; }

      protected:
        std::string m_debug_name;
    };
}
