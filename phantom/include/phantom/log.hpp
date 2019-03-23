#pragma once

#include "spdlog/sinks/stdout_color_sinks.h"
#include "spdlog/spdlog.h"
#include "core.hpp"

namespace Phantom
{

class Log
{
  public:
    static void Init();
    inline static std::shared_ptr<spdlog::logger>& GetCoreLogger()
    {
        return m_core_logger;
    }
    inline static std::shared_ptr<spdlog::logger>& GetClientLogger()
    {
        return m_client_logger;
    }
  private:
    static std::shared_ptr<spdlog::logger> m_client_logger;
    static std::shared_ptr<spdlog::logger> m_core_logger;
};

}

#define PHTM_CORE_FATAL(...) ::Phantom::Log::GetCoreLogger()->fatal(__VA_ARGS__)
#define PHTM_CORE_ERROR(...) ::Phantom::Log::GetCoreLogger()->error(__VA_ARGS__)
#define PHTM_CORE_WARN(...)  ::Phantom::Log::GetCoreLogger()->warn(__VA_ARGS__)
#define PHTM_CORE_INFO(...)  ::Phantom::Log::GetCoreLogger()->info(__VA_ARGS__)
#define PHTM_CORE_TRACE(...) ::Phantom::Log::GetCoreLogger()->trace(__VA_ARGS__)


#define PHTM_CLIENT_FATAL(...) ::Phantom::Log::GetClientLogger()->fatal(__VA_ARGS__)
#define PHTM_CLIENT_ERROR(...) ::Phantom::Log::GetClientLogger()->error(__VA_ARGS__)
#define PHTM_CLIENT_WARN(...)  ::Phantom::Log::GetClientLogger()->warn(__VA_ARGS__)
#define PHTM_CLIENT_INFO(...)  ::Phantom::Log::GetClientLogger()->info(__VA_ARGS__)
#define PHTM_CLIENT_TRACE(...) ::Phantom::Log::GetClientLogger()->trace(__VA_ARGS__)
