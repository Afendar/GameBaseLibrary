#pragma once

//GameBaseLibrary Includes
#include <resource/IResourceLoader.hpp>

namespace gbl {
	namespace resource {
		/**
		* Class TextureLoader
		* 
		* @namepsace gbl::resource
		*/
		class TextureLoader : public IResourceLoader {
			public:
				/**
				* 
				* @param const char* jsonFilename
				* @param ResourceManager* handler
				*/
				void load(const char* jsonFilename, ResourceManager* handler);
		};
	}
}