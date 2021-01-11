#include "Collision.h"
#include "Collider.h"
#include "Actor.h"

using namespace UlmaEngine;

void AddHitData2D(Actor& a1, Actor& a2, Collider2D& c1, Collider2D& c2, Math::Vector2 hitPos);
void RemoveHitData2D(Actor& a1, Actor& a2, Collider2D& c1, Collider2D& c2);

bool Collision::Intersect(Actor& a1, Actor& a2) {
	//‰~“¯Žm‚Ì”»’è
	auto a1Circ = a1.GetComponent<CircleCollider>();
	auto a2Circ = a2.GetComponent<CircleCollider>();
	if (a1Circ != nullptr && a2Circ != nullptr) {
		if (Intersect(*a1Circ, *a2Circ)) {
			AddHitData2D(a1, a2, *a1Circ, *a2Circ, Math::Vector2(0.0, 0.0));
			return true;
		}
		else {
			RemoveHitData2D(a1, a2, *a1Circ, *a2Circ);
		}
	}
	return false;
}


bool Collision::Intersect(const CircleCollider& c1, const CircleCollider& c2) {
	if (!c1.enable || !c2.enable) return false;
	float distance = (c1.centerPosition - c2.centerPosition).Magnitude();
	if (distance <= c1.radius + c2.radius) {
		return true;
	}
	return false;
}


void AddHitData2D(Actor& a1, Actor& a2, Collider2D& c1, Collider2D& c2, Math::Vector2 hitPos) {
	//Šù‚É’Ç‰Á‚³‚ê‚Ä‚¢‚é‚©Šm”F
	auto it = c1.hitData.begin();
	for (; it != c1.hitData.end(); ++it) {
		if ((*it).actor == &a2) break;
	}
	//‘¶Ý‚µ‚Ä‚¢‚È‚¯‚ê‚Î’Ç‰Á
	if (it == c1.hitData.end()) {
		c1.hitData.emplace_back(HitData2D(a2, hitPos));
	}
	else {
		(*it).hitPosition = hitPos;
	}

	auto it2 = c2.hitData.begin();
	for (; it2 != c2.hitData.end(); ++it2) {
		if ((*it2).actor == &a1) break;
	}
	if (it2 == c2.hitData.end()) {
		c2.hitData.emplace_back(HitData2D(a1));
	}
	else {
		(*it).hitPosition = hitPos;
	}
}


void RemoveHitData2D(Actor& a1, Actor& a2, Collider2D& c1, Collider2D& c2) {
	auto it1 = c1.hitData.begin();
	for (; it1 != c1.hitData.end(); ++it1) {
		if ((*it1).actor == &a2) break;
	}
	if (it1 != c1.hitData.end()) {
		c1.hitData.erase(it1);
	}

	auto it2 = c2.hitData.begin();
	for (; it2 != c2.hitData.end(); ++it2) {
		if ((*it2).actor == &a1) break;
	}
	if (it2 != c2.hitData.end()) {
		c2.hitData.erase(it2);
	}
}