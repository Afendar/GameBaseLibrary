#pragma once

#include <graphics/Shape.hpp>

namespace gbl {
	namespace graphics {
		class CircleShape : public Shape {
			public: 
				CircleShape(float radius, std::size_t pointCount = 30);

				void setRadius(float radius);
				float getRadius() const;

				void setPointCount(std::size_t pointCount);
				std::size_t getPointCount() const override;

			private:
				void draw(RenderTarget& target, RenderStates& states) const override;

				float m_radius;
				std::size_t m_pointCount;
		};
	}
}