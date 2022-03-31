#pragma once

#include "../resource/ResourceManager.hpp"
#include "manager/LoggerManager.hpp"

namespace gbl {
	namespace core {
		struct SharedContext {
			public:
				SharedContext() {
					m_resourceManager = gbl::resource::ResourceManager::getInstance();
				}

				gbl::resource::ResourceManager* m_resourceManager;
		};
	}
}