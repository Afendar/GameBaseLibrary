/**
 *
 *
 * @file src/assets/AssetsLoader.h
 * @author Afendar
 */

#pragma once

#include <string>
#include <unordered_map>
#include <iostream>
#include <fstream>
#include <sstream>

#include "../defines.h"
#include "../lib/json.hpp"

using json = nlohmann::json;

namespace GDLib {
	namespace Assets {
		template<typename Derived, typename T>
		class GDLIB_API AssetsLoader {
			public:

				AssetsLoader(const std::string& pathsFile);
				virtual ~AssetsLoader();

				T* get(const std::string& id);

				std::string getPath(const std::string& id);

				bool requireAsset(const std::string& id);
				bool releaseAsset(const std::string& id);

				void purgeAssets();

			protected:

				T* load(const std::string& path);

			private:

				std::pair<T*, unsigned int>* find(const std::string& id);

				bool unload(const std::string& id);

				void loadPaths(const std::string& pathFile);

				std::unordered_map<std::string, std::pair<T*, unsigned int>> m_resources;
				std::unordered_map<std::string, std::string> m_paths;
		};
	}
}