#include "GuiManager.h"
#include "Context.h"

namespace GDLib {
	GuiManager::GuiManager(EventManager* eventManager, Context* context) : m_eventManager(eventManager), m_context(context), m_currentState(0) {
		registerComponent<Gui::GuiButton>(Gui::GuiComponentType::BUTTON);

		this->m_componentTypes.emplace("Button", Gui::GuiComponentType::BUTTON);

		this->m_eventManager->addCallback(0, "Mouse_Left", &GuiManager::handleClick, this);
		this->m_eventManager->addCallback(0, "Mouse_Left_Release", &GuiManager::handleRelease, this);
	}

	GuiManager::~GuiManager()
	{
		this->m_eventManager->removeCallback(0, "Mouse_Left");
		this->m_eventManager->removeCallback(0, "Mouse_Left_Release");
	}

	void GuiManager::handleClick(EventDetails* details)
	{
	}

	void GuiManager::handleRelease(EventDetails* details)
	{
	}

	void GuiManager::addEvent(Gui::GuiEvent eventObj)
	{
		this->m_events[this->m_currentState].push_back(eventObj);
	}

	bool GuiManager::pollEvent(Gui::GuiEvent& eventObj)
	{
		if (this->m_events[this->m_currentState].empty())
		{
			return false;
		}
		eventObj = this->m_events[this->m_currentState].back();
		this->m_events[this->m_currentState].pop_back();
		return true;
	}

	void GuiManager::update(float dt)
	{
		sf::Vector2i mousePos = this->m_eventManager->getMousePos(this->m_context->m_window->getRenderWindow());
	}

	void GuiManager::render(sf::RenderWindow* window)
	{
	}

	Context* GuiManager::getContext() {
		return this->m_context;
	}

	void GuiManager::setCurrentState(const unsigned int state) {
		if (this->m_currentState == state)
		{
			return;
		}

		handleRelease(nullptr);
		this->m_currentState = state;
	}
}