//Standard C++ Library Includes
#include <iostream>

//Boost Library Includes
#include <boost/log/core.hpp>
#include <boost/log/trivial.hpp>
#include <boost/log/expressions.hpp>
#include <boost/log/utility/setup/file.hpp>
#include <boost/log/utility/setup/common_attributes.hpp>

//GameBaseLibrary Includes
#include <core/logging/StreamLogger.hpp>
#include <core/Utils.hpp>

gbl::core::StreamLogger* gbl::core::StreamLogger::m_instance = nullptr;

gbl::core::StreamLogger* gbl::core::StreamLogger::getInstance()
{
	if (m_instance == nullptr) {
		m_instance = new StreamLogger();
	}

	return m_instance;
}

void gbl::core::StreamLogger::init()
{
	std::string directory = "logs";

	if (!folder_exists(directory) && makedir(directory.c_str()) != 0) {
		std::cerr << "cannot create directory " + directory << std::endl;
		return;
	}

	time_t now = time(0);
	tm ltm;
	localtime_s(&ltm, &now);
	char buffer[50];
	strftime(buffer, 50, "%Y-%m-%d", &ltm);
	std::string filename = directory + "/" + std::string(buffer) + ".log";

	boost::log::register_simple_formatter_factory<boost::log::trivial::severity_level, char>("Severity");
	boost::log::add_file_log(
		boost::log::keywords::file_name = filename.c_str(),
		boost::log::keywords::open_mode = std::ios_base::app,
		boost::log::keywords::format = "[%TimeStamp%] [%ThreadID%] [%Severity%] %Message%"
	);
	boost::log::add_common_attributes();
}

void gbl::core::StreamLogger::trace(const std::string& msg)
{
	BOOST_LOG_TRIVIAL(trace) << msg;
}

void gbl::core::StreamLogger::debug(const std::string& msg)
{
	BOOST_LOG_TRIVIAL(debug) << msg;
}

void gbl::core::StreamLogger::info(const std::string& msg)
{
	BOOST_LOG_TRIVIAL(info) << msg;
}

void gbl::core::StreamLogger::warning(const std::string& msg)
{
	BOOST_LOG_TRIVIAL(warning) << msg;
}

void gbl::core::StreamLogger::error(const std::string& msg)
{
	BOOST_LOG_TRIVIAL(error) << msg;
}

void gbl::core::StreamLogger::fatal(const std::string& msg)
{
	BOOST_LOG_TRIVIAL(fatal) << msg;
}

gbl::core::StreamLogger::StreamLogger()
{
	init();
}
