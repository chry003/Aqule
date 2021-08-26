#pragma once

#include "Core.hpp"
#include "spdlog/spdlog.h"
#include "spdlog/fmt/ostr.h"

namespace Aq {

    class Log
    {
    public:
        static void Init();

        inline static std::shared_ptr<spdlog::logger>& GetCoreLogger() { return s_CoreLogger; }
        inline static std::shared_ptr<spdlog::logger>& GetClientLogger() { return s_CoreLogger; }
    private:
		static std::shared_ptr<spdlog::logger> s_CoreLogger;
		static std::shared_ptr<spdlog::logger> s_ClientLogger;
    };
}

// Core log macros
#define AQ_CORE_TRACE(...)    ::Aq::Log::GetCoreLogger()->trace(__VA_ARGS__)
#define AQ_CORE_INFO(...)     ::Aq::Log::GetCoreLogger()->info(__VA_ARGS__)
#define AQ_CORE_WARN(...)     ::Aq::Log::GetCoreLogger()->warn(__VA_ARGS__)
#define AQ_CORE_ERROR(...)    ::Aq::Log::GetCoreLogger()->error(__VA_ARGS__)
#define AQ_CORE_FATAL(...)    ::Aq::Log::GetCoreLogger()->fatal(__VA_ARGS__)

// Client log macros
#define AQ_TRACE(...)	      ::Aq::Log::GetClientLogger()->trace(__VA_ARGS__)
#define AQ_INFO(...)	      ::Aq::Log::GetClientLogger()->info(__VA_ARGS__)
#define AQ_WARN(...)	      ::Aq::Log::GetClientLogger()->warn(__VA_ARGS__)
#define AQ_ERROR(...)	      ::Aq::Log::GetClientLogger()->error(__VA_ARGS__)
#define AQ_FATAL(...)	      ::Aq::Log::GetClientLogger()->fatal(__VA_ARGS__)