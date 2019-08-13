#pragma once

#include <SFML/Graphics.hpp>
#include "defines.h"

namespace GDLib {
	class GDLIB_API Entity {
		public:
			Entity();
			~Entity();

			sf::Vector2f getPosition() const;
			void setPosition(sf::Vector2f pos);
			sf::IntRect* getBounds() const;

			virtual void update(float dt);

			bool isBlocked(int cx, int cy);
			void onTouch(Entity e);
			bool intersect(sf::IntRect bounds);
			sf::Vector2f getCenter();
			void renderBounds(sf::RenderTarget& target);

		protected:
			sf::Vector2f m_position;
			sf::IntRect* m_bounds;
	};
}