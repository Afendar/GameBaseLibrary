#pragma once

#include <SFML/Window/Event.hpp>
#include <SFML/Graphics/RenderWindow.hpp>
#include <string>
#include <vector>
#include <unordered_map>
#include <assert.h>
#include <functional>
#include <fstream>
#include <sstream>
#include <iostream>

#include "defines.h"
#include "Gui/GuiEvent.h"

namespace GDLib {
	enum class GDLIB_API EventType {
		KEY_DOWN = sf::Event::KeyPressed,
		KEY_UP = sf::Event::KeyReleased,
		MOUSE_BUTTON_DOWN = sf::Event::MouseButtonPressed,
		MOUSE_BUTTON_UP = sf::Event::MouseButtonReleased,
		MOUSE_WHEEL = sf::Event::MouseWheelMoved,
		WINDOW_RESIZED = sf::Event::Resized,
		GAINED_FOCUS = sf::Event::GainedFocus,
		LOST_FOCUS = sf::Event::LostFocus,
		MOUSE_ENTERED = sf::Event::MouseEntered,
		MOUSE_LEFT = sf::Event::MouseLeft,
		CLOSED = sf::Event::Closed,
		TEXT_ENTERED = sf::Event::TextEntered,
		KEYBOARD = sf::Event::Count + 1,
		MOUSE,
		JOYSTICK,
		GUI_CLICK,
		GUI_RELEASE,
		GUI_HOVER,
		GUI_LEAVE
	};

	struct GDLIB_API EventInfo {
		EventInfo() { m_code = 0; }
		EventInfo(int evt) { m_code = evt; }
		EventInfo(const Gui::GuiEvent& guiEvent) { m_gui = guiEvent; }
		union {
			int m_code;
			Gui::GuiEvent m_gui;
		};
	};

	struct GDLIB_API EventDetails {
		EventDetails(const std::string& bindName) : m_name(bindName) {
			clear();
		}

		std::string m_name;
		sf::Vector2i m_size;
		sf::Uint32 m_textEntered;
		sf::Vector2i m_mouse;
		int m_mouseWheelDelta;
		int m_keyCode;

		std::string m_guiInterface;
		std::string m_guiElement;
		Gui::GuiEventType m_guiEvent;

		void clear() {
			m_size = sf::Vector2i(0, 0);
			m_textEntered = 0;
			m_mouse = sf::Vector2i(0, 0);
			m_mouseWheelDelta = 0;
			m_keyCode = -1;
			m_guiInterface = "";
			m_guiElement = "";
			m_guiEvent = Gui::GuiEventType::NONE;
		}
	};

	using Events = std::vector<std::pair<EventType, EventInfo>>;

	struct GDLIB_API Binding {
		Binding(const std::string& name): m_name(name), m_details(name), m_count(0){}
		~Binding() {
			for (auto itr = m_events.begin(); itr != m_events.end(); ++itr) {
				if (itr->first == EventType::GUI_CLICK || itr->first == EventType::GUI_RELEASE || itr->first == EventType::GUI_HOVER ||
					itr->first == EventType::GUI_LEAVE) {
					delete[] itr->second.m_gui.m_interface;
					delete[] itr->second.m_gui.m_element;
				}
			}
		}

		void bindEvent(EventType type, EventInfo info = EventInfo()) {
			m_events.emplace_back(type, info);
		}

		Events m_events;
		std::string m_name;
		int m_count;
		EventDetails m_details;
	};

	using Bindings = std::unordered_map<std::string, Binding*>;
	using CallbackContainer = std::unordered_map<std::string, std::function<void(EventDetails*)>>;
	
	enum class StateType;

	using Callbacks = std::unordered_map<unsigned int, CallbackContainer>;

	class GDLIB_API EventManager {
		public:
			EventManager();
			~EventManager();

			bool addBinding(Binding* binding);
			bool removeBinding(std::string name);

			void setCurrentState(unsigned int);
			void setFocus(bool focus);

			template<class T>
			bool addCallback(unsigned int state, const std::string& name, void(T::*func)(EventDetails*), T* instance) {
				auto itr = m_callbacks.emplace(state, CallbackContainer()).first;
				auto temp = std::bind(func, instance, std::placeholders::_1);
				return itr->second.emplace(name, temp).second;
			}

			bool removeCallback(unsigned int state, const std::string& name) {
				auto itr = m_callbacks.find(state);
				if (itr == m_callbacks.end()) { return false; }
				auto itr2 = itr->second.find(name);
				if (itr2 == itr->second.end()) { return false; }
				itr->second.erase(name);
				return true;
			}

			void handleEvent(sf::Event& evt);
			void handleEvent(Gui::GuiEvent& evt);
			void update();

			sf::Vector2i getMousePos(sf::RenderWindow* window = nullptr) {
				return window ? sf::Mouse::getPosition(*window) : sf::Mouse::getPosition();
			}

		private:

			unsigned int m_currentState;
			Bindings m_bindings;
			Callbacks m_callbacks;
			bool m_hasFocus;
	};
}