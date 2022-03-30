#pragma once

#include "IResourceLoader.hpp"

namespace gbl {
	namespace resource {
		class TextureLoader : public IResourceLoader {
			public:
				void load(const char* jsonFilename, ResourceManager* handler);
		};
	}
}