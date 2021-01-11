#include "Collider.h"
#include "Actor.h"

using namespace UlmaEngine;

Collider2D::Collider2D(Actor& owner)
	: Component(owner)
	, isTrigger(false)
	, m_isHit(false)
{ }


Collider2D::~Collider2D() {

}


void Collider2D::Update(float _deltaTime) {
	if (!enable) return;
	if (hitData.size() >= 1) {
		m_isHit = true;
	}
	else {
		m_isHit = false;
	}
}


HitData2D::HitData2D(Actor& _actor)
	: actor(&_actor)
	, hitPosition(Math::Vector2(0.0f, 0.0f)) {
}


HitData2D::HitData2D(Actor& _actor, Math::Vector2 _hitPos) 
	: actor(&_actor)
	, hitPosition(_hitPos)
{}


CircleCollider::CircleCollider(Actor& owner)
	: Collider2D(owner)
	, centerPosition(Math::Vector3::zero)
	, radius(100.0f)
{}


CircleCollider::CircleCollider(Actor& owner, const Math::Vector3& _centerPos, float _radius)
	: Collider2D(owner)
	, centerPosition(_centerPos)
	, radius(_radius)
{}


CircleCollider::~CircleCollider(){}


void CircleCollider::Update(float _deltaTime) {
	Collider2D::Update(_deltaTime);
	centerPosition = m_owner->GetTransform().position;
}


BoxCollider2D::BoxCollider2D(Actor& owner)
	: Collider2D(owner)
	, centerPosition(Math::Vector3::zero)
	, width(100.0f)
	, height(100.0f)
	, rotation(0.0f)
{ }


BoxCollider2D::BoxCollider2D(Actor& owner, Math::Vector3 centerPos, float _width, float _height, float _rotation)
	: Collider2D(owner)
	, centerPosition(centerPos)
	, width(_width)
	, height(_height)
	, rotation(_rotation)
{ }


BoxCollider2D::~BoxCollider2D(){}