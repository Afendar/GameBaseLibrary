#pragma once

//GameBaseLibrary Includes
#include <graphics/RenderWindow.hpp>
#include <core/SharedContext.hpp>

namespace gbl {
	namespace core {
		/**
		* Class BaseApplication
		* 
		* @author Afendar <contact.afendar@gmail.com>
		* @since 0.0.1
		*/
		class BaseApplication {
			public:

				/**
				* 
				* 
				* @param int argc
				* @param char** argv
				*/
				BaseApplication(int argc, char** argv);

				/**
				* 
				*/
				~BaseApplication();

				/**
				* 
				* 
				* @return int
				*/
				int run();

			protected:

				/**
				* 
				* 
				* @return bool
				*/
				virtual bool init();

				/**
				* 
				* 
				* @param int width
				* @param int height
				* @param std::string title
				*/
				void createWindow(int width, int height, const std::string& title);

				/**
				* 
				*/
				virtual void onExit() {}

				/**
				* 
				*/
				virtual void handleEvents() {
					Event event{};
					while (m_window->poolEvent(event)) {
						//Process events here
					}
				};

				/**
				* 
				*/
				virtual void loop();

				std::unique_ptr<gbl::graphics::RenderWindow> m_window;
				std::unique_ptr<SharedContext> m_context;
		};
	}
}