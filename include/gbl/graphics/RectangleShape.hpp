#pragma once

//Standard C++ Library Includes
#include <array>

//GameBaseLibrary Includes
#include <graphics/Shape.hpp>

namespace gbl {
	namespace graphics {
		class VertexArray;

		class RectangleShape : public Shape {
			public:
				RectangleShape() : RectangleShape(gbl::core::Vector2f{ 0, 0 }) {}
				RectangleShape(float width, float height) : RectangleShape(gbl::core::Vector2f{ width, height }) {}
				RectangleShape(const gbl::core::Vector2f& size = gbl::core::Vector2f(0, 0));

				float getWidth() const { return m_rect.w; }
				float getHeight() const { return m_rect.h; }

				gbl::core::Vector2f getSize() const { return gbl::core::Vector2f{ static_cast<float>(m_rect.w), static_cast<float>(m_rect.h) }; }

				void setSize(float width, float height) { m_rect.w = width; m_rect.h = height; }
				void setSize(const gbl::core::Vector2f& size) { m_rect.w = size.m_x; m_rect.h = size.m_y; }

				std::size_t getPointCount() const override;

				//void setOutlineColor(const Color& color) { m_outlineColor = color; }
				//void setOutlineThickness(int outlineThickness) { m_outlineThickness = outlineThickness; }

			private:

				void draw(RenderTarget& target, RenderStates& states) const override;

				SDL_Rect m_rect{0, 0, 0, 0};
				int m_outlineThickness = 0;
		};
	}
}