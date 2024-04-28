#pragma once


#ifdef MZ_PLATFORM_WINDOWS
	#ifdef MZ_BUILD_DLL
		#define MAZE_API __declspec(dllexport)
	#else
		#define MAZE_API __declspec(dllimport)
	#endif // MZ_BUILD_DLL
#else
	#error Maze supports only Windows!
#endif // MZ_PLATFORM_WINDOWS

#ifdef MZ_ENABLE_ASSERTS
	#define MZ_ASSERT(x, ...) { if(!(x)) { MZ_ERROR("Assertion Failed: {0}", __VA_ARGS__); __debugbreack(); } }
	#define MZ_CORE_ASSERT(x, ...) { if(!(x)) { MZ_CORE_ERROR("Assertion Failed: {0}", __VA_ARGS__); __debugbreack(); } }
#else
	#define MZ_ASSERT(x, ...)
	#define MZ_CORE_ASSERT(x, ...)
#endif

#define BIT(x) (1 << x)
