/**
 *
 *
 * @file src/Application.h
 * @author Afendar
 */
#pragma once

#include <iostream>
#include <SFML/Graphics.hpp>
#include "Window.h"

namespace GDLib {

	class Application {
		public:
			Application() { 
				m_clock.restart();

				m_isInitialized = false;
				m_isRunning = false;
			}
			~Application() {}

			virtual void run() = 0;
			virtual void stop() = 0;

			sf::Time getElapsed() { return m_elapsed; }
			Window* getWindow() { return &m_window; }

		protected:

			virtual void init() = 0;
			virtual void update() = 0;
			virtual void lateUpdate() = 0;

			virtual void render() = 0;

			void restartClock() {
				m_elapsed = m_clock.restart();
			}

			Window m_window;

			sf::Clock m_clock;
			sf::Time m_elapsed;

			bool m_isInitialized;
			bool m_isRunning;
	};

}