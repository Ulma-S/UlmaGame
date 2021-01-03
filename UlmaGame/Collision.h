#pragma once

namespace Game {
	namespace Core {
		class Actor;
		class CircleCollider;
		class BoxCollider2D;

		class Collision {
		public:
			static bool Intersect(Actor& a1, Actor& a2);

		private:
			static bool Intersect(const CircleCollider& c1, const CircleCollider& c2);	//‰~“¯Žm‚Ì”»’è
		};
	}
}