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

#ifdef DEMOENGINE_DEBUG
	#define DEMOENGINE_ENABLE_ASSERTS
#endif


#ifdef DEMOENGINE_ENABLE_ASSERTS
	#define DEMOENGINE_ASSERT(x, ...) { if(!(x)) { LOG_ERROR("Assertion failed: {0}", __VA_ARGS__); __debugbreak(); } }
	#define DEMOENGINE_CORE_ASSERT(x, ...) { if(!(x)) { LOG_CORE_ERROR("Assertion failed: {0}", __VA_ARGS__); __debugbreak(); } }
#else
	#define DEMOENGINE_ASSERT(x, ...)
	#define DEMOENGINE_CORE_ASSERT(x, ...)
#endif


#define BIT(x) (1 << x)