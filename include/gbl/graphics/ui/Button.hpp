#pragma once

//Standard C++ Libary Includes
#include <functional>
#include <string>

//GameBaseLibrary Includes
#include <graphics/ui/Component.hpp>

namespace gbl {
	namespace graphics {
		class Button : public Component
		{
		public:
			typedef std::function<void()> Callback;

			Button();
			~Button();

			void setText(const std::string& text);
			void setCallback(Callback callback);
			void setWidth(float width);
			void setFontSize(int size);
			//void setIcon(sf::Sprite& icon);
			//void setBackgroundColor(sf::Color& color);

			virtual void select();
			virtual void deselect();

			gbl::core::FloatRect getLocalBounds() const override;

		protected:
			void centerOrigin();

			//sf::Sprite m_icon;
			//sf::Text m_text;
			//sf::RectangleShape m_background, m_borders;
			Callback m_callback;

		private:
			void handleMouseEnter(int x, int y) override;
			void handleMouseLeave(int x, int y) override;
			void handleMouseButtonEvent(gbl::core::Mouse::Button button, bool pressed, int x, int y) override;

			virtual void draw() const;
		};
	}
}