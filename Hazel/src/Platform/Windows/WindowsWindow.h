#pragma once

#include "Hazel/Window.h"

#include <GLFW/glfw3.h>

namespace Hazel
{
    class WindowsWindow : public Window
    {
    public:

        WindowsWindow(const WindowProps & props);
        ~WindowsWindow() override;

        void OnUpdate() override;

        [[nodiscard]] unsigned int GetWidth() const override { return m_Data.Width; }
        [[nodiscard]] unsigned int GetHeight() const override { return m_Data.Height; }

        // Window attributes
        void SetEventCallback(const EventCallbackFn & callback) override { m_Data.EventCallback = callback; }
        void SetVSync(bool enabled) override;
        [[nodiscard]] bool IsVSync() const override;

    private:

        virtual void Init(const WindowProps & props);
        virtual void Shutdown();

        GLFWwindow * m_Window;

        struct WindowData
        {
            std::string Title;
            unsigned int Width, Height;
            bool VSync;

            EventCallbackFn EventCallback;
        };

        WindowData m_Data;

    };
}