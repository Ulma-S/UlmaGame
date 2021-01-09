#pragma once
#include <vector>
#include "Component.h"
#include "Vector.h"

namespace UlmaEngine {
	class Actor;

	struct HitData2D {
		Actor* actor;	//衝突したActor
		Math::Vector2 hitPosition;

		HitData2D(Actor& actor);
		HitData2D(Actor& actor, Math::Vector2 _hitPos);
	};

	class Collider2D : public Component {
	public:
		virtual ~Collider2D();

		bool enable;	//衝突判定が有効か？
		bool isTrigger;	//Triggerか？
		bool isHit;
		std::vector<HitData2D> hitData;

	protected:
		Collider2D(Actor& owner);
	};

	class CircleCollider : public Collider2D {
	public:
		CircleCollider(Actor& owner);
		CircleCollider(Actor& owner, Math::Vector3 centerPos, float _radius);
		~CircleCollider();

		virtual void Update(float deltaTime) override;

		Math::Vector3 centerPosition;
		float radius;
	};

	class BoxCollider2D : public Collider2D {
		BoxCollider2D(Actor& owner);
		BoxCollider2D(Actor& owner, Math::Vector3 centerPos, float _width, float _height, float _rotation);

		~BoxCollider2D();

		Math::Vector3 centerPosition;
		float width;
		float height;
		float rotation;
	};
}