#include "I18nManager.h"

namespace GDLib {
	namespace I18n {

		bool I18nManager::initLang(const char* lcid) {
			const char** found = std::find(std::begin(GDLib::I18n::locale_list), std::end(GDLib::I18n::locale_list), lcid);

			if (found == std::end(GDLib::I18n::locale_list)) {
				return false;
			}

			int pos = std::distance(GDLib::I18n::locale_list, found);
			m_lcidName = GDLib::I18n::locale_names[pos];

			return loadTranslationFile(lcid);
		}

		const std::string I18nManager::translate(const std::string& key) const {
			return std::string();
		}

		const std::string I18nManager::getLangString() const {
			return m_lcidName;
		}

		I18nManager::I18nManager() {
		}

		const std::string I18nManager::getPath(const std::string& path) {
			return std::string();
		}

		bool I18nManager::loadTranslationFile(const std::string& filename) {
			m_translations.clear();
			std::ifstream file(Utils::System::getWorkingDirectory() + "data/langs/" + filename + ".json");
			if (!file.good()) {
				std::cerr << "Failed to load file " << filename + ".json" << std::endl;
				return false;
			}

			nlohmann::json translations = nlohmann::json::parse(file);
			parseTranslations(translations, std::string(""));
			return true;
		}

		void I18nManager::parseTranslations(nlohmann::json& translations, const std::string& parentKey) {
			for (nlohmann::json::iterator it = translations.begin(); it != translations.end(); ++it) {
				if (it->is_object()) {
					parseTranslations(it.value(), (parentKey != "" ? parentKey + "." : parentKey) + it.key());
				}
				else {
					std::string key(parentKey + "." + it.key());
					addTranslation(key, it.value().get<std::string>());
				}
			}
		}

		void I18nManager::addTranslation(std::string& key, const std::string& msg) {
			m_translations[key] = msg;
		}
	}
}