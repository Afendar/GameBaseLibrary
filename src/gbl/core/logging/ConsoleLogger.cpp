#include <boost/log/core.hpp>
#include <boost/log/trivial.hpp>
#include <boost/log/expressions.hpp>
#include <boost/log/support/date_time.hpp>
#include <boost/log/utility/setup/console.hpp>
#include <boost/log/utility/setup/common_attributes.hpp>

#include "../../../../include/gbl/core/logging/ConsoleLogger.hpp"

gbl::core::ConsoleLogger* gbl::core::ConsoleLogger::m_instance = nullptr;

gbl::core::ConsoleLogger* gbl::core::ConsoleLogger::getInstance()
{
	if (m_instance == nullptr) {
		m_instance = new ConsoleLogger();
	}

	return m_instance;
}

void gbl::core::ConsoleLogger::init()
{
}

void gbl::core::ConsoleLogger::trace(const std::string& msg)
{
	BOOST_LOG_TRIVIAL(trace) << msg;
}

void gbl::core::ConsoleLogger::debug(const std::string& msg)
{
	BOOST_LOG_TRIVIAL(debug) << msg;
}

void gbl::core::ConsoleLogger::info(const std::string& msg)
{
	BOOST_LOG_TRIVIAL(info) << msg;
}

void gbl::core::ConsoleLogger::warning(const std::string& msg)
{
	BOOST_LOG_TRIVIAL(warning) << msg;
}

void gbl::core::ConsoleLogger::error(const std::string& msg)
{
	BOOST_LOG_TRIVIAL(error) << msg;
}

void gbl::core::ConsoleLogger::fatal(const std::string& msg)
{
	BOOST_LOG_TRIVIAL(fatal) << msg;
}

gbl::core::ConsoleLogger::ConsoleLogger()
{
	init();
}
