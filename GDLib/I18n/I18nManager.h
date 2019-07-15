#pragma once

#ifdef GDLIB_EXPORTS
#define GDLIB_API __declspec(dllexport)
#else
#define GDLIB_API __declspec(dllimport)
#endif

#include <string>
#include <map>
#include <fstream>
#include <iostream>

#include "Locales.h"
#include "../Utils/System.h"
#include "../lib/json.hpp"

namespace GDLib {
	namespace I18n {
		class GDLIB_API I18nManager {
			public:
				bool initLang(const char* lcid);

				const std::string translate(const std::string& key) const;

				const std::string getLangString() const;

				I18nManager();

			private:

				const std::string getPath(const std::string& path);

				bool loadTranslationFile(const std::string& filename);

				void parseTranslations(nlohmann::json& translations, const std::string& parentKey);

				void addTranslation(std::string& key, const std::string& msg);

				typedef std::map<std::string, std::string> Translations;
				Translations m_translations;
				char* m_lcid;
				std::string m_lcidName;
		};
	}
}