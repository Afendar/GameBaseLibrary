#pragma once

#include "../logging/Logger.hpp"

namespace gbl {
	namespace core {
		class LoggerManager
		{
			public:
				static Logger* getLogger();
		};
	}
}