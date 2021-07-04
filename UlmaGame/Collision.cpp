#include "Collision.h"
#include "Collider.h"
#include "Actor.h"
#include "Debug.h"

using namespace UlmaEngine;

void AddHitData2D(Actor& a1, Actor& a2, Collider2D& c1, Collider2D& c2, Math::Vector2 hitPos);
void RemoveHitData2D(Actor& a1, Actor& a2, Collider2D& c1, Collider2D& c2);

bool Collision::ComputeIntersection(Actor& a1, Actor& a2) {
	//円同士の判定
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

	//矩形同士の判定
	auto a1Box = a1.GetComponent<BoxCollider2D>();
	auto a2Box = a2.GetComponent<BoxCollider2D>();
	if (a1Box != nullptr && a2Box != nullptr) {
		if (Intersect(*a1Box, *a2Box)) {
			AddHitData2D(a1, a2, *a1Box, *a2Box, Math::Vector2(0.0, 0.0));
			return true;
		}
		else {
			RemoveHitData2D(a1, a2, *a1Box, *a2Box);
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


bool Collision::Intersect(const BoxCollider2D& c1, const BoxCollider2D& c2) {
	if (!c1.enable || !c2.enable) return false;
	

	//頂点リスト
	Math::Vector2 verticesC1[] = {
		Math::Vector2(
			(-c1.width / 2.0f) * Math::Cos(c1.rotation) - (c1.height / 2.0f) * Math::Sin(c1.rotation) + c1.centerPosition.x,
			(-c1.width / 2.0f) * Math::Sin(c1.rotation) + (c1.height / 2.0f) * Math::Cos(c1.rotation) + c1.centerPosition.y
		),
		Math::Vector2(
			(c1.width / 2.0f) * Math::Cos(c1.rotation) - (c1.height / 2.0f) * Math::Sin(c1.rotation) + c1.centerPosition.x,
			(c1.width / 2.0f) * Math::Sin(c1.rotation) + (c1.height / 2.0f) * Math::Cos(c1.rotation) + c1.centerPosition.y
		),
		Math::Vector2(
			(c1.width / 2.0f) * Math::Cos(c1.rotation) - (-c1.height / 2.0f) * Math::Sin(c1.rotation) + c1.centerPosition.x,
			(c1.width / 2.0f) * Math::Sin(c1.rotation) + (-c1.height / 2.0f) * Math::Cos(c1.rotation) + c1.centerPosition.y
		),
		Math::Vector2(
			(-c1.width / 2.0f) * Math::Cos(c1.rotation) - (-c1.height / 2.0f) * Math::Sin(c1.rotation) + c1.centerPosition.x,
			(-c1.width / 2.0f) * Math::Sin(c1.rotation) + (-c1.height / 2.0f) * Math::Cos(c1.rotation) + c1.centerPosition.y
		),
	};


	Math::Vector2 verticesC2[] = {
		Math::Vector2(
			(-c2.width / 2.0f) * Math::Cos(c2.rotation) - (c2.height / 2.0f) * Math::Sin(c2.rotation) + c2.centerPosition.x,
			(-c2.width / 2.0f) * Math::Sin(c2.rotation) + (c2.height / 2.0f) * Math::Cos(c2.rotation) + c2.centerPosition.y
		),
		Math::Vector2(
			(c2.width / 2.0f) * Math::Cos(c2.rotation) - (c2.height / 2.0f) * Math::Sin(c2.rotation) + c2.centerPosition.x,
			(c2.width / 2.0f) * Math::Sin(c2.rotation) + (c2.height / 2.0f) * Math::Cos(c2.rotation) + c2.centerPosition.y
		),
		Math::Vector2(
			(c2.width / 2.0f) * Math::Cos(c2.rotation) - (-c2.height / 2.0f) * Math::Sin(c2.rotation) + c2.centerPosition.x,
			(c2.width / 2.0f) * Math::Sin(c2.rotation) + (-c2.height / 2.0f) * Math::Cos(c2.rotation) + c2.centerPosition.y
		),
		Math::Vector2(
			(-c2.width / 2.0f) * Math::Cos(c2.rotation) - (-c2.height / 2.0f) * Math::Sin(c2.rotation) + c2.centerPosition.x,
			(-c2.width / 2.0f) * Math::Sin(c2.rotation) + (-c2.height / 2.0f) * Math::Cos(c2.rotation) + c2.centerPosition.y
		),
	};


	//辺のベクトル
	Math::Vector2 vecsC1[] = {
		verticesC1[1] - verticesC1[0],
		verticesC1[2] - verticesC1[1],
		verticesC1[3] - verticesC1[2],
		verticesC1[0] - verticesC1[3],
	};

	Math::Vector2 vecsC2[] = {
		verticesC2[1] - verticesC2[0],
		verticesC2[2] - verticesC2[1],
		verticesC2[3] - verticesC2[2],
		verticesC2[0] - verticesC2[3],
	};

	//c1の一点がc2内にあるか確認
	for (int i = 0; i < 4; ++i) {
		auto r1 = vecsC2[0].Cross(verticesC1[i] - verticesC2[0]);
		auto r2 = vecsC2[1].Cross(verticesC1[i] - verticesC2[1]);
		auto r3 = vecsC2[2].Cross(verticesC1[i] - verticesC2[2]);
		auto r4 = vecsC2[3].Cross(verticesC1[i] - verticesC2[3]);

		if (r1 <= 0 && r2 <= 0 && r3 <= 0 && r4 <= 0) {
			return true;
		}
	}

	//c2の一点がc1内にあるか確認
	for (int i = 0; i < 4; ++i) {
		auto r1 = vecsC1[0].Cross(verticesC2[i] - verticesC1[0]);
		auto r2 = vecsC1[1].Cross(verticesC2[i] - verticesC1[1]);
		auto r3 = vecsC1[2].Cross(verticesC2[i] - verticesC1[2]);
		auto r4 = vecsC1[3].Cross(verticesC2[i] - verticesC1[3]);

		if (r1 <= 0 && r2 <= 0 && r3 <= 0 && r4 <= 0) {
			return true;
		}
	}

	//辺同士が8点で交差しているか確認
	int hitCount = 0;	//辺の交差回数
	if (Intersect(verticesC1[0], verticesC1[1], verticesC2[0], verticesC2[1])) ++hitCount;
	if (Intersect(verticesC1[0], verticesC1[1], verticesC2[1], verticesC2[2])) ++hitCount;
	if (Intersect(verticesC1[0], verticesC1[1], verticesC2[2], verticesC2[3])) ++hitCount;
	if (Intersect(verticesC1[0], verticesC1[1], verticesC2[3], verticesC2[0])) ++hitCount;

	if (Intersect(verticesC1[1], verticesC1[2], verticesC2[0], verticesC2[1])) ++hitCount;
	if (Intersect(verticesC1[1], verticesC1[2], verticesC2[1], verticesC2[2])) ++hitCount;
	if (Intersect(verticesC1[1], verticesC1[2], verticesC2[2], verticesC2[3])) ++hitCount;
	if (Intersect(verticesC1[1], verticesC1[2], verticesC2[3], verticesC2[0])) ++hitCount;
	
	if (Intersect(verticesC1[2], verticesC1[3], verticesC2[0], verticesC2[1])) ++hitCount;
	if (Intersect(verticesC1[2], verticesC1[3], verticesC2[1], verticesC2[2])) ++hitCount;
	if (Intersect(verticesC1[2], verticesC1[3], verticesC2[2], verticesC2[3])) ++hitCount;
	if (Intersect(verticesC1[2], verticesC1[3], verticesC2[3], verticesC2[0])) ++hitCount;
	
	if (Intersect(verticesC1[3], verticesC1[0], verticesC2[0], verticesC2[1])) ++hitCount;
	if (Intersect(verticesC1[3], verticesC1[0], verticesC2[1], verticesC2[2])) ++hitCount;
	if (Intersect(verticesC1[3], verticesC1[0], verticesC2[2], verticesC2[3])) ++hitCount;
	if (Intersect(verticesC1[3], verticesC1[0], verticesC2[3], verticesC2[0])) ++hitCount;

	if (hitCount == 8) return true;
	return false;
}


bool Collision::Intersect(const Math::Vector2& _a1, const Math::Vector2& _a2, const Math::Vector2& _b1, const Math::Vector2& _b2) {
	float p, q;
	p = (_a1.x - _a2.x) * (_b1.y - _a1.y) - (_a1.y - _a2.y) * (_b1.x - _a1.x);
	q = (_a1.x - _a2.x) * (_b2.y - _a1.y) - (_a1.y - _a2.y) * (_b2.x - _a1.x);
	if (p * q > 0) return false;

	p = (_b1.x - _b2.x) * (_a1.y - _b1.y) - (_b1.y - _b2.y) * (_a1.x - _b1.x);
	q = (_b1.x - _b2.x) * (_a2.y - _b1.y) - (_b1.y - _b2.y) * (_a2.x - _b1.x);
	if (p * q > 0) return false;
	return true;
}


void AddHitData2D(Actor& a1, Actor& a2, Collider2D& c1, Collider2D& c2, Math::Vector2 hitPos) {
	//既に追加されているか確認
	auto it = c1.hitData.begin();
	for (; it != c1.hitData.end(); ++it) {
		if ((*it).actor == &a2) break;
	}
	//存在していなければ追加
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