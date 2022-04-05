#include "../../../../include/gbl/core/manager/EventManager.hpp"

#include <iostream>

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
			switch (key) {
				case SDLK_0: return Keyboard::Key::Num0;
				case SDLK_1: return Keyboard::Key::Num1;
				case SDLK_2: return Keyboard::Key::Num2;
				case SDLK_3: return Keyboard::Key::Num3;
				case SDLK_4: return Keyboard::Key::Num4;
				case SDLK_5: return Keyboard::Key::Num5;
				case SDLK_6: return Keyboard::Key::Num6;
				case SDLK_7: return Keyboard::Key::Num7;
				case SDLK_8: return Keyboard::Key::Num8;
				case SDLK_9: return Keyboard::Key::Num9;
				case SDLK_a: return Keyboard::Key::A;
				case SDLK_b: return Keyboard::Key::B;
				case SDLK_c: return Keyboard::Key::C;
				case SDLK_d: return Keyboard::Key::D;
				case SDLK_e: return Keyboard::Key::E;
				case SDLK_f: return Keyboard::Key::F;
				case SDLK_g: return Keyboard::Key::G;
				case SDLK_h: return Keyboard::Key::H;
				case SDLK_i: return Keyboard::Key::I;
				case SDLK_j: return Keyboard::Key::J;
				case SDLK_k: return Keyboard::Key::K;
				case SDLK_l: return Keyboard::Key::L;
				case SDLK_m: return Keyboard::Key::M;
				case SDLK_n: return Keyboard::Key::N;
				case SDLK_o: return Keyboard::Key::O;
				case SDLK_p: return Keyboard::Key::P;
				case SDLK_q: return Keyboard::Key::Q;
				case SDLK_r: return Keyboard::Key::R;
				case SDLK_s: return Keyboard::Key::S;
				case SDLK_t: return Keyboard::Key::T;
				case SDLK_u: return Keyboard::Key::U;
				case SDLK_v: return Keyboard::Key::V;
				case SDLK_w: return Keyboard::Key::W;
				case SDLK_x: return Keyboard::Key::X;
				case SDLK_y: return Keyboard::Key::Y;
				case SDLK_z: return Keyboard::Key::Z;
				case SDLK_KP_0: return Keyboard::Key::Numpad0;
				case SDLK_F1: return Keyboard::Key::F1;
				case SDLK_F2 : return Keyboard::Key::F2;
				case SDLK_F3 : return Keyboard::Key::F3;
				case SDLK_F4 : return Keyboard::Key::F4;
				case SDLK_F5 : return Keyboard::Key::F5;
				case SDLK_F6 : return Keyboard::Key::F6;
				case SDLK_F7 : return Keyboard::Key::F7;
				case SDLK_F8 : return Keyboard::Key::F8;
				case SDLK_F9 : return Keyboard::Key::F9;
				case SDLK_F10 : return Keyboard::Key::F10;
				case SDLK_F11 : return Keyboard::Key::F11;
				case SDLK_F12 : return Keyboard::Key::F12;
			}

			return Keyboard::Key::Unknown;
		}
	}
}