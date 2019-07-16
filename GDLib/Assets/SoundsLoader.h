#pragma once

#include <SFML/Audio/SoundBuffer.hpp>

#include "AssetsLoader.h"
#include "../utils/System.h"

namespace GDLib {
	namespace Assets {

		class GDLIB_API SoundsLoader : public  AssetsLoader<SoundsLoader, sf::SoundBuffer> {
		public:

			SoundsLoader();
			~SoundsLoader();
			sf::SoundBuffer* load(const std::string& path);
		};
	}
}