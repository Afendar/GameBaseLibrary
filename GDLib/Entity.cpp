#include "Entity.h"

namespace GDLib {
	Entity::Entity() {
		m_bounds = new sf::IntRect(0, 0, 0, 0);
	}

	Entity::~Entity() {

	}

	sf::Vector2f Entity::getPosition() const {
		return m_position;
	}

	void Entity::setPosition(sf::Vector2f pos) {
		m_position = pos;
	}

	sf::IntRect* Entity::getBounds() const {
		return m_bounds;
	}

	void Entity::update(float dt) {

	}

	bool Entity::isBlocked(int cx, int cy) {
		return false;
	}

	void Entity::onTouch(Entity e) {

	}

	bool Entity::intersect(sf::IntRect bounds) {
		return m_bounds->intersects(bounds);
	}

	sf::Vector2f Entity::getCenter() {
		return sf::Vector2f(m_bounds->left + m_bounds->width / 2.0f, m_bounds->top + m_bounds->height / 2.0f);
	}

	void Entity::renderBounds(sf::RenderTarget& target) {
		sf::RectangleShape rect(sf::Vector2f(m_bounds->width, m_bounds->height));
		rect.setPosition(sf::Vector2f(m_bounds->left, m_bounds->top));
		rect.setFillColor(sf::Color::Transparent);
		rect.setOutlineColor(sf::Color::Red);
		rect.setOutlineThickness(1);
		target.draw(rect);
	}
}