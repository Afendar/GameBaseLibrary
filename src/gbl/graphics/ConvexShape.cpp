//GameBaseLibrary Includes
#include <graphics/ConvexShape.hpp>

void gbl::graphics::ConvexShape::setPointCount(int pointCount)
{
	m_points.resize(pointCount);
	update();
}

void gbl::graphics::ConvexShape::setPoint(int index, const gbl::core::Vector2f& point)
{
	m_points[index] = point;
	update();
}

std::size_t gbl::graphics::ConvexShape::getPointCount() const
{
	return m_points.size();
}

void gbl::graphics::ConvexShape::draw(RenderTarget& target, RenderStates& states) const
{
	SDL_Renderer* renderer = target.getSDLRenderer();
	SDL_SetRenderDrawColor(renderer, 255, 255, 255, 255);

	for (int i = 0; i < m_points.size(); i++) {
		gbl::core::Vector2f startPoint = m_points[i];
		gbl::core::Vector2f endPoint = m_points[(i + 1 > m_points.size() - 1) ? 0 : i + 1];
		SDL_RenderDrawLine(renderer, startPoint.m_x, startPoint.m_y, endPoint.m_x, endPoint.m_y);
	}
}
