#pragma once

//Standard C++ Library Includes
#include <queue>

//GameBaseLibrary Includes
#include <core/input/Event.hpp>

namespace gbl {
	namespace core {
		class EventManager
		{
			public:
				bool popEvent(Event& event, bool block);

			protected:
				void pushEvent(const Event& event);
				void processEvents();
				Event::EventType convertEventWindowType(const Uint8& windowEvent);
				Keyboard::Key convertKeyCode(const SDL_Keycode& key);

			private:
				std::queue<Event> m_events;
			};
	}
}