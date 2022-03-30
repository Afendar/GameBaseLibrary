#pragma once

namespace gbl {
	namespace resource {

		class ResourceManager;

		class IResourceLoader {
			public:
				virtual ~IResourceLoader() = default;

				virtual void load(const char* jsonFilename, ResourceManager* handler) = 0;
		};
	}
}