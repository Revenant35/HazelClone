workspace "Hazel"
    architecture "x86_64"
    language "C++"

    configurations
    {
        "Debug",
        "Release",
        "Dist"
    }

    startproject "Sandbox"

    outputdir = "%{cfg.buildcfg}-%{cfg.system}-%{cfg.architecture}"
    
    -- Include directories relative to root folder (solution directory)
    IncludeDir = {}
    IncludeDir["GLFW"] = "Hazel/vendor/GLFW/include"
    IncludeDir["Glad"] = "Hazel/vendor/Glad/include"
    IncludeDir["ImGui"] = "Hazel/vendor/imgui"
    
    include "Hazel/vendor/GLFW"
    include "Hazel/vendor/Glad"
    include "Hazel/vendor/imgui"

project "Hazel"
    location "Hazel"
    kind "SharedLib"
    cppdialect "C++17"

    targetdir ("bin/" .. outputdir .. "/%{prj.name}")
    objdir ("bin-int/" .. outputdir .. "/%{prj.name}")

    pchheader "hzpch.h"
    pchsource "Hazel/src/hzpch.cpp"

    files
    {
        "%{prj.name}/src/**.h",
        "%{prj.name}/src/**.cpp"
    }

    includedirs
    {
        "%{prj.name}/src",
        "%{prj.name}/vendor/spdlog/include",
        "%{IncludeDir.GLFW}",
        "%{IncludeDir.Glad}",
        "%{IncludeDir.ImGui}"
    }

    links
    {
        "GLFW",
        "Glad",
        "ImGui",
        "opengl32.lib"
    }

    filter "system:windows"
        staticruntime "off"
        systemversion "latest"

        defines
        {
            "HZ_PLATFORM_WINDOWS",
            "HZ_BUILD_DLL",
            "HZ_ENABLE_ASSERTS",
            "GLFW_INCLUDE_NONE"
        }

        postbuildcommands
        {
            ("{COPY} %{cfg.buildtarget.relpath} ../bin/" .. outputdir .. "/Sandbox")
        }

    filter "configurations:Debug"
        defines "HZ_DEBUG"
        runtime "Debug"
        optimize "Debug"
        symbols "On"
        
    filter "configurations:Release"
        defines "HZ_RELEASE"
        runtime "Release"
        optimize "Speed"
        symbols "Off"
        
    filter "configurations:Dist"
        defines "HZ_DIST"
        runtime "Release"
        optimize "Full"
        symbols "Off"


project "Sandbox"
    location "Sandbox"
    kind "ConsoleApp"
    cppdialect "C++17"

    targetdir ("bin/" .. outputdir .. "/%{prj.name}")
    objdir ("bin-int/" .. outputdir .. "/%{prj.name}")

    files
    {
        "%{prj.name}/src/**.h",
        "%{prj.name}/src/**.cpp"
    }

    includedirs
    {
        "Hazel/vendor/spdlog/include",
        "Hazel/src"
    }

    links
    {
        "Hazel"
    }

    filter "system:windows"
        staticruntime "off"
        systemversion "latest"

        defines
        {
            "HZ_PLATFORM_WINDOWS"
        }

    filter "configurations:Debug"
        defines "HZ_DEBUG"
        runtime "Debug"
        optimize "Debug"
        symbols "On"
        
    filter "configurations:Release"
        defines "HZ_RELEASE"
        runtime "Release"
        optimize "Speed"
        symbols "Off"
    
    filter "configurations:Dist"
        defines "HZ_DIST"
        runtime "Release"
        optimize "Full"
        symbols "Off"
