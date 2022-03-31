#pragma once

#include <string>

namespace gbl {
	namespace core {
		class Logger
		{
			public:
				Logger() noexcept {}

				virtual void init() = 0;

				virtual void trace(const std::string& msg) = 0;
				virtual void debug(const std::string& msg) = 0;
				virtual void info(const std::string& msg) = 0;
				virtual void warning(const std::string& msg) = 0;
				virtual void error(const std::string& msg) = 0;
				virtual void fatal(const std::string& msg) = 0;
		};
	}
}