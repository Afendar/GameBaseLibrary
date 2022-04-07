//GameBaseLibrary Includes
#include <core/Environment.hpp>
#include <core/manager/LoggerManager.hpp>
#include <core/logging/ConsoleLogger.hpp>
#include <core/logging/StreamLogger.hpp>

gbl::core::Logger* gbl::core::LoggerManager::getLogger()
{
	if (DEBUG_MODE) {
		return gbl::core::ConsoleLogger::getInstance();
	}
	else {
		return gbl::core::StreamLogger::getInstance();
	}
}
