#pragma once

#include "defines.h"
#include "Window.h"

namespace GDLib {
	struct GDLIB_API Context {
		Context() : m_window(nullptr) {}
		Window* m_window;
	};
}