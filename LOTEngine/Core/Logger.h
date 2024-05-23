#pragma once

#include <spdlog/spdlog.h>
#include <string>
#include <memory>
#include <vector>
#include <sstream>

namespace LOT
{
	class Logger
	{
	public:
		static void Init(const std::string& name = "LOTLogger");
		inline static std::shared_ptr<spdlog::logger> GetEngineLogger() { return s_EngineLogger; }
		inline static std::shared_ptr<spdlog::logger> GetLogger() { return s_Logger; }

		static void SaveLastLog();
		static void Clear();
		static const std::vector<std::string>& GetLogs();

	private:
		inline static std::shared_ptr<spdlog::logger> s_EngineLogger;
		inline static std::shared_ptr<spdlog::logger> s_Logger;
		inline static std::vector<std::string> s_Logs;
		inline static std::ostringstream s_Stream;
	};
}

#ifdef LOT_ENGINE
	#define LOT_LOG_INFO(...)		(LOT::Logger::GetEngineLogger()->info(__VA_ARGS__), LOT::Logger::SaveLastLog())
	#define LOT_LOG_WARN(...)		(LOT::Logger::GetEngineLogger()->warn(__VA_ARGS__), LOT::Logger::SaveLastLog())
	#ifdef LOT_ENGINE_DEBUG
		#define LOT_LOG_DEBUG(...)	(LOT::Logger::GetEngineLogger()->debug(__VA_ARGS__), LOT::Logger::SaveLastLog())
	#else
		#define LOT_LOG_DEBUG(...)
	#endif
	#define LOT_LOG_ERROR(...)		(LOT::Logger::GetEngineLogger()->error(__VA_ARGS__), LOT::Logger::SaveLastLog())
	#define LOT_LOG_CRITICAL(...)	(LOT::Logger::GetEngineLogger()->critical(__VA_ARGS__), LOT::Logger::SaveLastLog(), throw)
	#define LOT_LOG_TRACE(...)		(LOT::Logger::GetEngineLogger()->trace(__VA_ARGS__), LOT::Logger::SaveLastLog())
#else
	#define LOT_LOG_INFO(...)		(LOT::Logger::GetLogger()->info(__VA_ARGS__), LOT::Logger::SaveLastLog())
	#define LOT_LOG_WARN(...)		(LOT::Logger::GetLogger()->warn(__VA_ARGS__), LOT::Logger::SaveLastLog())
#ifdef LOT_DEBUG
	#define LOT_LOG_DEBUG(...)		(LOT::Logger::GetLogger()->debug(__VA_ARGS__), LOT::Logger::SaveLastLog())
#else
	#define LOT_LOG_DEBUG(...)
#endif
	#define LOT_LOG_ERROR(...)		(LOT::Logger::GetLogger()->error(__VA_ARGS__), LOT::Logger::SaveLastLog())
	#define LOT_LOG_CRITICAL(...)	(LOT::Logger::GetLogger()->critical(__VA_ARGS__), LOT::Logger::SaveLastLog(), throw)
	#define LOT_LOG_TRACE(...)		(LOT::Logger::GetLogger()->trace(__VA_ARGS__), LOT::Logger::SaveLastLog(), __VA_ARGS__))
#endif
