#include "AssetsLoader.h"

namespace GDLib {
	namespace Assets {
		template<typename Derived, typename T>
		AssetsLoader<Derived, T>::AssetsLoader(const std::string& pathsFile) { loadPaths(pathsFile); }

		template<typename Derived, typename T>
		AssetsLoader<Derived, T>::~AssetsLoader() { purgeAssets(); }

		template<typename Derived, typename T>
		T* AssetsLoader<Derived, T>::get(const std::string& id) {
			auto res = find(id);
			return res ? res->first : nullptr;
		}

		template<typename Derived, typename T>
		std::string AssetsLoader<Derived, T>::getPath(const std::string& id) {
			auto path = m_paths.find(id);
			return path != m_paths.end() ? path->second : "";
		}

		template<typename Derived, typename T>
		bool AssetsLoader<Derived, T>::requireAsset(const std::string& id) {
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

		template<typename Derived, typename T>
		bool AssetsLoader<Derived, T>::releaseAsset(const std::string& id) {
			auto res = find(id);
			if (!res) { return false; }
			--res->second;
			if (!res->second) { unload(id); }
			return true;
		}

		template<typename Derived, typename T>
		void AssetsLoader<Derived, T>::purgeAssets() {
			std::cout << "Purging all assets:" << std::endl;
			while (m_resources.begin() != m_resources.end()) {
				std::cout << "Removing: " << m_resources.begin()->first << std::endl;
				delete m_resources.begin()->second.first;
				m_resources.erase(m_resources.begin());
			}
			std::cout << "Purging finished." << std::endl;
		}

		template<typename Derived, typename T>
		T* AssetsLoader<Derived, T>::load(const std::string& path) {
			return static_cast<Derived*>(this)->load(path);
		}

		template<typename Derived, typename T>
		std::pair<T*, unsigned int>* AssetsLoader<Derived, T>::find(const std::string& id) {
			auto itr = m_resources.find(id);
			return itr != m_resources.end() ? &itr->second : nullptr;
		}

		template<typename Derived, typename T>
		bool AssetsLoader<Derived, T>::unload(const std::string& id) {
			auto itr = m_resources.find(id);
			if (itr == m_resources.end()) { return false; }
			delete itr->second.first;
			m_resources.erase(itr);
			return true;
		}

		template<typename Derived, typename T>
		void AssetsLoader<Derived, T>::loadPaths(const std::string& pathFile) {
			std::ifstream paths;
			paths.open(Utils::System::getWorkingDirectory() + pathFile);

			if (!paths.good()) {
				std::cerr << "! Failed loading the path file: " << pathFile << std::endl;
				return;
			}

			try {
				json assets = json::parse(paths);
				for (auto it = assets.begin(); it != assets.end(); ++it)
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
	}
}