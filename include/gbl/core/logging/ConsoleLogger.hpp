#pragma once

//GameBaseLibrary Includes
#include <core/logging/Logger.hpp>

namespace gbl {
	namespace core {
		class ConsoleLogger : public Logger
		{
			public:
				ConsoleLogger(ConsoleLogger& logger) = delete;
				void operator= (const ConsoleLogger&) = delete;

				static ConsoleLogger* getInstance();

				void init() override;

				void trace(const std::string& msg) override;
				void debug(const std::string& msg) override;
				void info(const std::string& msg) override;
				void warning(const std::string& msg) override;
				void error(const std::string& msg) override;
				void fatal(const std::string& msg) override;

			protected:

				ConsoleLogger();

				static ConsoleLogger* m_instance;
		};
	}
}