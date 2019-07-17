#include "BaseState.h"

namespace GDLib {
	namespace State {
		BaseState::BaseState(StateManager* stateManager) : m_stateManager(stateManager),
			m_transparent(false),
			m_transcendent(false) {
		}

		BaseState::~BaseState(){}

		void BaseState::setTransparent(const bool& transparent) {
			m_transparent = transparent;
		}

		bool BaseState::isTransparent() const {
			return m_transparent;
		}

		void BaseState::setTranscendent(const bool& transcendent) {

		}

		bool BaseState::isTranscendent() const {
			return m_transcendent;
		}

		sf::View& BaseState::getView() {
			return m_view;
		}

		StateManager* BaseState::getStateManager() {
			return m_stateManager;
		}
	}
}