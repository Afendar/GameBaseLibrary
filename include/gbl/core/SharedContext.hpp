#pragma once

//GameBaseLibrary Includes
#include <resource/ResourceManager.hpp>
#include <core/manager/LoggerManager.hpp>

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