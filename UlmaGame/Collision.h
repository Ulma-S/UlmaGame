#pragma once
#include "Math.h"

namespace UlmaEngine {
	class Actor;
	class CircleCollider;
	class BoxCollider2D;

	class Collision {
	public:
		static bool ComputeIntersection(Actor& a1, Actor& a2);

	private:
		static bool Intersect(const CircleCollider& c1, const CircleCollider& c2);	//‰~“¯Žm‚Ì”»’è
		static bool Intersect(const BoxCollider2D& c1, const BoxCollider2D& c2);	//‹éŒ`“¯Žm‚Ì”»’è
		static bool Intersect(const CircleCollider& c1, const BoxCollider2D& c2);	//‰~‚Æ‹éŒ`‚Ì”»’è
	};
}