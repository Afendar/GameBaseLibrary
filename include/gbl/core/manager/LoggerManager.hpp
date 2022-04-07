#pragma once

//GameBaseLibrary Includes
#include <core/logging/Logger.hpp>

namespace gbl {
	namespace core {
		class LoggerManager
		{
			public:
				static Logger* getLogger();
		};
	}
}