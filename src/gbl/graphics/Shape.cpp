//GameBaseLibrary Includes
#include <graphics/Shape.hpp>

namespace gbl {
	namespace graphics {
		Shape::~Shape()
		{
		}
		void Shape::setColor(const Color& color)
		{
			m_color = color;
			updateColor();
		}
		void Shape::setOutlineColor(const Color& color)
		{
			m_outlineColor = color;
			updateOutlineColor();
		}
		void Shape::setOutlineThickness(float thickness)
		{
			m_outlineThickness = thickness;
			update();
		}
		const Color& Shape::getColor() const
		{
			return m_color;
		}
		const Color& Shape::getOutlineColor() const
		{
			return m_outlineColor;
		}
		float Shape::getOutlineThickness() const
		{
			return m_outlineThickness;
		}
		std::size_t Shape::getPointCount() const
		{
			return std::size_t();
		}
		gbl::core::FloatRect Shape::getLocalBounds() const
		{
			return m_bounds;
		}
		gbl::core::FloatRect Shape::getGlobalBounds() const
		{
			return getTransform().transformRect(getLocalBounds());
		}
		Shape::Shape() :
			m_color(255, 255, 255),
			m_outlineColor(255, 255, 255),
			m_outlineThickness(0),
			m_insideBounds(),
			m_bounds()
		{
		}
		void Shape::update()
		{
			updateColor();
			updateOutline();
		}
		void Shape::updateColor()
		{
		}
		void Shape::updateOutlineColor()
		{
		}
		void Shape::updateOutline()
		{
			updateOutlineColor();
		}
	}
}