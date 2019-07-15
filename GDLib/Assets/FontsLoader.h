/**
 * 
 * 
 * @file src/assets/FontsLoader.h
 * @author Afendar
 */

#pragma once

#ifdef GDLIB_EXPORTS
#define GDLIB_API __declspec(dllexport)
#else
#define GDLIB_API __declspec(dllimport)
#endif

#include <SFML/Graphics/Font.hpp>

#include "AssetsLoader.h"
#include "../utils/System.h"

namespace GDLib {
	namespace Assets {
		class GDLIB_API FontsLoader : public AssetsLoader<FontsLoader, sf::Font> {
			public:

				FontsLoader();
				~FontsLoader();
				sf::Font* load(const std::string& path);
		};
	}
}