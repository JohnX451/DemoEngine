#pragma once

#ifdef DEMOENGINE_PLATFORM_WINDOWS
	#ifdef DEMOENGINE_BUILD_DLL
		#define DEMOENGINE_API __declspec(dllexport)
	#else
		#define DEMOENGINE_API __declspec(dllimport)
	#endif
#else
	#error Demo Engine only supported on Windows.
#endif
