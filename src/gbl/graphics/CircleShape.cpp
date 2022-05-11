#include <graphics/CircleShape.hpp>

gbl::graphics::CircleShape::CircleShape(float radius, std::size_t pointCount):
	m_radius(radius),
	m_pointCount(pointCount)
{
	update();
}

void gbl::graphics::CircleShape::setRadius(float radius)
{
	m_radius = radius;
	update();
}

float gbl::graphics::CircleShape::getRadius() const
{
	return m_radius;
}

void gbl::graphics::CircleShape::setPointCount(std::size_t pointCount)
{
	m_pointCount = pointCount;
	update();
}

std::size_t gbl::graphics::CircleShape::getPointCount() const
{
	return m_pointCount;
}

void gbl::graphics::CircleShape::draw(RenderTarget& target, RenderStates& states) const
{
    const int32_t diameter = (m_radius * 2);

    int32_t x = (m_radius - 1);
    int32_t y = 0;
    int32_t tx = 1;
    int32_t ty = 1;
    int32_t error = (tx - diameter);
    SDL_Renderer* renderer = target.getSDLRenderer();

    SDL_SetRenderDrawColor(renderer, 0, 255, 255, 255);

    while (x >= y)
    {
        //  Each of the following renders an octant of the circle
        SDL_RenderDrawPoint(renderer, m_position.m_x + x, m_position.m_y - y);
        SDL_RenderDrawPoint(renderer, m_position.m_x + x, m_position.m_y + y);
        SDL_RenderDrawPoint(renderer, m_position.m_x - x, m_position.m_y - y);
        SDL_RenderDrawPoint(renderer, m_position.m_x - x, m_position.m_y + y);
        SDL_RenderDrawPoint(renderer, m_position.m_x + y, m_position.m_y - x);
        SDL_RenderDrawPoint(renderer, m_position.m_x + y, m_position.m_y + x);
        SDL_RenderDrawPoint(renderer, m_position.m_x - y, m_position.m_y - x);
        SDL_RenderDrawPoint(renderer, m_position.m_x - y, m_position.m_y + x);

        if (error <= 0)
        {
            ++y;
            error += ty;
            ty += 2;
        }

        if (error > 0)
        {
            --x;
            tx += 2;
            error += (tx - diameter);
        }
    }
}
