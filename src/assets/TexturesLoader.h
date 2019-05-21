/**
 *
 *
 * @file src/assets/TexturesLoader.h
 * @author Afendar
 */

#pragma once

#include <SFML/Graphics/Texture.hpp>

#include "AssetsLoader.h"
#include "../utils/System.h"

namespace GDLib {
	namespace Assets {
		
		class TexturesLoader : public  AssetsLoader<TexturesLoader, sf::Texture> {
			public:

				TexturesLoader() : AssetsLoader("data/textures.cfg") {}

				sf::Texture* load(const std::string& path) {
					sf::Texture* texture = new sf::Texture();
					if (!texture->loadFromFile(
						Utils::System::getWorkingDirectory() + path
					)) {
						delete texture;
						texture = nullptr;
						std::cerr << "! Failed to load texture: " << path << std::endl;
					}
					return texture;
				}
		};

	}
}