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
    inline static std::shared_ptr<spdlog::logger>& getCoreLogger()
    {
        return m_core_logger;
    }
    inline static std::shared_ptr<spdlog::logger>& getClientLogger()
    {
        return m_client_logger;
    }
  private:
    static std::shared_ptr<spdlog::logger> m_client_logger;
    static std::shared_ptr<spdlog::logger> m_core_logger;
};

}

#define PHTM_CORE_FATAL(...) ::Phantom::Log::getCoreLogger()->fatal(__VA_ARGS__)
#define PHTM_CORE_ERROR(...) ::Phantom::Log::getCoreLogger()->error(__VA_ARGS__)
#define PHTM_CORE_WARN(...)  ::Phantom::Log::getCoreLogger()->warn(__VA_ARGS__)
#define PHTM_CORE_INFO(...)  ::Phantom::Log::getCoreLogger()->info(__VA_ARGS__)
#define PHTM_CORE_TRACE(...) ::Phantom::Log::getCoreLogger()->trace(__VA_ARGS__)


#define PHTM_CLIENT_FATAL(...) ::Phantom::Log::getClientLogger()->fatal(__VA_ARGS__)
#define PHTM_CLIENT_ERROR(...) ::Phantom::Log::getClientLogger()->error(__VA_ARGS__)
#define PHTM_CLIENT_WARN(...)  ::Phantom::Log::getClientLogger()->warn(__VA_ARGS__)
#define PHTM_CLIENT_INFO(...)  ::Phantom::Log::getClientLogger()->info(__VA_ARGS__)
#define PHTM_CLIENT_TRACE(...) ::Phantom::Log::getClientLogger()->trace(__VA_ARGS__)
