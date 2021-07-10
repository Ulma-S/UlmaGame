#include "Rigidbody2D.h"
#include "Actor.h"
#include "Collider.h"
#include "Debug.h"

using namespace UlmaEngine;

Rigidbody2D::Rigidbody2D(Actor& owner)
	: Component(owner)
	, m_velocity(Math::Vector2::zero)
	, m_acceleration(Math::Vector2::zero)
	, m_gravityScale(0.1f)
	, m_enableGravity(true)
{}


Rigidbody2D::Rigidbody2D(Actor& owner, float gravityScale = 0.05f)
	: Component(owner)
	, m_velocity(Math::Vector2::zero)
	, m_acceleration(Math::Vector2::zero)
	, m_gravityScale(gravityScale)
	, m_enableGravity(true)
{}


void Rigidbody2D::Update(float deltaTime) {
	auto currAcc = m_acceleration;
	auto currVel = m_velocity;
	auto currPos = m_owner->GetTransform().position;

	m_velocity.x += m_acceleration.x;
	m_owner->GetTransform().position.x += m_velocity.x * deltaTime;

	auto col = m_owner->GetComponent<Collider2D>();
	if(col != nullptr) {
		if(col->IsHit()) {
			m_acceleration.x = 0.0f;
			m_velocity.x = 0.0f;
			m_owner->GetTransform().position.x = currPos.x;
		}
	}else {
		m_acceleration.x = currAcc.x;
		m_velocity.x = currVel.x;
	}

	
	if (m_enableGravity) {
		m_acceleration.y -= m_gravityScale;
	}
	m_velocity.y += m_acceleration.y;
	m_owner->GetTransform().position.y += m_velocity.y * deltaTime;

	if(col != nullptr) {
		if(col->IsHit()) {
			m_acceleration.y = 0.0f;
			m_velocity.y = 0.0f;
			m_owner->GetTransform().position.y = currPos.y;
		}
	}else {
		m_acceleration.y = currAcc.y;
		m_velocity.y = currVel.y;
	}
}


Rigidbody2D::~Rigidbody2D() {

}
