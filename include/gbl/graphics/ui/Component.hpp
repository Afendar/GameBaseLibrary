#pragma once

//Standard C++ Library Includes
#include <memory>

//GameBaseLibrary Includes
#include <core/Vector2.hpp>
#include <core/Rect.hpp>
#include <core/input/Event.hpp>

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

				virtual void handleEvent(const gbl::core::Event& evt);

				//virtual void draw() const;
				//gbl::core::Vector2f getTextStringMetrics(const std::string& string, const std::string& font, unsigned int fontSize) const;

			protected:
				bool isMouseInComponent() const;

				virtual void handleMouseMoveEvent(int x, int y) {}
				virtual void handleMouseButtonEvent(gbl::core::Mouse::Button button, bool pressed, int x, int y) {}
				virtual void handleKeyEvent(gbl::core::Keyboard::Key key, bool pressed) {}
				virtual void handleTextEvent(Uint32 character) {}
				virtual void handleMouseEnter(int x, int y) {}
				virtual void handleMouseLeave(int x, int y) {}
				virtual void handleMouseClick(gbl::core::Mouse::Button button, int x, int y) {}
				virtual void handleUpdate(float seconds) {}
				virtual void handleFocusChange(Ptr component) {}

				static bool hasFocus(PtrConst component);

				static void grabFocus(Ptr component);

				std::weak_ptr<Container> m_parent;

			private:
				bool m_selected, m_visible;
				int m_zOrder;
		};
	}
}