
#include "../../../../include/gbl/core/Environment.hpp"
#include "../../../../include/gbl/core/manager/LoggerManager.hpp"
#include "../../../../include/gbl/core/logging/ConsoleLogger.hpp"
#include "../../../../include/gbl/core/logging/StreamLogger.hpp"

gbl::core::Logger* gbl::core::LoggerManager::getLogger()
{
	if (DEBUG_MODE) {
		return gbl::core::ConsoleLogger::getInstance();
	}
	else {
		return gbl::core::StreamLogger::getInstance();
	}
}
