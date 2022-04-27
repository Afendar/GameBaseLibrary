#pragma once

#include <core/Rect.hpp>

namespace gbl{
	namespace graphics {
		class Transform {
			public:
				gbl::core::FloatRect transformRect(const gbl::core::FloatRect& rectangle) const;
		};
	}
}