#pragma once

#include <iostream>

#include "../defines.h"

namespace GDLib {
	namespace Logger {

		enum Severity {
			S_INFO = 0,
			S_WARNING,
			S_ERROR,
			S_FATAL
		};

		class GDLIB_API LoggerInterface
		{
			public:

				virtual ~LoggerInterface();
				static LoggerInterface* getLogger();

				virtual std::ostream& getStream() = 0;
				virtual std::ostream& getStream(Severity severity, const char* file, int line, int exitCode = -1) = 0;

				virtual void logMessage(const char* message) = 0;
				virtual void logMessage(Severity severity, const char* file, int line, const char* message) = 0;

			protected:

				LoggerInterface();

				void writeHeader(std::ostream& ostream, Severity severity, const char* file, int line);

			private:

				static LoggerInterface* m_instance;

				LoggerInterface(const LoggerInterface&);
		};
	}
}