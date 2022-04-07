#pragma once

//Standard C++ Library Includes
#include <string>
#include <sys/stat.h>
#include <sstream>

#ifdef _WIN32
#include <direct.h>
#include <Windows.h>
#endif

/**
* @param folderName Name of folder than is checked
* @return `true` if folder exist or `false` if not
*/
static inline bool folder_exists(std::string folderName)
{
	struct stat st;
	stat(folderName.c_str(), &st);
	return st.st_mode & S_IFDIR;
}

/**
* @param fileName Name of file to get creation date
* @return st_ctime of filename
*/
static inline time_t getCreationDate(std::string fileName) {
	struct stat st;
	stat(fileName.c_str(), &st);
	return st.st_ctime;
}

/**
* @param path Path of directories want to be create
* @return status of creation
*/
static inline int makedir(const char* path)
{
#ifdef _WIN32
	return ::_mkdir(path);
#else
#if _POSIX_C_SOURCE
	return ::mkdir(path);
#else
	return ::mkdir(path, 0755); // not sure if this works on mac
#endif
#endif
}

struct Resolution {
	int m_width, m_height;
};

static inline std::vector<Resolution*> getAvailableResolutions()
{
	std::vector<Resolution*> m_resolutions = {};

#ifdef _WIN32
	//WINDOWS
	DEVMODE dm = { 0 };
	dm.dmSize = sizeof(dm);

	for (int iModeNum = 0; EnumDisplaySettings(NULL, iModeNum, &dm) != 0; iModeNum++) {

		Resolution* r = new Resolution();
		r->m_width = dm.dmPelsWidth;
		r->m_height = dm.dmPelsHeight;

		if (std::find_if(
			m_resolutions.begin(),
			m_resolutions.end(),
			[&r](const Resolution* i) {
				return i->m_width == r->m_width && i->m_height == r->m_height;
			}
		) == m_resolutions.end())
			m_resolutions.push_back(r);
	}
#else
#if _POSIX_C_SOURCE
	//UNIX
#else
	//MAC
#endif
#endif

	std::sort(m_resolutions.begin(), m_resolutions.end(), [](Resolution* i, Resolution* j) { return i->m_width < j->m_width; });

	return m_resolutions;
}