workspace "DemoEngine"
	architecture 'x64'

	configurations {
		"Debug",
		"Release",
		"Dist"
	}

outputdir = "%{cfg.buildcfg}-%{cfg.system}-%{cfg.architecture}"

IncludeDir = {}
IncludeDir["GLFW"] = "DemoEngine/thirdparty/GLFW/include"

include "DemoEngine/thirdparty/GLFW"

project "DemoEngine"
	location "DemoEngine"
	kind "SharedLib"
	language "C++"

	targetdir ("bin/" .. outputdir .. "/%{prj.name}")
	objdir ("bin-int/" .. outputdir .. "/%{prj.name}")

	pchheader "pch.h"
	pchsource "DemoEngine/src/pch.cpp"

	files {
		"%{prj.name}/src/**.h",
		"%{prj.name}/src/**.cpp"
	}

	includedirs {
		"%{prj.name}/src",
		"%{prj.name}/thirdparty/spdlog/include",
		"%{IncludeDir.GLFW}"
	}

	links {
		"GLFW",
		"opengl32.lib",
		"dwmapi.lib"
	}

	filter "system:windows"
		cppdialect "C++17"
		staticruntime "Off"
		systemversion "latest"

		defines {
			"DEMOENGINE_PLATFORM_WINDOWS",
			"DEMOENGINE_BUILD_DLL"
		}

		postbuildcommands {
			("{COPY} %{cfg.buildtarget.relpath} ../bin/" .. outputdir .. "/Sandbox")
		}

	filter "configurations:Debug"
		defines "DEMOENGINE_DEBUG"
		symbols "On"

	filter "configurations:Release"
		defines "DEMOENGINE_RELEASE"
		optimize "On"

	filter "configurations:Dist"
		defines "DEMOENGINE_DIST"
		optimize "On"

project "Sandbox"
	location "Sandbox"
	kind "ConsoleApp"
	language "C++"

	targetdir ("bin/" .. outputdir .. "/%{prj.name}")
	objdir ("bin-int/" .. outputdir .. "/%{prj.name}")

	files {
		"%{prj.name}/src/**.h",
		"%{prj.name}/src/**.cpp"
	}

	includedirs {
		"DemoEngine/thirdparty/spdlog/include",
		"DemoEngine/src"
	}

	links {
		"DemoEngine"
	}

	filter "system:windows"
		cppdialect "C++17"
		staticruntime "On"
		systemversion "latest"

		defines {
			"DEMOENGINE_PLATFORM_WINDOWS"
		}

	filter "configurations:Debug"
		defines "DEMOENGINE_DEBUG"
		symbols "On"

	filter "configurations:Release"
		defines "DEMOENGINE_RELEASE"
		optimize "On"

	filter "configurations:Dist"
		defines "DEMOENGINE_DIST"
		optimize "On"