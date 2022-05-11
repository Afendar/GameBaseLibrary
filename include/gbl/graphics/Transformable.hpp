#pragma once

//GameBaseLibrary Inculdes
#include <graphics/Transform.hpp>

namespace gbl {
	namespace graphics {
		class Transformable {
			public:

				virtual ~Transformable() = default;

				void setPosition(const float x, const float y);
				void setPosition(const gbl::core::Vector2f& position) { setPosition(position.m_x, position.m_y); }

				void setOrigin(const float x, const float y);
				void setOrigin(const gbl::core::Vector2f& origin) { setOrigin(origin.m_x, origin.m_y); }

				void setScale(const float factorX, const float factorY);
				void setScale(const gbl::core::Vector2f& factor) { setScale(factor.m_x, factor.m_y); }

				void setRotation(float angle);

				const gbl::core::Vector2f& getPosition() const { return m_position; }
				const gbl::core::Vector2f& getOrigin() const { return m_origin; }
				const gbl::core::Vector2f& getScale() const { return m_scale; }

				const Transform& getTransform() const;

			protected:

				gbl::core::Vector2f m_position{0, 0};
				gbl::core::Vector2f m_origin{0, 0};
				gbl::core::Vector2f m_scale{0, 0};
				float m_rotation = 0;

				mutable Transform m_transform;
		};
	}
}