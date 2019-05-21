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
		class FontsLoader : public AssetsLoader<FontsLoader, sf::Font> {
			public:

				FontsLoader() : AssetsLoader("data/fonts.cfg") {}

				sf::Font* load(const std::string& path) {
					sf::Font* font = new sf::Font();
					if (!font->loadFromFile(
						Utils::System::getWorkingDirectory() + path
					)) {
						delete font;
						font = nullptr;
						std::cerr << "! Failed to load font: " << path << std::endl;
					}
					return font;
				}
		};
	}
}