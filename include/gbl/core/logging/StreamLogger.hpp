#pragma once

#include "Logger.hpp"

namespace gbl {
	namespace core {
		class StreamLogger : public Logger {
			public:
				StreamLogger(StreamLogger& logger) = delete;
				void operator= (const StreamLogger&) = delete;

				static StreamLogger* getInstance();

				void init() override;

				void trace(const std::string& msg) override;
				void debug(const std::string& msg) override;
				void info(const std::string& msg) override;
				void warning(const std::string& msg) override;
				void error(const std::string& msg) override;
				void fatal(const std::string& msg) override;

			protected:

				StreamLogger();

				static StreamLogger* m_instance;
		};
	}
}