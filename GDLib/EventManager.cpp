#include "EventManager.h"

namespace GDLib {
	EventManager::EventManager() : m_currentState(0), m_hasFocus(true) {
	}

	EventManager::~EventManager() {
		for (auto &itr : m_bindings) {
			delete itr.second;
		}
	}

	bool EventManager::addBinding(Binding* binding) {
		if (m_bindings.find(binding->m_name) != m_bindings.end()) {
			return false;
		}
		return m_bindings.emplace(binding->m_name, binding).second;
	}

	bool EventManager::removeBinding(std::string name) {
		auto itr = m_bindings.find(name);
		if (itr == m_bindings.end()) {
			return false;
		}
		delete itr->second;
		m_bindings.erase(itr);
		return true;
	}

	void EventManager::setCurrentState(unsigned int state) {
		m_currentState = state;
	}

	void EventManager::setFocus(bool focus) {
		m_hasFocus = focus;
	}

	void EventManager::handleEvent(sf::Event& evt) {
		for (auto &bItr : m_bindings) {
			Binding* bind = bItr.second;
			for (auto &eItr : bind->m_events) {
				EventType sfmlEvent = (EventType)evt.type;
				if (eItr.first == EventType::GUI_CLICK || eItr.first == EventType::GUI_RELEASE || eItr.first == EventType::GUI_HOVER ||
					eItr.first == EventType::GUI_LEAVE || eItr.first != sfmlEvent) {
					continue;
				}
				if (sfmlEvent == EventType::KEY_DOWN || sfmlEvent == EventType::KEY_UP) {
					if (eItr.second.m_code == evt.key.code) {
						if (bind->m_details.m_keyCode != -1) {
							bind->m_details.m_keyCode = eItr.second.m_code;
						}
						++(bind->m_count);
						break;
					}
				}
				else if(sfmlEvent == EventType::MOUSE_BUTTON_DOWN || sfmlEvent == EventType::MOUSE_BUTTON_UP){
					if (eItr.second.m_code == evt.mouseButton.button) {
						bind->m_details.m_mouse.x = evt.mouseButton.x;
						bind->m_details.m_mouse.y = evt.mouseButton.y;
						if (bind->m_details.m_keyCode != -1) {
							bind->m_details.m_keyCode = eItr.second.m_code;
						}
						++(bind->m_count);
						break;
					}
				}
				else {
					if (sfmlEvent == EventType::MOUSE_WHEEL) {
						bind->m_details.m_mouseWheelDelta = evt.mouseWheel.delta;
					}
					else if (sfmlEvent == EventType::WINDOW_RESIZED) {
						bind->m_details.m_size.x = evt.size.width;
						bind->m_details.m_size.y = evt.size.height;
					}
					else if (sfmlEvent == EventType::TEXT_ENTERED) {
						bind->m_details.m_textEntered = evt.text.unicode;
					}
					++(bind->m_count);
				}
			}
		}
	}

	void EventManager::handleEvent(Gui::GuiEvent& evt) {
		for (auto &bItr : m_bindings) {
			Binding* bind = bItr.second;
			for (auto &eItr : bind->m_events) {
				if (eItr.first != EventType::GUI_CLICK && eItr.first != EventType::GUI_RELEASE && eItr.first != EventType::GUI_HOVER &&
					eItr.first != EventType::GUI_LEAVE) {
					continue;
				}
				if ((eItr.first == EventType::GUI_CLICK && evt.m_type != Gui::GuiEventType::CLICK) ||
					(eItr.first == EventType::GUI_RELEASE && evt.m_type != Gui::GuiEventType::RELEASE) ||
					(eItr.first == EventType::GUI_HOVER && evt.m_type != Gui::GuiEventType::HOVER) ||
					(eItr.first == EventType::GUI_LEAVE && evt.m_type != Gui::GuiEventType::LEAVE)) {
					continue;
				}
				if (strcmp(eItr.second.m_gui.m_interface, evt.m_interface) || strcmp(eItr.second.m_gui.m_element, evt.m_element)) {
					continue;
				}
				bind->m_details.m_guiElement = evt.m_element;
				++(bind->m_count);
			}
		}
	}

	void EventManager::update() {
		if (!m_hasFocus) {
			return;
		}
		for (auto &bItr : m_bindings) {
			Binding* bind = bItr.second;
			for (auto &eItr : bind->m_events) {
				switch (eItr.first) {
					case EventType::KEYBOARD:
						if (sf::Keyboard::isKeyPressed(sf::Keyboard::Key(eItr.second.m_code))) {
							if (bind->m_details.m_keyCode != -1) {
								bind->m_details.m_keyCode = eItr.second.m_code;
							}
							++(bind->m_count);
						}
						break;
					case EventType::MOUSE:
						if (sf::Mouse::isButtonPressed(sf::Mouse::Button(eItr.second.m_code))) {
							if (bind->m_details.m_keyCode != -1) {
								bind->m_details.m_keyCode = eItr.second.m_code;
							}
							++(bind->m_count);
						}
						break;
					case EventType::JOYSTICK:
						//TODO up expansion.
						break;
				}
			}

			if (bind->m_events.size() == bind->m_count) {
				auto stateCallbacks = m_callbacks.find(m_currentState);
				auto otherCallbacks = m_callbacks.find(0);

				if (stateCallbacks != m_callbacks.end()) {
					auto callItr = stateCallbacks->second.find(bind->m_name);
					if (callItr != stateCallbacks->second.end()) {
						callItr->second(&bind->m_details);
					}
				}

				if (otherCallbacks != m_callbacks.end()) {
					auto callItr = otherCallbacks->second.find(bind->m_name);
					if (callItr != otherCallbacks->second.end()) {
						callItr->second(&bind->m_details);
					}
				}
			}
			bind->m_count = 0;
			bind->m_details.clear();
		}
	}
}