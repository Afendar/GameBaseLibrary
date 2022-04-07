#pragma once

//Standard C++ Library Includes
#include <memory>
#include <set>

namespace gbl {
	namespace graphics {
		class RadioButton;

		class RadioButtonGroup {
			public:

				typedef std::set<std::weak_ptr<RadioButton>, std::owner_less<std::weak_ptr<RadioButton>>> ContainerType;

				RadioButtonGroup();
				~RadioButtonGroup();

				ContainerType& getMembers();

			private:

				ContainerType m_members;
		};
	}
}