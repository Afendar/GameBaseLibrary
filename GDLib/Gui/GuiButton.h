#pragma once

#include "GuiComponent.h"

namespace GDLib {
	namespace Gui {
		class GDLIB_API GuiButton : public GuiComponent
		{
			public:
				GuiButton(const std::string& name);
				~GuiButton();

				void readIn(std::stringstream& stream);
				void onClick(const sf::Vector2f& mousePos);
				void onRelease();
				void onHover(const sf::Vector2f& mousePos);
				void onLeave();
				void update(float dt);
				void draw(sf::RenderTarget* target);
		};
	}
}