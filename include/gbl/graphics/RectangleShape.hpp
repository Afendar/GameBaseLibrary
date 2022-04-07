#pragma once

//Standard C++ Library Includes
#include <array>

#include <core/Vector2.hpp>

namespace gbl {
	namespace graphics {
		class RectangleShape {
			public:
				RectangleShape();
				RectangleShape(float width, float height);

				//const Color &getColor() const {return m_color;}
				//void setFillColor(const Color &color) {m_color = color;}

				float getWidth() const { return m_width; }
				float getHeight() const { return m_height; }

				gbl::core::Vector2f getSize() const { return gbl::core::Vector2f{ m_width, m_height }; }

				void setSize(float width, float height) { m_width = width; m_height = height; }
				void setSize(const gbl::core::Vector2f& size) { m_width = size.m_x; m_height = size.m_y; }

				//void setOutlineColor(const Color& color) { m_outlineColor = color; }
				//void setOutlineThickness(int outlineThickness) { m_outlineThickness = outlineThickness; }

			private:

				void draw() const;

				float m_width = 0;
				float m_height = 0;
				int m_outlineThickness = 0;
		};
	}
}