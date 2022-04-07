//GameBaseLibrary Includes
#include <core/input/Mouse.hpp>

namespace gbl {
	namespace core {
		Mouse::Button Mouse::getButtonFromSDLButton(const Uint8& SDLbutton)
		{
			switch (SDLbutton) {
				case SDL_BUTTON_LEFT: return Mouse::Button::Left;
				case SDL_BUTTON_RIGHT: return Mouse::Button::Right;
				case SDL_BUTTON_MIDDLE: return Mouse::Button::Middle;
				case SDL_BUTTON_X1: return Mouse::Button::XButton1;
				case SDL_BUTTON_X2: return Mouse::Button::XButton2;
			}
		}
	}
}