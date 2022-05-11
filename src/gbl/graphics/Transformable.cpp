//GameBaseLibrary Includes
#include <graphics/Transformable.hpp>

namespace gbl {
	namespace graphics {
		void Transformable::setPosition(const float x, const float y)
		{
			m_position.m_x = x;
			m_position.m_y = y;
		}
		void Transformable::setOrigin(const float x, const float y)
		{
		}
		void Transformable::setScale(const float factorX, const float factorY)
		{
		}
		void Transformable::setRotation(float angle)
		{
		}
		const Transform& Transformable::getTransform() const
		{
			return m_transform;
		}
	}
}