#pragma once

//GameBaseLibrary Includes
#include <graphics/Drawable.hpp>
#include <graphics/Transformable.hpp>
#include <graphics/Color.hpp>

namespace gbl {
	namespace graphics {
		class Shape : public Drawable, public Transformable {
			public:
				~Shape();

				void setColor(const Color& color);
				void setOutlineColor(const Color& color);
				void setOutlineThickness(float thickness);

				const Color& getColor() const;
				const Color& getOutlineColor() const;
				float getOutlineThickness() const;

				virtual std::size_t getPointCount() const = 0;

				gbl::core::FloatRect getLocalBounds() const;
				gbl::core::FloatRect getGlobalBounds() const;

			protected:

				Shape();
				void update();

			private:

				void updateColor();
				void updateOutlineColor();
				void updateOutline();

				Color m_color;
				Color m_outlineColor;
				float m_outlineThickness;
				gbl::core::FloatRect m_insideBounds;
				gbl::core::FloatRect m_bounds;
		};
	}
}