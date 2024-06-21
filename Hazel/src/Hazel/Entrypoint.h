#pragma once

#include "Application.h"
#include "Log.h"

#ifdef HZ_PLATFORM_WINDOWS

extern Hazel::Application* Hazel::CreateApplication();

int main(int argc, char ** argv)
{
    Hazel::Log::Init();
    HZ_CORE_INFO("Initialized Hazel Log!");
    HZ_INFO("Initialized App Log!");
    
    auto app = Hazel::CreateApplication();
    app->Run();
    delete app;
    
}

#endif
