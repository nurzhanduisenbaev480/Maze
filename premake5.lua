workspace "Maze"
    architecture "x64"

    configurations
    {
        "Debug",
        "Release",
        "Dist"
    }

outputdir = "%{cfg.buildcfg}-%{cfg.system}-%{cfg.architecture}"

project "Maze"
    location "Maze"
    kind "SharedLib"
    language "C++"

    targetdir ("bin/" .. outputdir .. "/%{prj.name}")
    objdir ("bin-int/" .. outputdir .. "/%{prj.name}")

    files
    {
        "%{prj.name}/src/**.h",
        "%{prj.name}/src/**.cpp"
    }

    includedirs
    {
        "%{prj.name}/src",
        "%{prj.name}/vendor/spdlog/include"
    }

    filter "system:windows"
        cppdialect "C++17"
        staticruntime "On"
        systemversion "latest"
        defines
        {
            "MZ_PLATFORM_WINDOWS",
            "MZ_BUILD_DLL"
        }

        postbuildcommands
        {
            ("{COPY} %{cfg.buildtarget.relpath} ../bin/" .. outputdir .. "/Sandbox")
        }
    filter "configurations:Debug"
        defines "MZ_DEBUG"
        symbols "On"
    filter "configurations:Release"
        defines "MZ_Release"
        optimize "On"
    filter "configurations:Dist"
        defines "MZ_Dist"
        optimize "On"

project "Sandbox"
    location "Sandbox"
    kind "ConsoleApp"
    language "C++"

    targetdir ("bin/" .. outputdir .. "/%{prj.name}")
    objdir ("bin-int/" .. outputdir .. "/%{prj.name}")

    files
    {
        "%{prj.name}/src/**.h",
        "%{prj.name}/src/**.cpp"
    }

    includedirs
    {
        "Maze/vendor/spdlog/include",
        "Maze/src"
    }

    links 
    {
        "Maze"
    }

    filter "system:windows"
        cppdialect "C++17"
        staticruntime "On"
        
        defines
        {
            "MZ_PLATFORM_WINDOWS"
        }

    filter "configurations:Debug"
        defines "MZ_DEBUG"
        symbols "On"
    filter "configurations:Release"
        defines "MZ_Release"
        optimize "On"
    filter "configurations:Dist"
        defines "MZ_Dist"
        optimize "On"

    