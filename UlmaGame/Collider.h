#pragma once

namespace Game {
	namespace Core {
		class Collider2D {
		public:
			Collider2D();
			virtual ~Collider2D();

			bool enable;	//Õ“Ë”»’è‚ª—LŒø‚©H
			bool isTrigger;	//Trigger‚©H
		};
	}
}