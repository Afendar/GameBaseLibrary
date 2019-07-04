#pragma once

#include <unordered_map>
#include "lib/glm/glm.hpp"

namespace GDLib {
	class InputManager {
		public:

			InputManager(): m_mouseCoords(0.0f) {

			}
			~InputManager() {

			}

			void update() {
				for (auto& it : m_keyMap) {
					m_previousKeyMap[it.first] = it.second;
				}
			}

			void keyPress(unsigned int keyID) {
				m_keyMap[keyID] = true;
			}

			void keyRelease(unsigned int keyID) {
				m_keyMap[keyID] = false;
			}

			void setMouseCoords(float x, float y) {
				m_mouseCoords.x = x;
				m_mouseCoords.y = y;
			}

			bool isKeyDown(unsigned int keyID) {
				auto it = m_keyMap.find(keyID);
				if (it != m_keyMap.end()) {
					return it->second;
				}
				return false;
			}

			bool isKeyPressed(unsigned int keyID) {
				if (isKeyDown(keyID) == true && wasKeyDown(keyID) == false) {
					return true;
				}
				return false;
			}

			glm::vec2 getMouseCoords() const {
				return m_mouseCoords;
			}

		private:

			bool wasKeyDown(unsigned int keyID) {
				auto it = m_previousKeyMap.find(keyID);
				if (it != m_previousKeyMap.end()) {
					return it->second;
				}
				return false;
			}

			std::unordered_map<unsigned int, bool> m_keyMap;
			std::unordered_map<unsigned int, bool> m_previousKeyMap;
			glm::vec2 m_mouseCoords;
	};
}