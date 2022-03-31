#pragma once

#if defined _DEBUG
//Debug Mode
constexpr bool DEBUG_MODE = true;
constexpr auto LOGGER_TYPE = "console";
constexpr auto LOGGER_LEVEL = "debug";
#else
//Release Mode
constexpr bool DEBUG_MODE = false;
constexpr auto LOGGER_TYPE = "stream";
constexpr auto LOGGER_LEVEL = "warning";
#endif