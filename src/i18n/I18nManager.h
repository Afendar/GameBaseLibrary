#pragma once

#include <string>
#include <map>
#include <fstream>
#include <iostream>

#include "Locales.h"
#include "../utils/System.h"
#include "../lib/json.hpp"

namespace GDLib {
	namespace I18n {
		class I18nManager {
			public:

				static I18nManager& getInstance() {

				}

				bool initLang(const char* lcid) {
					const char** found = std::find(std::begin(GDLib::I18n::locale_list), std::end(GDLib::I18n::locale_list), lcid);

					if (found == std::end(GDLib::I18n::locale_list)) {
						return false;
					}

					int pos = std::distance(GDLib::I18n::locale_list, found);
					m_lcidName = GDLib::I18n::locale_names[pos];

					return loadTranslationFile(lcid);
				}

				const std::string translate(const std::string& key) const {
					return std::string();
				}

				const std::string getLangString() const {
					return m_lcidName;
				}

				I18nManager() {
				}

			private:

				const std::string getPath(const std::string& path) {
					return std::string();
				}

				bool loadTranslationFile(const std::string& filename){
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

				void parseTranslations(nlohmann::json& translations, const std::string& parentKey) {
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

				void addTranslation(std::string& key, const std::string& msg) {
					m_translations[key] = msg;
				}

				typedef std::map<std::string, std::string> Translations;
				Translations m_translations;
				char* m_lcid;
				std::string m_lcidName;
		};
	}
}