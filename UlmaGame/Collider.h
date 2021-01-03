#pragma once
#include "Component.h"
#include "Vector.h"

namespace Game {
	namespace Core {
		class Actor;

		class Collider2D : public Component{
		public:
			Collider2D(Actor& owner);
			virtual ~Collider2D();

			bool enable;	//è’ìÀîªíËÇ™óLå¯Ç©ÅH
			bool isTrigger;	//TriggerÇ©ÅH
			bool isHit;
		};

		class CircleCollider : public Collider2D {
		public:
			CircleCollider(Actor& owner);
			CircleCollider(Actor& owner, Math::Vector3& centerPos, float _radius);
			~CircleCollider();

			Math::Vector3 centerPosition;
			float radius;
		};

		class BoxCollider2D : public Collider2D {
			BoxCollider2D(Actor& owner);
			BoxCollider2D(Actor& owner, Math::Vector3& centerPos, float _width, float _height, float _rotation);

			~BoxCollider2D();

			Math::Vector3 centerPosition;
			float width;
			float height;
			float rotation;
		};
	}
}