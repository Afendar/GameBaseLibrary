#pragma once

#include <graphics/ui/Component.hpp>

namespace gbl {
	namespace graphics {
		class Label : public Component
		{
			public:
				typedef std::shared_ptr<Label> Ptr;

				Label();
				Label(const std::string& text, const std::string& font);

				virtual bool isSelected() const;
				void setText(const std::string& text);
				//void setFillColor(sf::Color color);
				void setFontSize(unsigned int size);
				virtual void handleEvent(const gbl::core::Event& evt);

				gbl::core::FloatRect getGlobalBounds() const override;

			private:
				void draw() const;
				void centerOrigin();

				std::string m_text;
		};
	}
}