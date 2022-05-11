//Standard C++ Library Includes
#include <iostream>

//GameBaseLibrary Includes
#include <graphics/RectangleShape.hpp>
#include <core/SDLHeaders.hpp>

namespace gbl {
	namespace graphics {
		RectangleShape::RectangleShape(const gbl::core::Vector2f& size)
		{
			setSize(size);
			m_rect.x = 50;
			m_rect.y = 80;
		}

		std::size_t RectangleShape::getPointCount() const
		{
			return 4;
		}

		void RectangleShape::draw(RenderTarget& target, RenderStates& states) const
		{
			SDL_Renderer* renderer = target.getSDLRenderer();

			SDL_SetRenderDrawColor(renderer, 0, 0, 255, 255);
			SDL_RenderFillRect(renderer, &m_rect);
		}
	}
}