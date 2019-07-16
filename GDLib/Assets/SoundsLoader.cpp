#include "SoundsLoader.h"
#include "AssetsLoader.cpp"

namespace GDLib {
	namespace Assets {
		SoundsLoader::SoundsLoader() : AssetsLoader<SoundsLoader, sf::SoundBuffer>("data/sounds.cfg") {}

		SoundsLoader::~SoundsLoader() {

		}

		sf::SoundBuffer* SoundsLoader::load(const std::string& path) {
			sf::SoundBuffer* sound = new sf::SoundBuffer();
			if (!sound->loadFromFile(
				Utils::System::getWorkingDirectory() + path
			)) {
				delete sound;
				sound = nullptr;
				std::cerr << "! Failed to load texture: " << path << std::endl;
			}
			return sound;
		}
	}
}