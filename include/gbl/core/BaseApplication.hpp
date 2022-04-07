#pragma once

//GameBaseLibrary Includes
#include <core/Window.hpp>
#include <core/SharedContext.hpp>

namespace gbl {
	namespace core {
		class BaseApplication {
			public:

				/**
				* 
				*/
				BaseApplication(int argc, char** argv);

				/**
				* 
				*/
				~BaseApplication();

				/**
				* 
				*/
				int run();

			protected:

				/**
				* 
				*/
				virtual bool init();

				/**
				* 
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

				std::unique_ptr<Window> m_window;
				std::unique_ptr<SharedContext> m_context;
		};
	}
}