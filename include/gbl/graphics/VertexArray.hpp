#pragma once

#include <vector>

#include <graphics/Drawable.hpp>
#include <graphics/Vertex.hpp>

namespace gbl {
	namespace graphics {
		class VertexArray: public Drawable {
			public:
				VertexArray() {}

				void append(const Vertex& vertex) {
					m_vertices.push_back(vertex);
				}

			private:
				void draw(RenderTarget& target, RenderStates& states) const override {
					if (!m_vertices.empty()) {
						
					}
				}

				std::vector<Vertex> m_vertices;
		};
	}
}