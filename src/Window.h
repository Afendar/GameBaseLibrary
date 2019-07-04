/**
 *
 *
 * @file src/Window.h
 * @author Afendar
 */
#pragma once

#include <string>
#include <SFML/Graphics.hpp>

namespace GDLib {
	class Window {
		public:
			Window() {
				m_isInitialized = false;
				m_mouseMoved = true;
				m_isFocused = true;
			}
			~Window() {
				m_window.close();
			}

			void clear(){
				m_window.clear(sf::Color::Black);
			}
			void display(){
				m_window.display();
			}

			sf::RenderWindow* getRenderWindow() {
				return &m_window;
			}

			void init(const std::string& title, const sf::Vector2u& size, const bool& isFullscreen){
				m_windowTile = title;
				m_windowSize = size;
				m_isFullscreen = isFullscreen;
				m_isClosed = false;
				m_isFocused = false;
				m_isInitialized = true;

				create();
			}

			void update(){
				sf::Event event;
				while (m_window.pollEvent(event)) {
					if (event.type == sf::Event::Closed) {
						close();
					}
				}
			}

			bool isClosed() { return m_isClosed; }
			bool isFullscreen() { return m_isFullscreen; }
			bool isFocused() { return m_isFocused; }

			void toggleFullscreen(){}
			void close(){
				m_isClosed = true;
			}

		private:

			void create(){
				sf::Uint32 style = sf::Style::Default;

				if (m_isFullscreen) {
					style = sf::Style::Fullscreen;
				}

				sf::ContextSettings context;
				context.depthBits = 24;
				context.stencilBits = 8;
				context.antialiasingLevel = 2;

				m_window.create(sf::VideoMode(m_windowSize.x, m_windowSize.y, 32), m_windowTile, style, context);
				m_window.setVerticalSyncEnabled(true);
			}

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