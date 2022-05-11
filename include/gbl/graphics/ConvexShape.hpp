#pragma once

//Standard C++ Library Includes
#include <vector>

//GameBaseLibrary Includes
#include <graphics/Shape.hpp>

namespace gbl {
	namespace graphics {
		class ConvexShape : public Shape {
			public:
				ConvexShape() = default;

				void setPointCount(int pointCount);
				void setPoint(int index, const gbl::core::Vector2f& point);

				std::size_t getPointCount() const override;
			private:

				void draw(RenderTarget& target, RenderStates& states) const override;

				std::vector<gbl::core::Vector2f> m_points;
		};
	}
}