#include "log.hpp"

namespace Phantom
{

std::shared_ptr<spdlog::logger> Log::m_core_logger;
std::shared_ptr<spdlog::logger> Log::m_client_logger;

void Log::Init()
{
    spdlog::set_pattern("%^[%T] %n: %v%$");
    m_core_logger =   spdlog::stdout_color_mt("PhantomCore"); // Returns shared pointer. No need to wrap with make_shared
    m_client_logger = spdlog::stdout_color_mt("App");

    m_core_logger->set_level(spdlog::level::trace); // Prints everything which is above trace level messages
    m_client_logger->set_level(spdlog::level::trace);
}

}
