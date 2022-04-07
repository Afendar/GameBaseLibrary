#pragma once

//Standard C++ Library Includes
#include <vector>
#include <memory>

//GameBaseLibrary Includes
#include <graphics/ui/Component.hpp>

namespace gbl {
	namespace graphics {
		class Container : public Component
		{
		public:
			typedef std::shared_ptr<Container> Ptr;
			typedef std::shared_ptr<const Container> PtrConst;
			typedef std::vector<Component::Ptr> ComponentList;

			Container();
			~Container();

			void add(Component::Ptr component);

			bool isChild(Component::Ptr component) const;

			const ComponentList& getChildren() const;

			virtual void handleEvent(const gbl::core::Event& evt) override;

		protected:
			void handleUpdate(float seconds) override;

			std::vector<Component::Ptr> m_childrens;

		private:

			virtual void draw() const;
		};
	}
}