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
		static bool Intersect(const CircleCollider& c1, const CircleCollider& c2);	//�~���m�̔���
		static bool Intersect(const BoxCollider2D& c1, const BoxCollider2D& c2);	//��`���m�̔���
		static bool Intersect(const Math::Vector2& _a1, const Math::Vector2& _a2, const Math::Vector2& _b1, const Math::Vector2& _b2);	//�������m�̔���
		static bool Intersect(const CircleCollider& c1, const BoxCollider2D& c2);	//�~�Ƌ�`�̔���
	};
}