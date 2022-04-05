#pragma once

namespace gbl {
	namespace core {
		class Mouse {
			public:
				enum Button {
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
		};
	}
}