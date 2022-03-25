#pragma once

#include "Window.hpp"

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
				virtual ~BaseApplication() = default;

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
				virtual void loop();

				std::unique_ptr<Window> m_window;
		};
	}
}