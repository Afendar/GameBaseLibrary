#pragma once

//GameBaseLibrary Includes
#include <core/input/Mouse.hpp>
#include <core/input/Keyboard.hpp>

namespace gbl {
	namespace core {

		class Event {
			public:
				struct ResizeEvent {
					unsigned int width;
					unsigned int height;
				};

				struct KeyEvent {
					Keyboard::Key code;
					SDL_Keycode sdl_code;
					bool alt;
					bool control;
					bool shift;
					bool system;
				};

				struct MouseMoveEvent {
					int x;
					int y;
				};

				struct MouseButtonEvent {
					Mouse::Button button;
					int x;
					int y;
				};

				struct MouseWheelScrollEvent {
					Mouse::Wheel wheel;
					float delta;
					int x;
					int y;
				};

				enum class EventType : int {
					Unknown = -1,
					Closed = 0,
					Resized,
					LostFocus,
					GainedFocus,
					TextEntered,
					KeyPressed,
					KeyReleased,
					MouseWheelScrolled,
					MouseButtonPressed,
					MouseButtonReleased,
					MouseMoved,
					MouseEntered,
					MouseLeft,
					Count
				};

				EventType type;

				union {
					ResizeEvent size;
					KeyEvent key;
					MouseMoveEvent mouseMove;
					MouseButtonEvent mouseButton;
				};
		};
	}
}