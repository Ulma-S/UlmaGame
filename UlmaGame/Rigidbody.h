#pragma once
#include "Component.h"

namespace UlmaEngine {
	class Actor;

	class Rigidbody : public Component {
	public:
		Rigidbody(Actor& owner);

		~Rigidbody();
	};
};