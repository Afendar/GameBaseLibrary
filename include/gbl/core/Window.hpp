#pragma once

//Standard C++ Library Includes
#include <memory>
#include <string>
#include <iostream>

//GameBaseLibrary Includes
#include <core/manager/EventManager.hpp>
#include <core/SDLHeaders.hpp>
#include <core/Vector2.hpp>
#include <graphics/Color.hpp>

namespace gbl {
	namespace core {
		class Window {
			public:
				enum class WindowMode : int {
					WINDOWED,
					FULLSCREEN,
					BORDERLESS,
					RESIZABLE
				};

				void open(int width, int height, const std::string& title);
				void close() { m_opened = false; }
				void clear(const gbl::graphics::Color& color = gbl::graphics::Color(0, 0, 0));
				void display();

				bool isVerticalSyncEnabled() const { return m_verticalSyncEnabled; }
				void setVerticalSyncEnabled(bool enable);

				Vector2u getSize() const;
				void resize(unsigned int width, unsigned int height);

				WindowMode getWindowMode() const;
				void setWindowMode(WindowMode mode);

				bool isOpen() const { return m_opened; }
				bool poolEvent(Event& event);

			protected:

				using SDL_WindowPtr = std::unique_ptr<SDL_Window, decltype(&SDL_DestroyWindow)>;
				using SDL_RendererPtr = std::unique_ptr<SDL_Renderer, decltype(&SDL_DestroyRenderer)>;

				SDL_WindowPtr m_window{nullptr, SDL_DestroyWindow};
				SDL_RendererPtr m_renderer{nullptr, SDL_DestroyRenderer};
				std::unique_ptr<EventManager> m_eventManager = std::make_unique<EventManager>();
				bool m_opened, m_verticalSyncEnabled;
				Vector2u m_size;
				WindowMode m_mode = WindowMode::WINDOWED;

			private:

				void onEvent(const Event& event);
				bool filterEvent(const Event& event);
		};
	}
}