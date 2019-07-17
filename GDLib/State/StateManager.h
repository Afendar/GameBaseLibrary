#pragma once

#include <vector>
#include <unordered_map>
#include <functional>

#include "../defines.h"
#include "BaseState.h"
#include "../Context.h"

namespace GDLib {
	namespace State {
		using StateContainer = std::vector<std::pair<unsigned int, BaseState*>>;
		using TypeContainer = std::vector<unsigned int>;
		using StateFactory = std::unordered_map<unsigned int, std::function<BaseState*(void)>>;

		class GDLIB_API StateManager {
			public:
				StateManager(Context* context);
				~StateManager();

				void update(const sf::Time& time);
				void draw();

				void processRequests();

				Context* GetContext();

				bool hasState(const unsigned int& type);
				void switchTo(const unsigned int& type);
				void remove(const unsigned int& type);

				template<class T>
				void registerState(const unsigned int& type) {
					m_stateFactory[type] = [this]() -> BaseState*
					{
						return new T(this);
					};
				}

			private:
				void createState(const unsigned int& type);
				void removeState(const unsigned int& type);

				Context* m_context;
				StateContainer m_states;
				TypeContainer m_toRemove;
				StateFactory m_stateFactory;
		};
	}
}