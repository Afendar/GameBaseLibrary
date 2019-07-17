#pragma once

#include <vector>
#include <SFML/System/Time.hpp>
#include <SFML/Graphics/View.hpp>

#include "../defines.h"

namespace GDLib {
	namespace State {
		class StateManager;

		class GDLIB_API BaseState {
			friend class StateManager;

		public:
			BaseState(StateManager* stateManager);
			virtual ~BaseState();

			virtual void onCreate() = 0;
			virtual void onDestroy() = 0;

			virtual void activate() = 0;
			virtual void desactivate() = 0;

			virtual void update(const sf::Time& time) = 0;
			virtual void draw() = 0;

			void setTransparent(const bool& transparent);
			bool isTransparent() const;

			void setTranscendent(const bool& transcendent);
			bool isTranscendent() const;

			sf::View& getView();
			StateManager* getStateManager();

		protected:

			StateManager* m_stateManager;
			bool m_transparent;
			bool m_transcendent;
			sf::View m_view;

		private:

		};
	}
}