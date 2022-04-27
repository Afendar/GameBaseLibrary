#pragma once

#include <graphics/Transform.hpp>

namespace gbl {
	namespace graphics {
		class RenderStates {
			public:
				Transform transform;

				static const RenderStates Default;
		};
	}
}