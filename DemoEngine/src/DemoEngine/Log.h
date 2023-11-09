#pragma once

#include <memory>
#include "Core.h"
#include "spdlog/spdlog.h"
#include "spdlog/sinks/stdout_color_sinks.h"

namespace DemoEngine {

	class DEMOENGINE_API Log
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
#define LOG_CORE_TRACE(...) ::DemoEngine::Log::GetCoreLogger()->trace(__VA_ARGS__)
#define LOG_CORE_INFO(...)  ::DemoEngine::Log::GetCoreLogger()->info(__VA_ARGS__)
#define LOG_CORE_WARN(...)  ::DemoEngine::Log::GetCoreLogger()->warn(__VA_ARGS__)
#define LOG_CORE_ERROR(...) ::DemoEngine::Log::GetCoreLogger()->error(__VA_ARGS__)
#define LOG_CORE_FATAL(...) ::DemoEngine::Log::GetCoreLogger()->fatal(__VA_ARGS__)

// Client log macros
#define LOG_TRACE(...)      ::DemoEngine::Log::GetClientLogger()->trace(__VA_ARGS__)
#define LOG_INFO(...)       ::DemoEngine::Log::GetClientLogger()->info(__VA_ARGS__)
#define LOG_WARN(...)       ::DemoEngine::Log::GetClientLogger()->warn(__VA_ARGS__)
#define LOG_ERROR(...)      ::DemoEngine::Log::GetClientLogger()->error(__VA_ARGS__)
#define LOG_FATAL(...)      ::DemoEngine::Log::GetClientLogger()->fatal(__VA_ARGS__)