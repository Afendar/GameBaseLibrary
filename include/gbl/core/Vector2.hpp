#pragma once

namespace gbl {
	namespace core {
		template<typename T>
		class Vector2 {
			public:
				Vector2() = default;
				constexpr Vector2(T x, T y) : m_x(x), m_y(y) {}

				template<typename U>
				Vector2(const Vector2<U> &vector2) : m_x(vector2.m_x), m_y(vector2.m_y) {}

				Vector2 operator-() const { return Vector2{ -m_x, -m_y }; }

				Vector2 &operator+=(const Vector2& vector) { *this = operator+(vector); return *this; }
				Vector2& operator-=(const Vector2& vector) { *this = operator-(vector); return *this; }
				Vector2& operator*=(const Vector2& vector) { *this = operator*(vector); return *this; }
				Vector2& operator/=(const Vector2& vector) { *this = operator/(vector); return *this; }

				T m_x, m_y;

				template<typename U>
				auto operator+(const Vector2<U> &vector) -> Vector2<decltype(m_x + vector.m_x)> {
					return { m_x + vector.m_x, m_y + vector.m_y };
				}
				template<typename U>
				auto operator-(const Vector2<U>& vector) -> Vector2<decltype(m_x - vector.m_x)> {
					return { m_x - vector.m_x, m_y - vector.m_y };
				}
				template<typename U>
				auto operator*(const Vector2<U>& vector) -> Vector2<decltype(m_x * vector.m_x)> {
					return { m_x * vector.m_x, m_y * vector.m_y };
				}
				template<typename U>
				auto operator/(const Vector2<U>& vector) -> Vector2<decltype(m_x / vector.m_x)> {
					return { m_x / vector.m_x, m_y / vector.m_y };
				}

				bool operator==(const Vector2<T>& vector) { return m_x == vector.m_x && m_y == vector.m_y; }
				bool operator!=(const Vector2<T>& vector) { return !operator==(vector); }
				bool operator<(const Vector2<T>& vector) { return m_x < vector.m_x && m_y < vector.m_y; }
				bool operator>(const Vector2<T>& vector) { return m_x > vector.m_x && m_y > vector.m_y; }
		};

		using Vector2i = Vector2<int>;
		using Vector2u = Vector2<unsigned int>;
		using Vector2f = Vector2<float>;
		using Vector2d = Vector2<double>;
	}
}