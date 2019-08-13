#include "TexturesLoader.h"

namespace GDLib {
	namespace Assets {
		TexturesLoader::TexturesLoader() : AssetsLoader<TexturesLoader, sf::Texture>("textures") {
			std::cout << "Loading textures..." << std::endl;
		}

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