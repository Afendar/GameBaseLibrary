#include <graphics/RenderTarget.hpp>
#include <graphics/Drawable.hpp>

namespace gbl{
	namespace graphics{
		void RenderTarget::draw(Drawable& drawable, RenderStates states)
		{
			drawable.draw(*this, states);
		}
	}
}