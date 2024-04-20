#pragma once

#include <memory>
#include "Core.h"
#include "spdlog/spdlog.h"

namespace Maze {
	class MAZE_API Log
	{
	public:
		static void Init();

		inline static std::shared_ptr<spdlog::logger>& GetCoreLogger() { return s_CoreLogger; }
		inline static std::shared_ptr<spdlog::logger>& GetClientLogger() { return s_ClientLogger; }

	private:
		static std::shared_ptr<spdlog::logger> s_CoreLogger;
		static std::shared_ptr<spdlog::logger> s_ClientLogger;
	};
}
// Core log macros
#define MZ_CORE_TRACE(...)	::Maze::Log::GetCoreLogger()->trace(__VA_ARGS__)
#define MZ_CORE_INFO(...)	::Maze::Log::GetCoreLogger()->info(__VA_ARGS__)
#define MZ_CORE_WARN(...)	::Maze::Log::GetCoreLogger()->warn(__VA_ARGS__)
#define MZ_CORE_ERROR(...)	::Maze::Log::GetCoreLogger()->error(__VA_ARGS__)
#define MZ_CORE_FATAL(...)	::Maze::Log::GetCoreLogger()->fatal(__VA_ARGS__)

// Client log macros
#define MZ_TRACE(...)		::Maze::Log::GetClientLogger()->trace(__VA_ARGS__)
#define MZ_INFO(...)		::Maze::Log::GetClientLogger()->info(__VA_ARGS__)
#define MZ_WARN(...)		::Maze::Log::GetClientLogger()->warn(__VA_ARGS__)
#define MZ_ERROR(...)		::Maze::Log::GetClientLogger()->error(__VA_ARGS__)
#define MZ_FATAL(...)		::Maze::Log::GetClientLogger()->fatal(__VA_ARGS__)
