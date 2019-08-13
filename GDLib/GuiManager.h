#pragma once

#include <SFML/Graphics.hpp>
#include <unordered_map>
#include <functional>

#include "defines.h"
#include "EventManager.h"
#include "Gui/GuiEvent.h"
#include "Gui/GuiComponent.h"
#include "Gui/GuiButton.h"

namespace GDLib {

	struct Context;

	using GuiEvents = std::unordered_map<unsigned int, std::vector<Gui::GuiEvent>>;
	using GuiFactory = std::unordered_map<Gui::GuiComponentType, std::function<Gui::GuiComponent*(void)>>;
	using GuiComponentTypes = std::unordered_map<std::string, Gui::GuiComponentType>;

	class GDLIB_API GuiManager {
		public:

			GuiManager(EventManager* eventManager, Context* context);
			~GuiManager();

			void handleClick(EventDetails* details);
			void handleRelease(EventDetails* details);
			
			void addEvent(Gui::GuiEvent eventObj);
			bool pollEvent(Gui::GuiEvent& eventObj);

			void update(float dt);
			void render(sf::RenderWindow* window);

			template<class T>
			void registerComponent(const Gui::GuiComponentType& id) {
				this->m_factory[id] = []() -> Gui::GuiComponent* {
					return new T("");
				};
			}

			Context* getContext();
			void setCurrentState(const unsigned int state);

		private:
			GuiEvents m_events;
			Context* m_context;
			GuiFactory m_factory;
			unsigned int m_currentState;
			EventManager* m_eventManager;
			GuiComponentTypes m_componentTypes;
	};
}