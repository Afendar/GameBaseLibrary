#pragma once

#ifdef GDLIB_EXPORTS
#define GDLIB_API __declspec(dllexport)
#else
#define GDLIB_API __declspec(dllimport)
#endif

#include <unordered_map>
#include "lib/glm/glm.hpp"

namespace GDLib {
	class GDLIB_API InputManager {
		public:

			InputManager();
			~InputManager();

			void update();

			void keyPress(unsigned int keyID);
			void keyRelease(unsigned int keyID);
			void setMouseCoords(float x, float y);

			bool isKeyDown(unsigned int keyID);
			bool isKeyPressed(unsigned int keyID);

			glm::vec2 getMouseCoords() const;

		private:

			bool wasKeyDown(unsigned int keyID);

			std::unordered_map<unsigned int, bool> m_keyMap;
			std::unordered_map<unsigned int, bool> m_previousKeyMap;
			glm::vec2 m_mouseCoords;
	};
}