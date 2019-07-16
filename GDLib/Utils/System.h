/**
 *
 *
 * @file src/utils/System.h
 * @author Afendar
 */

#pragma once

#include <string>
#include <iostream>
#include <algorithm>

#include "../defines.h"

#include "../System/OSDefines.h"

#ifdef RUNNING_WINDOWS
	#include <Windows.h>
	#include <Shlwapi.h>
#elif defined RUNNING_LINX
	#include <unistd.h>
#endif

namespace GDLib {
	namespace Utils {
		class GDLIB_API System {
			public:
				#ifdef RUNNING_WINDOWS
					static std::string getWorkingDirectory() {
						HMODULE hModule = GetModuleHandle(nullptr);
						if (hModule) {
							wchar_t path[256];
							GetModuleFileName(hModule, path, sizeof(path));
							PathRemoveFileSpec(path);
							wcscat_s(path, L"\\");
							std::wstring ws(path);
							return std::string(ws.begin(), ws.end());
						}
						return "";
					}
				#elif defined RUNNING_LINX
					static std::string getWorkingDirectory() {
						char cwd[1024];
						if (getcwd(cwd, sizeof(cwd)) != nullptr) {
							return std::string(cwd) + std::string("/");
						}
						return "";
					}
				#endif

				static std::string getCurrentDateTime()
				{
					time_t now = time(NULL);
					struct tm tstruct;
					char buf[80];
					localtime_s(&tstruct, &now);
					strftime(buf, sizeof(buf), "%Y-%m-%d %X", &tstruct);
					return buf;
				}
		};
		
	}
}