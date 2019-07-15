#include "Application.h"

namespace GDLib {
	Application::Application() {
		m_clock.restart();
		m_isInitialized = false;
		m_isRunning = false;
	}

	Application::~Application() {

	}

	sf::Time Application::getElapsed() {
		return m_elapsed;
	}

	Window* Application::getWindow() {
		return &m_window;
	}

	void Application::restartClock() {
		m_elapsed = m_clock.restart();
	}
}