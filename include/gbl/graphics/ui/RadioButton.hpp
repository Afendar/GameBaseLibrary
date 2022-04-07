#pragma once

//GameBaseLibrary Includes
#include <graphics/ui/CheckBox.hpp>

namespace gbl{
	namespace graphics {
		class RadioButtonGroup;

		class RadioButton : public CheckBox {
			public:
				typedef std::shared_ptr<RadioButton> Ptr;
				typedef std::shared_ptr<const RadioButton> PtrConst;

				RadioButton();
				~RadioButton();

				std::shared_ptr<RadioButtonGroup> getGroup() const;

				void setGroup(std::shared_ptr<RadioButtonGroup> group);
				void setActive(bool active);

			protected:

				void handleMouseClick(gbl::core::Mouse::Button button, int x, int y) override;

			private:

				virtual void draw() const;

				std::shared_ptr<RadioButtonGroup> m_group;
		};
	}
}