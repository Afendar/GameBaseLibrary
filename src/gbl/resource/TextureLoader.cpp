//Standard C++ Library Includes
#include <iostream>

//GameBaseLibrary Includes
#include <resource/TextureLoader.hpp>

void gbl::resource::TextureLoader::load(const char* jsonFilename, ResourceManager* handler)
{
	std::cout << "loading texture resources from: " << jsonFilename << std::endl;
	//TODO loading texture elements
}
