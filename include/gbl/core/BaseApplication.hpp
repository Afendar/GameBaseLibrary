#pragma once

#include "Window.hpp"
#include "SharedContext.hpp"

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
				virtual void handleEvents();

				/**
				* 
				*/
				virtual void onEvent(const SDL_Event& event);

				/**
				* 
				*/
				virtual void loop();

				std::unique_ptr<Window> m_window;
				std::unique_ptr<SharedContext> m_context;
		};
	}
}