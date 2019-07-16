/**
 *
 *
 * @file src/Window.h
 * @author Afendar
 */
#pragma once

#include <string>
#include <SFML/Graphics.hpp>

#include "defines.h"

namespace GDLib {
	class GDLIB_API Window {
		public:

			Window();
			~Window();

			void clear();
			void display();

			sf::RenderWindow* getRenderWindow();

			void init(const std::string& title, const sf::Vector2u& size, const bool& isFullscreen);

			void update();

			bool isClosed();
			bool isFullscreen();
			bool isFocused();

			void toggleFullscreen();
			void close();

		private:

			void create();

			bool m_isClosed;
			bool m_isFullscreen;
			bool m_isFocused;
			bool m_mouseMoved;
			bool m_captureMouse;
			bool m_isInitialized;
			
			sf::RenderWindow m_window;
			sf::Vector2u m_windowSize;
			std::string m_windowTile;
	};
}