#pragma once

#include <exception>
#include <string>
namespace gbl {
	namespace core {
		class Exception : public std::exception
		{
			public:
				Exception(const char* msg, const char* info = "", const char* file = __FILE__, int line = __LINE__) :
					std::exception(msg),
					m_file(file),
					m_line(line),
					m_info(info)
				{
				}

				const char* getFile() const { return m_file; }
				int getLine() const { return m_line; }
				const char* getInfo() const { return m_info; }
			private:
				const char* m_file, * m_info;
				int m_line;
		};
	}
}