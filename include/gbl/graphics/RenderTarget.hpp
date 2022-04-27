#pragma once

#include <graphics/RenderStates.hpp>
#include <core/SDLHeaders.hpp>

namespace gbl {
	namespace graphics {
		class Drawable;

		class RenderTarget {
			public:
				virtual ~RenderTarget() = default;

				void draw(Drawable& drawable, RenderStates states = RenderStates::Default);

				virtual SDL_Renderer* getSDLRenderer() = 0;
		};
	}
}