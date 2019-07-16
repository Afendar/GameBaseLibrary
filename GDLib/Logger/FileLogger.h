#pragma once

#include <fstream>

#include "LoggerInterface.h"

namespace GDLib {
	namespace Logger {
		class GDLIB_API FileLogger : public LoggerInterface
		{
			public:
				FileLogger(const char* filename);
				virtual ~FileLogger();

				virtual std::ostream& getStream();
				virtual std::ostream& getStream(Severity severity, const char* file, int line, int exitCode = -1);

				virtual void logMessage(const char* message);
				virtual void logMessage(Severity severity, const char* file, int line, const char* message);

			protected:

			private:

				std::ofstream m_fileStream;

				FileLogger(const FileLogger&);
				FileLogger& operator=(const FileLogger&);
		};
	}
}