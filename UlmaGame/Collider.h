#pragma once
#include <vector>
#include "Component.h"
#include "Vector.h"

namespace UlmaEngine {
	class Actor;

	struct HitData2D {
		Actor* actor;	//è’ìÀÇµÇΩActor
		Math::Vector2 hitPosition;

		HitData2D(Actor& actor);
		HitData2D(Actor& actor, Math::Vector2 _hitPos);
	};

	class Collider2D : public Component {
	public:
		Collider2D(Actor& _owner);
		virtual ~Collider2D();

		bool isTrigger;	//TriggerÇ©ÅH
		std::vector<HitData2D> hitData;

		void Update(float _deltaTime) override;

		inline bool GetIsHit() const { return m_isHit; }

	protected:
		bool m_isHit;
	};

	class CircleCollider : public Collider2D {
	public:
		CircleCollider(Actor& _owner);
		CircleCollider(Actor& _owner, const Math::Vector3& _centerPos, float _radius);
		~CircleCollider();

		virtual void Update(float _deltaTime) override;

		Math::Vector3 centerPosition;
		float radius;
	};

	class BoxCollider2D : public Collider2D {
		BoxCollider2D(Actor& _owner);
		BoxCollider2D(Actor& _owner, Math::Vector3 _centerPos, float _width, float _height, float _rotation);

		~BoxCollider2D();

		Math::Vector3 centerPosition;
		float width;
		float height;
		float rotation;
	};
}