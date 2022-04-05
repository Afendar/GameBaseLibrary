#include "../../../include/gbl/core/Window.hpp"
#include "../../../include/gbl/core/Exception.hpp"

void gbl::core::Window::open(int width, int height, const std::string& title)
{
	m_window.reset(SDL_CreateWindow(title.c_str(), SDL_WINDOWPOS_CENTERED, SDL_WINDOWPOS_CENTERED, width, height, 0));

	if (!m_window) {
		throw gbl::core::Exception("Window initialisation failed:", SDL_GetError());
	}

	m_size.m_x = width;
	m_size.m_y = height;

	m_opened = true;
}

void gbl::core::Window::clear()
{
}

void gbl::core::Window::display()
{
}

void gbl::core::Window::onEvent(const Event& event)
{
	switch (event.type) {
	case Event::EventType::Resized:
			m_size.m_x = event.size.width;
			m_size.m_y = event.size.height;
			resize(m_size.m_x, m_size.m_y);
			break;
	case Event::EventType::Closed:
			m_opened = false;
			break;
		default:
			break;
	}
}

void gbl::core::Window::setVerticalSyncEnabled(bool enable)
{
	m_verticalSyncEnabled = enable;
}

gbl::core::Vector2u gbl::core::Window::getSize() const
{
	return m_size;
}

void gbl::core::Window::resize(unsigned int width, unsigned int height)
{
	SDL_SetWindowSize(m_window.get(), m_size.m_x, m_size.m_y);
}

gbl::core::Window::WindowMode gbl::core::Window::getWindowMode() const
{
	return WindowMode();
}

void gbl::core::Window::setWindowMode(WindowMode mode)
{
}

bool gbl::core::Window::poolEvent(Event& event)
{
	if (m_eventManager->popEvent(event, false)) {
		return filterEvent(event);
	}
	return false;
}

bool gbl::core::Window::filterEvent(const Event& event)
{
	onEvent(event);
	return true;
}
