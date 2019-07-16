/**
 * 
 * 
 * @file src/assets/FontsLoader.h
 * @author Afendar
 */

#pragma once

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