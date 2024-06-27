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

        virtual void OnUpdate() override;

        virtual unsigned int GetWidth() const override { return m_Data.Width; }
        virtual unsigned int GetHeight() const override { return m_Data.Height; }

        // Window attributes
        virtual void SetEventCallback(const EventCallbackFn & callback) override { m_Data.EventCallback = callback; }
        virtual void SetVSync(bool enabled) override;
        virtual bool IsVSync() const override;

        virtual void* GetNativeWindow() const override { return m_Window; }

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