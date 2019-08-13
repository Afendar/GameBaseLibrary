#pragma once

#include "../defines.h"

namespace GDLib {
	namespace Gui {
		enum GDLIB_API GuiEventType {
			NONE,
			CLICK,
			RELEASE,
			HOVER,
			LEAVE
		};

		struct GDLIB_API ClickCoordinates {
			float x, y;
		};

		struct GDLIB_API GuiEvent {
			GuiEventType m_type;
			const char* m_element;
			const char* m_interface;
			union {
				ClickCoordinates m_clickCoords;
			};
		};
	}
}