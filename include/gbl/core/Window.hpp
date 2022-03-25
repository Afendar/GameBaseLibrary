#pragma once

#include <memory>
#include <string>

namespace gbl {
	namespace core {
		class Window {
			public:
				enum WindowMode {
					WINDOWED,
					FULLSCREEN,
					BORDERLESS,
					RESIZABLE
				};

				void open(int width, int height, const std::string& title);

				void clear();

				void display();

				WindowMode getWindowMode() const;
				void setWindowMode(WindowMode mode);

				

			protected:
		};
	}
}