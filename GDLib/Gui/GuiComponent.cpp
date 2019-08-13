#include "GuiComponent.h"

namespace GDLib {
	namespace Gui {
		GuiComponent::GuiComponent(const std::string& name, const GuiComponentType& type)
			: m_name(name), m_type(type), m_state(GuiComponentState::NEUTRAL),
			m_needsRedraw(false), m_active(true), m_isControl(false)
		{
		}

		GuiComponent::~GuiComponent()
		{
		}

		GuiComponentType GuiComponent::getType()
		{
			return this->m_type;
		}

		const std::string& GuiComponent::getName() const
		{
			return this->m_name;
		}

		const sf::Vector2f& GuiComponent::getPosition() const
		{
			return this->m_position;
		}

		const sf::Vector2f& GuiComponent::getSize() const
		{
			return sf::Vector2f(0, 0);
		}

		GuiComponentState GuiComponent::getState() const
		{
			return this->m_state;
		}

		bool GuiComponent::needsRedraw() const
		{
			return this->m_needsRedraw;
		}

		bool GuiComponent::isActive() const
		{
			return this->m_active;
		}

		bool GuiComponent::isInside(const sf::Vector2f& pointCoords) const
		{
			return false;
		}

		bool GuiComponent::isControl() const
		{
			return this->m_isControl;
		}
	}
}