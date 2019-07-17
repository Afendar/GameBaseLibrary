#include "FileLogger.h"

namespace GDLib {
	namespace Logger {
		FileLogger::FileLogger(const char* filename) : LoggerInterface() {
			m_fileStream.open(filename);
			if (m_fileStream.is_open()) {
				logMessage(Severity::S_INFO, __FILE__, __LINE__, "FileLogger::ctor()");
			}
		}

		FileLogger::~FileLogger() {
			if (m_fileStream.is_open()) {
				logMessage(Severity::S_INFO, __FILE__, __LINE__, "FileLogger::dtor()");
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

		std::ostream& FileLogger::getStream(Severity severity, const char* file, int line, int exitCode) {
			std::ostream* result = nullptr;
			if (m_fileStream.is_open()) {
				result = &m_fileStream;
				writeHeader(m_fileStream, severity, file, line);
			}
			return *result;
		}

		void FileLogger::logMessage(const char* message) {
			if (m_fileStream.is_open()) {
				m_fileStream << message << std::endl;
			}
		}

		void FileLogger::logMessage(Severity severity, const char* file, int line, const char* message) {
			if (m_fileStream.is_open()) {
				writeHeader(m_fileStream, severity, file, line);
				m_fileStream << message << std::endl;
			}
		}
	}
}