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
		
		class GDLIB_API TexturesLoader : public  AssetsLoader<TexturesLoader, sf::Texture> {
			public:

				TexturesLoader();
				~TexturesLoader();
				sf::Texture* load(const std::string& path);
		};
	}
}