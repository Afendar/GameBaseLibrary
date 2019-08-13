#pragma once

#include "defines.h"
#include "Window.h"
#include "Assets/TexturesLoader.h"

namespace GDLib {
	struct GDLIB_API Context {
		Context() : m_window(nullptr) {}
		Window* m_window;
		Assets::TexturesLoader* m_texturesLoader;
	};
}