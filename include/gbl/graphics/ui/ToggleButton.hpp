#pragma once

//GameBaseLibrary Includes
#include <graphics/ui/Button.hpp>

namespace gbl {
	namespace graphics {
		class RadioButtonGroup;

		class ToggleButton : public Button
		{
		public:
			typedef std::shared_ptr<ToggleButton> Ptr;
			typedef std::shared_ptr<const ToggleButton> PtrConst;

			ToggleButton();
			~ToggleButton();


			void select();
			void deselect();

			void setActive(bool active);
			bool isActive() const;

		protected:
			bool m_active;

		private:
			void handleMouseClick(gbl::core::Mouse::Button button, int x, int y) override;
		};
	}
}