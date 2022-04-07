#include <graphics/ui/Component.hpp>

std::weak_ptr<gbl::graphics::Component> focusedComponent;

gbl::graphics::Component::Component(): 
	m_selected(false),
	m_zOrder(0),
	m_visible(true)
{
}

gbl::graphics::Component::~Component()
{
}

bool gbl::graphics::Component::isVisible() const
{
	return m_visible;
}

bool gbl::graphics::Component::hasFocus() const
{
	return hasFocus(shared_from_this());
}

int gbl::graphics::Component::getZOrder() const
{
	return m_zOrder;
}

std::shared_ptr<gbl::graphics::Container> gbl::graphics::Component::getParent()
{
	return m_parent.lock();
}

void gbl::graphics::Component::setVisible(bool visible)
{
	m_visible = visible;
}

void gbl::graphics::Component::setZOrder(int zOrder)
{
	m_zOrder = zOrder;
}

void gbl::graphics::Component::setParent(Component::Ptr parent)
{
	auto cont = std::dynamic_pointer_cast<Container>(parent);
	m_parent = cont;
}

void gbl::graphics::Component::update(float seconds)
{
	handleUpdate(seconds);
}

void gbl::graphics::Component::grabFocus()
{
	grabFocus(shared_from_this());
}

bool gbl::graphics::Component::isSelected() const
{
	return m_selected;
}

void gbl::graphics::Component::select()
{
	m_selected = true;
}

void gbl::graphics::Component::deselect()
{
	m_selected = false;
}

gbl::core::FloatRect gbl::graphics::Component::getGlobalBounds() const
{
	return getTransform().transformRect(getLocalBounds());
}

gbl::core::FloatRect gbl::graphics::Component::getLocalBounds() const
{
	return gbl::core::FloatRect(0.f, 0.f, 0.f, 0.f);
}

const gbl::core::Vector2f& gbl::graphics::Component::getPosition() const
{
	gbl::core::Vector2f pos = Transformable::getPosition();
	if (m_parent.lock() != nullptr) {
		gbl::core::Vector2f parentPos = m_parent.lock()->getPosition();
		pos += parentPos;
	}
	return pos;
}

void gbl::graphics::Component::handleEvent(const gbl::core::Event& evt)
{
	switch (evt.type) {
	case gbl::core::Event::EventType::MouseLeft:
		/*if (!isMouseInComponent()) {
			handleMouseLeave(std::numeric_limits<int>::min(), std::numeric_limits<int>::min());
		}*/

		handleMouseMoveEvent(std::numeric_limits<int>::min(), std::numeric_limits<int>::min());

		handleMouseButtonEvent(gbl::core::Mouse::Button::Left, false, std::numeric_limits<int>::min(), std::numeric_limits<int>::min());
		handleMouseButtonEvent(gbl::core::Mouse::Button::Right, false, std::numeric_limits<int>::min(), std::numeric_limits<int>::min());

		break;
	case gbl::core::Event::EventType::MouseMoved:

		if (isMouseInComponent() && !isSelected()) {
			select();
			handleMouseEnter(evt.mouseMove.x, evt.mouseMove.y);
		}
		else if (!isMouseInComponent() && isSelected()) {
			deselect();
			handleMouseLeave(evt.mouseMove.x, evt.mouseMove.y);
		}

		handleMouseMoveEvent(evt.mouseMove.x, evt.mouseMove.y);

		break;
	case gbl::core::Event::EventType::MouseButtonPressed:
		handleMouseButtonEvent(evt.mouseButton.button, true, evt.mouseButton.x, evt.mouseButton.y);
		break;
	case gbl::core::Event::EventType::MouseButtonReleased:
		if (isMouseInComponent()) {
			handleMouseClick(evt.mouseButton.button, evt.mouseButton.x, evt.mouseButton.y);
		}

		handleMouseButtonEvent(evt.mouseButton.button, false, evt.mouseButton.x, evt.mouseButton.y);
		break;
	case gbl::core::Event::EventType::KeyPressed:
		if (hasFocus()) {
			handleKeyEvent(evt.key.code, true);
		}
		break;
	case gbl::core::Event::EventType::KeyReleased:
		if (hasFocus()) {
			handleKeyEvent(evt.key.code, false);
		}
		break;
	case gbl::core::Event::EventType::TextEntered:
		if (hasFocus()) {
			handleTextEvent(evt.text.unicode);
		}
		break;
	}
}

bool gbl::graphics::Component::isMouseInComponent() const
{
	gbl::core::Vector2f localPosition = gbl::core::Vector2f(gbl::core::Mouse::getPosition(*m_screen->getRenderWindow()));
	gbl::core::FloatRect rect(const_cast<Component*>(this)->getLocalBounds());
	gbl::core::Vector2f pos = getPosition();
	rect.m_x += pos.m_x;
	rect.m_y += pos.m_y;
	return rect.contains(localPosition.m_x, localPosition.m_y);
}

bool gbl::graphics::Component::hasFocus(PtrConst component)
{
	if (focusedComponent.lock() == component) {
		return true;
	}
	return false;
}

void gbl::graphics::Component::grabFocus(Ptr component)
{
	if (focusedComponent.lock()) {
		focusedComponent.lock()->handleFocusChange(component);
	}

	focusedComponent = component;

	if (focusedComponent.lock()) {
		focusedComponent.lock()->handleFocusChange(component);
	}
}
