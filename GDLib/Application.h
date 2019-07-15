/**
 *
 *
 * @file src/Application.h
 * @author Afendar
 */
#pragma once

#ifdef GDLIB_EXPORTS
#define GDLIB_API __declspec(dllexport)
#else
#define GDLIB_API __declspec(dllimport)
#endif

#include <iostream>
#include <SFML/Graphics.hpp>
#include "Window.h"
#include "I18n/I18nManager.h"

namespace GDLib {

	class GDLIB_API Application {
		public:
			Application();
			~Application();

			virtual void run() = 0;
			virtual void stop() = 0;

			sf::Time getElapsed();
			Window* getWindow();

		protected:

			virtual void init() = 0;
			virtual void update() = 0;
			virtual void lateUpdate() = 0;

			virtual void render() = 0;

			void restartClock();

			Window m_window;
			I18n::I18nManager m_i18nManager;

			sf::Clock m_clock;
			sf::Time m_elapsed;

			bool m_isInitialized;
			bool m_isRunning;
	};

}