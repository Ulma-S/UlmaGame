#include "Collider.h"
#include "Actor.h"
#include "Debug.h"

using namespace UlmaEngine;

Collider2D::Collider2D(Actor& owner)
	: Component(owner)
	, isTrigger(false)
	, m_isHit(false)
{ }


Collider2D::~Collider2D() {

}


void Collider2D::Update(float deltaTime) {
	if (!enable) return;
	if (!hitData.empty()) {
		m_isHit = true;
	}
	else {
		m_isHit = false;
	}
	if(m_owner->GetName() == "Player") {
	}
}


HitData2D::HitData2D(Actor& actor)
	: actor(&actor)
	, hitPosition(Math::Vector2(0.0f, 0.0f)) {
}


HitData2D::HitData2D(Actor& actor, Math::Vector2 hitPos) 
	: actor(&actor)
	, hitPosition(hitPos)
{}


CircleCollider::CircleCollider(Actor& owner)
	: Collider2D(owner)
	, centerPosition(Math::Vector3::zero)
	, radius(100.0f)
{}


CircleCollider::CircleCollider(Actor& owner, const Math::Vector3& centerPos, float radius)
	: Collider2D(owner)
	, centerPosition(centerPos)
	, radius(radius)
{}


CircleCollider::~CircleCollider(){}


void CircleCollider::Update(float deltaTime) {
	Collider2D::Update(deltaTime);
	centerPosition = m_owner->GetTransform().position;
}


BoxCollider2D::BoxCollider2D(Actor& owner)
	: Collider2D(owner)
	, centerPosition(Math::Vector3::zero)
	, width(100.0f)
	, height(100.0f)
	, rotation(0.0f)
{ }


BoxCollider2D::BoxCollider2D(Actor& owner, Math::Vector3 centerPos, float width, float height, float rotation)
	: Collider2D(owner)
	, centerPosition(centerPos)
	, width(width)
	, height(height)
	, rotation(rotation)
{ }


BoxCollider2D::~BoxCollider2D(){}


void BoxCollider2D::Update(float deltaTime) {
	Collider2D::Update(deltaTime);
	centerPosition = m_owner->GetTransform().position;
	this->rotation = m_owner->GetTransform().rotation.z;
}