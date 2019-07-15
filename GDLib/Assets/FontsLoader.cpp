#include "FontsLoader.h"
#include "AssetsLoader.cpp"

namespace GDLib {
	namespace Assets {
		FontsLoader::FontsLoader() : AssetsLoader<FontsLoader, sf::Font>("data/fonts.cfg") {}

		FontsLoader::~FontsLoader() {
		}

		sf::Font* FontsLoader::load(const std::string& path) {
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
	}
}