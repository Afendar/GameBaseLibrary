/**
 *
 *
 * @file src/assets/TexturesLoader.h
 * @author Afendar
 */

#pragma once

#ifdef GDLIB_EXPORTS
#define GDLIB_API __declspec(dllexport)
#else
#define GDLIB_API __declspec(dllimport)
#endif

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