#include "Collision.h"
#include "Collider.h"
#include "Actor.h"
#include "Math.h"

using namespace Game::Core;

bool Collision::Intersect(Actor& a1, Actor& a2) {
	return false;
}


bool Collision::Intersect(const CircleCollider& c1, const CircleCollider& c2) {
	float distance = (c1.centerPosition - c2.centerPosition).Magnitude();
	if (distance <= c1.radius + c2.radius) {
		return true;
	}
	return false;
}