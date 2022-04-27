#pragma once

#include <core/Window.hpp>
#include <graphics/RenderTarget.hpp>

namespace gbl {
	namespace graphics {
		class RenderWindow : public gbl::core::Window, public RenderTarget {
			SDL_Renderer* getSDLRenderer() override {
				return SDL_GetRenderer(m_window.get());
			}
		};
	}
}