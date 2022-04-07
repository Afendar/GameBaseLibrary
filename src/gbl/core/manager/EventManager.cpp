//Standard C++ Library Includes
#include <iostream>

//GameBaseLibrary Includes
#include <core/manager/EventManager.hpp>

namespace gbl {
	namespace core {

		bool EventManager::popEvent(Event& event, bool block)
		{
			if (m_events.empty()) {
				processEvents();
				
				//TODO if block
			}

			if (!m_events.empty()) {
				event = m_events.front();
				m_events.pop();
				return true;
			}
			return false;
		}
		
		void EventManager::pushEvent(const Event& event)
		{
			m_events.push(event);
		}

		void EventManager::processEvents()
		{
			SDL_Event evt;
			if (SDL_PollEvent(&evt) == 1) {
				switch (evt.type) {
					case SDL_WINDOWEVENT: {
						Event event{};
						event.type = convertEventWindowType(evt.window.event);
						pushEvent(event);
						break;
					}
					case SDL_KEYDOWN: {
						Event event{};
						event.type = Event::EventType::KeyPressed;
						event.key.alt = evt.key.keysym.sym == SDLK_LALT || evt.key.keysym.sym == SDLK_RALT;
						event.key.control = evt.key.keysym.sym == SDLK_LCTRL || evt.key.keysym.sym == SDLK_RCTRL;
						event.key.shift = evt.key.keysym.sym == SDLK_LSHIFT || evt.key.keysym.sym == SDLK_RSHIFT;
						event.key.code = convertKeyCode(evt.key.keysym.sym);
						event.key.sdl_code = evt.key.keysym.sym;
						pushEvent(event);
						break;
					}
					case SDL_KEYUP: {
						Event event{};
						event.type = Event::EventType::KeyReleased;
						event.key.alt = evt.key.keysym.sym == SDLK_LALT || evt.key.keysym.sym == SDLK_RALT;
						event.key.control = evt.key.keysym.sym == SDLK_LCTRL || evt.key.keysym.sym == SDLK_RCTRL;
						event.key.shift = evt.key.keysym.sym == SDLK_LSHIFT || evt.key.keysym.sym == SDLK_RSHIFT;
						event.key.code = convertKeyCode(evt.key.keysym.sym);
						event.key.sdl_code = evt.key.keysym.sym;
						pushEvent(event);
						break;
					}
					case SDL_MOUSEBUTTONDOWN: {
						Event event{};
						event.type = Event::EventType::MouseButtonPressed;
						event.mouseButton.button = Mouse::getButtonFromSDLButton(evt.button.button);
						event.mouseButton.x = evt.button.x;
						event.mouseButton.y = evt.button.y;
						pushEvent(event);
						break;
					}
					case SDL_MOUSEBUTTONUP: {
						Event event{};
						event.type = Event::EventType::MouseButtonReleased;
						event.mouseButton.button = Mouse::getButtonFromSDLButton(evt.button.button);
						event.mouseButton.x = evt.button.x;
						event.mouseButton.y = evt.button.y;
						pushEvent(event);
						break;
					}
					case SDL_MOUSEMOTION: {
						Event event{};
						event.type = Event::EventType::MouseMoved;
						event.mouseMove.x = evt.motion.x;
						event.mouseMove.y = evt.motion.y;
						pushEvent(event);
						break;
					}
				}
			}
		}

		Event::EventType EventManager::convertEventWindowType(const Uint8& windowEvent)
		{
			switch (windowEvent) {
				case SDL_WINDOWEVENT_CLOSE: return Event::EventType::Closed;
				case SDL_WINDOWEVENT_RESIZED: return Event::EventType::Resized;
			}
			return Event::EventType::Unknown;
		}

		Keyboard::Key EventManager::convertKeyCode(const SDL_Keycode& key)
		{
			return Keyboard::getKeycodeFromSDLKeycode(key);
		}
	}
}