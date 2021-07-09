#pragma once
#include <vector>
#include "Component.h"
#include "Vector.h"

namespace UlmaEngine {
	class Actor;

	/*------------------------------*/
	// 2Dの衝突情報を格納する構造体 //
	/*------------------------------*/
	struct HitData2D {
		Actor* actor;	//衝突したActor
		Math::Vector2 hitPosition;

		HitData2D(Actor& actor);
		HitData2D(Actor& actor, Math::Vector2 hitPos);
	};

	// 2Dコライダーの基底クラス
	class Collider2D : public Component {
	public:
		Collider2D(Actor& _owner);
		virtual ~Collider2D();

		bool isTrigger;	//Triggerか？
		std::vector<HitData2D> hitData;

		void Update(float deltaTime) override;

		inline bool IsHit() const { return m_isHit; }

		bool IsHit(const std::string& name) const;

	protected:
		bool m_isHit;
	};

	// 円形のコライダー
	class CircleCollider : public Collider2D {
	public:
		CircleCollider(Actor& _owner);
		CircleCollider(Actor& _owner, const Math::Vector3& centerPos, float radius);
		~CircleCollider();

		virtual void Update(float deltaTime) override;

		Math::Vector3 centerPosition;
		float radius;
	};

	// 矩形のコライダー
	class BoxCollider2D : public Collider2D {
	public:
		BoxCollider2D(Actor& _owner);
		BoxCollider2D(Actor& _owner, Math::Vector3 _centerPos = Math::Vector3::zero, float width = 100.0, float height = 100.0, float rotation = 0.0);
		~BoxCollider2D();

		virtual void Update(float deltaTime) override;

		Math::Vector3 centerPosition;
		float width;
		float height;
		float rotation;
	};
}