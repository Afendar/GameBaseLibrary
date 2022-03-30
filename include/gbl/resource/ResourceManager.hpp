#pragma once

#include <map>
#include <memory>

#include "IResourceLoader.hpp"
#include "../core/Exception.hpp"

namespace gbl {
	namespace resource {
		class ResourceManager {
			public:

				ResourceManager(const ResourceManager& resourceManager) = delete;
				ResourceManager& operator=(const ResourceManager& resourceManager) = delete;

				template<typename T, typename... Args>
				T& add(const std::string& name, Args &&... args) {
					if (has(name)) {
						throw gbl::core::Exception("Resource with type: " + typeid(T).name() + " already exists with name: " + name);
					}

					m_resources.emplace(name, std::make_shared<T>(std::forward<Args>(args)...));

					return get<T>(name);
				}

				bool has(const std::string& name) {
					return m_resources.count(name) == 1;
				}

				template<typename T>
				T& get(const std::string& name) {
					auto it = m_resources.find(name);
					if (it == m_resources.end()) {
						throw gbl::core::Exception("Unable to find resource with name: " + name);
					}

					return *std::static_pointer_cast<T>(it->second);
				}

				void clear() { m_resources.clear(); }

				static ResourceManager* getInstance() {
					if (!m_instance) {
						m_instance = new ResourceManager();
					}

					return m_instance;
				}

				template<typename ResourceLoader>
				static auto loadConfigFile(const char* jsonFilename) -> typename std::enable_if<std::is_base_of<IResourceLoader, ResourceLoader>::value>::type {
					ResourceLoader loader;
					loader.load(jsonFilename, getInstance());
				}

			private:

				ResourceManager() {}

				static ResourceManager* m_instance;

				std::map<std::string, std::shared_ptr<void>> m_resources;
		};
	}
}