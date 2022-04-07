#pragma once

//Standard C++ Library Includes
#include <algorithm>

//GameBaseLibrary Includes
#include <core/Vector2.hpp>

namespace gbl {
	namespace core {
		template<typename T>
		class Rect {
			public:
				Rect() = default;

				Rect(T x, T y, T sizeX, T sizeY): m_x(x), m_y(y), m_sizeX(sizeX), m_sizeY(sizeY) {}

				Rect(const Vector2<T>& position, const Vector2<T>& size): m_x(position.m_x), m_y(position.m_y), m_sizeX(size.m_x), m_sizeY(size.m_y) {}

				template<typename U>
				explicit Rect(const Rect<U>& rect) : Rect(rect.m_x, rect.m_y, rect.m_sizeX, rect.m_sizeY) {}

				bool contains(T x, T y) const {
					T x2 = m_x + m_sizeX;
					T y2 = m_y + m_sizeY;

					return (x >= m_x) && (x < x2) && (y >= m_y) && (y < y2);
				}

				bool contains(const Vector2<T>& point) const {
					return contains(point.m_x, point.m_y);
				}

				bool intersects(const Rect<T>& rect) const {
					return (std::max(m_x, rect.m_x) < std::min(m_x + m_sizeX, rect.m_x + rect.m_sizeX))
						& (std::max(m_y, rect.m_y) < std::min(m_y + m_sizeY, rect.m_y + rect.m_sizeY));
				}

				bool operator==(const Rect<T>& rect) const { return x == rect.m_x && y == rect.m_y && m_sizeX == rect.m_sizeX && m_sizeY == rect.m_sizeY; }

				bool operator!=(const Rect<T>& rect) const { return !operator==(rect); }

				T m_x = 0;
				T m_y = 0;
				T m_sizeX = 0;
				T m_sizeY = 0;
		};

		using IntRect = Rect<int>;
		using FloatRect = Rect<float>;
	}
}