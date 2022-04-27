#pragma once

#include <cstdint>

namespace gbl {
	namespace graphics {
		class Color {
			public:

				Color() { Color(0, 0, 0); }
				Color(std::uint8_t red, std::uint8_t green, std::uint8_t blue, std::uint8_t alpha = 255) : r(red), g(green), b(blue), a(alpha) {}

				std::uint8_t r, g, b, a;
		};
	}
}