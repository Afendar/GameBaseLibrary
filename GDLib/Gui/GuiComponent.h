#pragma once

#include <string>
#include <SFML/Graphics.hpp>

#include "../defines.h"
#include "GuiStyle.h"

namespace GDLib {
	namespace Gui {

		enum class GDLIB_API GuiComponentType
		{
			NONE = -1,
			WINDOW,
			LABEL,
			BUTTON,
			SCROLLBAR,
			TEXTFIELD,
			CHECKBOX,
			RADIO
		};

		class GDLIB_API GuiComponent {
			public:
				GuiComponent(const std::string& name, const GuiComponentType& type);
				virtual ~GuiComponent();

				virtual void onClick(const sf::Vector2f& mousePos) = 0;
				virtual void onRelease() = 0;
				virtual void onHover(const sf::Vector2f& mousePos) = 0;
				virtual void onLeave() = 0;

				virtual void update(float dt) = 0;
				virtual void draw(sf::RenderTarget* target) = 0;

				GuiComponentType getType();
				const std::string& getName() const;
				const sf::Vector2f& getPosition() const;
				const sf::Vector2f& getSize() const;
				GuiComponentState getState() const;

				bool needsRedraw() const;
				bool isActive() const;
				bool isInside(const sf::Vector2f& pointCoords) const;
				bool isControl() const;

			protected:
				/*protecetd members */
				std::string m_name;
				sf::Vector2f m_position;
				GuiComponentType m_type;
				GuiComponentState m_state;

				bool m_needsRedraw;
				bool m_active;
				bool m_isControl;
		};
	}
}