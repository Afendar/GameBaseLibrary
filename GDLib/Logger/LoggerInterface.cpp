#include "LoggerInterface.h"
#include "../Utils/System.h"

namespace GDLib {
	namespace Logger {

		LoggerInterface* LoggerInterface::m_instance = nullptr;

		LoggerInterface::LoggerInterface() {

		}

		LoggerInterface::~LoggerInterface() {
			m_instance = nullptr;
		}

		LoggerInterface* LoggerInterface::getLogger() {
			return m_instance;
		}

		void LoggerInterface::writeHeader(std::ostream& ostream, Severity severity, const char* file, int line) {
			ostream << Utils::System::getCurrentDateTime() << " ";

			switch (severity) {
				case Severity::S_INFO:
					ostream << "[INFO]";
					break;
				case Severity::S_WARNING:
					ostream << "[WARNING]";
					break;
				case Severity::S_ERROR:
					ostream << "[ERROR]";
					break;
				case Severity::S_FATAL:
					ostream << "[FATAL]";
					break;
				default:
					ostream << "[UNKNOWN]";
					break;
			}

			ostream << " " << file << " l." << line << " ";
		}
	}
}