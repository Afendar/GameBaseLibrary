#include "FileLogger.h"

namespace GDLib {
	namespace Logger {
		FileLogger::FileLogger(const char* filename) : LoggerInterface() {
			m_fileStream.open(filename);
			if (m_fileStream.is_open()) {
				logMessage(Severity::INFO, __FILE__, __LINE__, "FileLogger::ctor()");
			}
		}

		FileLogger::~FileLogger() {
			if (m_fileStream.is_open()) {
				logMessage(Severity::INFO, __FILE__, __LINE__, "FileLogger::dtor()");
				m_fileStream.close();
			}
		}

		std::ostream& FileLogger::getStream() {
			std::ostream* result = nullptr;
			if (m_fileStream.is_open()) {
				result = &m_fileStream;
			}
			return *result;
		}

		std::ostream& FileLogger::getStream(Severity severity, const char* file, int line, int exitCode = -1) {
			std::ostream* result = nullptr;
			if (m_fileStream.is_open()) {
				result = &m_fileStream;
			}
			return *result;
		}

		void FileLogger::logMessage(const char* message) {
			m_fileStream << message << std::endl;
			
		}

		void FileLogger::logMessage(Severity severity, const char* file, int line, const char* message) {
			m_fileStream << message << std::endl;
		}

	}
}