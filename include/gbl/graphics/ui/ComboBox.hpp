#pragma once

//Standard C++ Library Includes
#include <vector>
#include <memory>
#include <functional>

//GameBaseLibrary Includes
#include <graphics/ui/Component.hpp>

namespace gbl {
	namespace graphics {
		class Scrollbar;

		class ComboBox : public Component {
			public:
				typedef std::shared_ptr<ComboBox> Ptr;
				typedef std::shared_ptr<const ComboBox> PtrConst;
				typedef int IndexType;
				typedef std::function<void()> Callback;

				static const IndexType NONE;

				ComboBox();
				~ComboBox();

				IndexType getSelectedItem() const;
				IndexType getHighlightedItem() const;
				const std::string& getSelectedText() const;

				gbl::core::FloatRect getLocalBounds() const override;

				void appendItem(const std::string& text);
				void setPlaceholder(const std::string& placeholder);

				void onChangeCallback(Callback callback);

				IndexType getItemCount() const;

				IndexType getDisplayedItemCount() const;
				IndexType getDisplayedItemStart() const;

				const std::string& getItem(IndexType index) const;

				bool isDropdownDisplayed() const;

			private:
				void handleMouseEnter(int x, int y) override;
				void handleMouseLeave(int x, int y) override;
				void handleMouseMoveEvent(int x, int y) override;
				void handleMouseButtonEvent(gbl::core::Mouse::Button button, bool pressed, int x, int y) override;

				virtual void draw() const;
				IndexType m_activeItem, m_highlightedItem, m_startEntry;
				std::vector<std::string> m_entries;
				Callback m_onChangeCallback;

				std::string m_selectedItem;
				std::string m_placeholder;
				//gbl::graphics::RectangleShape m_borders, m_dropdown;
				bool m_opened;
		};
	}
}