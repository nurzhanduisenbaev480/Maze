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
