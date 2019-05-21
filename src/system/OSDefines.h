#pragma once

#if defined(_WIN32) || defined(_WIN64)

//Windows operating system
#define RUNNING_WINDOWS

#elif defined(linux) || defined(__linux) || defined(__linux__)

//Linux operating system
#define RUNNING_LINUX

#elif defined(__APPLE__) || defined(Macintosh) || defined(macintosh)

//MAC operating system
#define RUNNING_MACINTOSH

#elif defined(__FreeBSD__)

//FreeBSD operating system
#define RUNNING_FREEBSD

#else

#error This operating system is not supported for this engine

#endif