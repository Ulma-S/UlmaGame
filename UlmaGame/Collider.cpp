#include "Collider.h"

using namespace Game::Core;

Collider2D::Collider2D(Actor& owner)
	: Component(owner)
	, enable(true)
	, isTrigger(false)
	, isHit(false)
{ }


Collider2D::~Collider2D() {

}


CircleCollider::CircleCollider(Actor& owner)
	: Collider2D(owner)
	, centerPosition(Math::Vector3::zero)
	, radius(100.0f)
{}


CircleCollider::CircleCollider(Actor& owner, Math::Vector3 centerPos, float _radius)
	: Collider2D(owner)
	, centerPosition(centerPos)
	, radius(_radius)
{}


CircleCollider::~CircleCollider(){}


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