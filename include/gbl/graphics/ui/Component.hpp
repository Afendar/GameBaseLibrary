#pragma once

//Standard C++ Library Includes
#include <memory>

//GameBaseLibrary Includes
#include <core/Vector2.hpp>
#include <core/Rect.hpp>

namespace gbl {
	namespace graphics {
		class Container;

		class Component : public std::enable_shared_from_this<Component> {
			public:
				typedef std::shared_ptr<Component> Ptr;
				typedef std::shared_ptr<const Component> PtrConst;

				Component();
				virtual ~Component();

				bool isVisible() const;
				bool hasFocus() const;

				int getZOrder() const;
				std::shared_ptr<Container> getParent();

				void setVisible(bool visible = true);
				void setZOrder(int zOrder);
				void setParent(Component::Ptr parent);
				void update(float seconds);
				void grabFocus();

				virtual bool isSelected() const;
				virtual void select();
				virtual void deselect();

				virtual gbl::core::FloatRect getGlobalBounds() const;
				virtual gbl::core::FloatRect getLocalBounds() const;
				const gbl::core::Vector2f& getPosition() const;
		};
	}
}