#include "TexturesLoader.h"
#include "AssetsLoader.cpp"

namespace GDLib {
	namespace Assets {
		TexturesLoader::TexturesLoader() : AssetsLoader<TexturesLoader, sf::Texture>("data/textures.cfg") {}

		TexturesLoader::~TexturesLoader() {

		}

		sf::Texture* TexturesLoader::load(const std::string& path) {
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
	}
}