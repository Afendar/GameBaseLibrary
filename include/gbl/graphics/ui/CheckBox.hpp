#pragma once

//GameBaseLibrary Includes
#include <graphics/ui/Label.hpp>
#include <graphics/ui/ToggleButton.hpp>

namespace gbl {
	namespace graphics {
		class CheckBox : public ToggleButton {
			typedef std::shared_ptr<CheckBox> Ptr;
			typedef std::shared_ptr<const CheckBox> PtrConst;

		public:
			CheckBox();
			~CheckBox();

			void setLabel(const std::string& label);
			void setLabelFontSize(unsigned int fontSize);
			//void setLabelColor(sf::Color& color);

			gbl::core::FloatRect getLocalBounds() const override;

		private:
			virtual void draw() const;

			Label::Ptr m_label;
		};
	}
}