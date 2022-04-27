#pragma once

#include <graphics/RenderTarget.hpp>

namespace gbl {
	namespace graphics {

		class Drawable {
			public: 
				virtual ~Drawable() = default;

			protected:
				friend class RenderTarget;

				virtual void draw(RenderTarget& target, RenderStates& states) const = 0;
		};
	}
}