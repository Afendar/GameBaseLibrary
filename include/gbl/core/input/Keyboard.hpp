#pragma once

//Standard C++ Library Includes
#include <string>
#include <map>

//GameBaseLibrary Includes
#include <core/SDLHeaders.hpp>

namespace gbl {
	namespace core {
		/**
		* Class Keyboard
		* 
		* @author Afendar <contact.afendar@gmail.com>
		*/
		class Keyboard {
			public:
				/**
				*
				*/
				enum struct Key : int {
					Unknown = -1,
					Num0 = 0,
					Num1,
					Num2,
					Num3,
					Num4,
					Num5,
					Num6,
					Num7,
					Num8,
					Num9,
					Escape,
					LeftControl,
					LeftShift,
					LeftAlt,
					LeftSystem,
					RightControl,
					RightShift,
					RightAlt,
					RightSystem,
					Menu,
					LeftBracket,
					RightBracket,
					Semicolon,
					Comma,
					Period,
					Quote,
					Slash,
					Backslash,
					Tilde,
					Equal,
					Hyphen,
					Space,
					Enter,
					Backspace,
					Tab,
					PageUp,
					PageDown,
					End,
					Home,
					Insert,
					Delete,
					Add,
					Substract,
					Multiply,
					Divide,
					Left,
					Right,
					Up,
					Down,
					A,
					B,
					C,
					D,
					E,
					F,
					G,
					H,
					I,
					J,
					K,
					L,
					M,
					N,
					O,
					P,
					Q,
					R,
					S,
					T,
					U,
					V,
					W,
					X,
					Y,
					Z,
					Numpad0,
					Numpad1,
					Numpad2,
					Numpad3,
					Numpad4,
					Numpad5,
					Numpad6,
					Numpad7,
					Numpad8,
					Numpad9,
					F1,
					F2,
					F3,
					F4,
					F5,
					F6,
					F7,
					F8,
					F9,
					F10,
					F11,
					F12,
					Count
				};

				/**
				* 
				* 
				* @param SDL_Keycode code
				* @return Key
				*/
				static Key getKeycodeFromSDLKeycode(const SDL_Keycode& code);

				/**
				* 
				* 
				* @param Key key
				* @return std::string
				*/
				static std::string getKeyName(Key key);

				/**
				* 
				* 
				* @param SDL_Keycode code
				* @return std::string
				*/
				static std::string getKeyNameFromSDLKeycode(const SDL_Keycode& code);

			private:
				static std::map<Key, SDL_Keycode> m_keys;
		};
	}
}