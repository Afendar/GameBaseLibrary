#pragma once

//GameBaseLibrary Includes
#include <core/SDLHeaders.hpp>

namespace gbl {
	namespace core {
		class Mouse {
			public:
				enum class Button {
					Left,
					Right,
					Middle,
					XButton1,
					XButton2,
					Count
				};

				enum Wheel {
					VerticalWheel,
					HorizontalWheel
				};

				static Button getButtonFromSDLButton(const Uint8& SDLbutton);
		};
	}
}