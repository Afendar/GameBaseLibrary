#pragma once

#include <string>

namespace gbl {
	namespace core {
		class Keyboard {
			public:
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

				std::string getKeyName(const Key& key) const;
		};
	}
}