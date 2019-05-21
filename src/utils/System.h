#pragma once

#include <string>
#include <iostream>
#include <algorithm>

#include "../system/OSDefines.h"

#ifdef RUNNING_WINDOWS
	#include <Windows.h>
	#include <Shlwapi.h>
#elif defined RUNNING_LINX
	#include <unistd.h>
#endif

namespace GDLib {
	namespace Utils {
		class System {
			public:
				#ifdef RUNNING_WINDOWS
					static std::string getWorkingDirectory() {
						HMODULE hModule = GetModuleHandle(nullptr);
						if (hModule) {
							char path[256];
							GetModuleFileName(hModule, path, sizeof(path));
							PathRemoveFileSpec(path);
							strcat_s(path, "\\");
							return std::string(path);
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
		};
		
	}
}