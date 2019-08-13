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

				AssetsLoader(const std::string& type) {
					loadPaths("data/assets.cfg", type);
				}

				virtual ~AssetsLoader() {
					purgeAssets();
				}

				T* get(const std::string& id) {
					auto res = find(id);
					return res ? res->first : nullptr;
				}

				std::string getPath(const std::string& id) {
					auto path = m_paths.find(id);
					return path != m_paths.end() ? path->second : "";
				}

				bool requireAsset(const std::string& id) {
					auto res = find(id);
					if (res) {
						++res->second;
						return true;
					}
					auto path = m_paths.find(id);
					if (path == m_paths.end()) { return false; }
					T* resource = load(path->second);
					if (!resource) { return false; }
					m_resources.emplace(id, std::make_pair(resource, 1));
					return true;
				}

				bool releaseAsset(const std::string& id) {
					auto res = find(id);
					if (!res) { return false; }
					--res->second;
					if (!res->second) { unload(id); }
					return true;
				}

				void purgeAssets() {
					std::cout << "Purging all assets:" << std::endl;
					while (m_resources.begin() != m_resources.end()) {
						std::cout << "Removing: " << m_resources.begin()->first << std::endl;
						delete m_resources.begin()->second.first;
						m_resources.erase(m_resources.begin());
					}
					std::cout << "Purging finished." << std::endl;
				}

			protected:

				T* load(const std::string& path) {
					return static_cast<Derived*>(this)->load(path);
				}

			private:

				std::pair<T*, unsigned int>* find(const std::string& id) {
					auto itr = m_resources.find(id);
					return itr != m_resources.end() ? &itr->second : nullptr;
				}

				bool unload(const std::string& id) {
					auto itr = m_resources.find(id);
					if (itr == m_resources.end()) { return false; }
					delete itr->second.first;
					m_resources.erase(itr);
					return true;
				}

				void loadPaths(const std::string& pathFile, const std::string& type) {
					std::cout << "Loading paths..." << std::endl;
					std::ifstream paths;
					paths.open(Utils::System::getWorkingDirectory() + pathFile);

					if (!paths.good()) {
						std::cerr << "! Failed loading the path file: " << pathFile << std::endl;
						return;
					}

					try {
						json assets = json::parse(paths);

						if (!assets.contains(type)) {
							std::cerr << "! Failed loading the entry : " << type << ". Entry does not exist." << std::endl;
						}

						json jsonEntry = assets.at(type);

						for (auto it = jsonEntry.begin(); it != jsonEntry.end(); ++it)
						{
							m_paths.emplace(it.key(), it.value());
						}
						paths.close();
					}
					catch (json::parse_error& e)
					{
						std::cout << "message: " << e.what() << '\n' << std::endl;
						paths.close();
						return;
					}
				}

				std::unordered_map<std::string, std::pair<T*, unsigned int>> m_resources;
				std::unordered_map<std::string, std::string> m_paths;
		};
	}
}