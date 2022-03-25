#pragma once

#include <memory>
#include <string>
#include <iostream>

#include "SDLHeaders.hpp"
#include "Vector2.hpp"

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
				void close() { m_opened = false; }
				void clear();
				void display();

				void onEvent(const SDL_Event& event);

				bool isVerticalSyncEnabled() const { return m_verticalSyncEnabled; }
				void setVerticalSyncEnabled(bool enable);

				Vector2u getSize() const;
				void resize(unsigned int width, unsigned int height);

				WindowMode getWindowMode() const;
				void setWindowMode(WindowMode mode);

				bool isOpen() const { return m_opened; }

			protected:

				using SDL_WindowPtr = std::unique_ptr<SDL_Window, decltype(&SDL_DestroyWindow)>;

				SDL_WindowPtr m_window{ nullptr, SDL_DestroyWindow };
				bool m_opened, m_verticalSyncEnabled;
				Vector2u m_size;
				WindowMode m_mode = WindowMode::WINDOWED;
		};
	}
}