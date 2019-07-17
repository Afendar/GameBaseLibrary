#include "StateManager.h"

namespace GDLib {
	namespace State {

		StateManager::StateManager(Context* context): m_context(context){}

		StateManager::~StateManager(){
			for (auto &it : m_states) {
				it.second->onDestroy();
				delete it.second;
			}
		}

		void StateManager::update(const sf::Time& time) {
			if (m_states.empty()) { return; }
			if (m_states.back().second->isTranscendent() && m_states.size() > 1) {
				auto it = m_states.end();
				while (it != m_states.begin()) {
					if (it != m_states.end()) {
						if (!it->second->isTranscendent()) {
							break;
						}
					}
				}
				for (; it != m_states.end(); ++it) {
					it->second->update(time);
				}
			}
			else {
				m_states.back().second->update(time);
			}
		}

		void StateManager::draw() {
			if (m_states.empty()) { return; }
			if (m_states.back().second->isTransparent() && m_states.size() > 1) {
				auto it = m_states.end();
				while (it != m_states.begin()) {
					if (it != m_states.end()) {
						if (!it->second->isTransparent()) {
							break;
						}
					}
				}
				for (; it != m_states.end(); ++it) {
					it->second->draw();
				}
			}
			else {
				m_states.back().second->draw();
			}
		}

		void StateManager::processRequests() {
			while (m_toRemove.begin() != m_toRemove.end()) {
				removeState(*m_toRemove.begin());
				m_toRemove.erase(m_toRemove.begin());
			}
		}

		Context* StateManager::GetContext() {
			return m_context;
		}

		bool StateManager::hasState(const unsigned int& type) {
			for (auto it : m_states) {
				if (it.first == type) {
					auto removed = std::find(m_toRemove.begin(), m_toRemove.end(), type);
					if (removed == m_toRemove.end()) { return true; }
					return false;
				}
			}
			return false;
		}

		void StateManager::switchTo(const unsigned int& type) {
			for (auto it = m_states.begin() ; it != m_states.end() ; ++it) {
				if (it->first == type) {
					m_states.back().second->desactivate();
					unsigned int tmpType = it->first;
					BaseState* tmpState = it->second;
					m_states.erase(it);
					m_states.emplace_back(tmpType, tmpState);
					tmpState->activate();
					return;
				}
			}

			if (!m_states.empty()) { m_states.back().second->desactivate(); }
			createState(type);
			m_states.back().second->activate();
		}

		void StateManager::remove(const unsigned int& type) {
			m_toRemove.push_back(type);
		}

		void StateManager::createState(const unsigned int& type) {
			auto newState = m_stateFactory.find(type);
			if (newState == m_stateFactory.end()) { return; }
			BaseState* state = newState->second();
			m_states.emplace_back(type, state);
			state->onCreate();
		}

		void StateManager::removeState(const unsigned int& type) {
			for (auto it = m_states.begin(); it != m_states.end(); ++it) {
				if (it->first == type) {
					it->second->onDestroy();
					delete it->second;
					m_states.erase(it);
					return;
				}
			}
		}
	}
}