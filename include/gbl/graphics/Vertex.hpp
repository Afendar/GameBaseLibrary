#pragma once

#include <core/Vector2.hpp>

namespace gbl {
	namespace graphics {
		class Vertex {

			Vertex() : m_position(0, 0), m_texCoords(0, 0) {}
			Vertex(const gbl::core::Vector2f& position) : m_position(position), m_texCoords(0, 0) {}
			Vertex(const gbl::core::Vector2f& position, const gbl::core::Vector2f& texCoords) : m_position(position), m_texCoords(texCoords) {}

			gbl::core::Vector2f m_position;
			gbl::core::Vector2f m_texCoords;
		};
	}
}