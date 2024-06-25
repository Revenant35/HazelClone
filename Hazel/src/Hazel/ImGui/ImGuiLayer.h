#pragma once

#include "Hazel/Layer.h"
#include "Hazel/Events/KeyEvent.h"
#include "Hazel/Events/MouseEvent.h"
#include "Hazel/Events/WindowEvent.h"

namespace Hazel {

    class HAZEL_API ImGuiLayer : public Layer
    {
    public:
        ImGuiLayer();
        ~ImGuiLayer() override;

        void OnAttach() override;
        void OnDetach() override;
        void OnUpdate() override;
        void OnEvent(Event& event) override;

    private:
        bool OnMouseButtonPressedEvent(const MouseButtonPressedEvent & event);
        bool OnMouseButtonReleasedEvent(const MouseButtonReleasedEvent & event);
        bool OnMouseMovedEvent(const MouseMovedEvent & event);
        bool OnMouseScrolledEvent(const MouseScrolledEvent & event);
        bool OnKeyPressedEvent(const KeyPressedEvent & event);
        bool OnKeyReleasedEvent(const KeyReleasedEvent & event);
        bool OnKeyTypedEvent(const KeyTypedEvent & event);
        bool OnWindowResizeEvent(const WindowResizeEvent & event);
        
        float m_Time = 0.0f;
    };

}