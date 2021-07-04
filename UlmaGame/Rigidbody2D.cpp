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
	if(m_enableGravity) {
		m_acceleration.y -= m_gravityScale;
	}
	m_velocity += m_acceleration;
	m_owner->GetTransform().position += Math::Vector3(m_velocity) * deltaTime;

	
	//次のフレームのx座標を計算し、衝突するか確認
	auto currentVel = m_velocity;
	auto currentPos = m_owner->GetTransform().position;

	m_velocity.x += m_acceleration.x;
	m_owner->GetTransform().position.x += m_velocity.x * deltaTime;

	auto col = m_owner->GetComponent<Collider2D>();
	if(col != nullptr) {
		if(col->GetIsHit()) {
			m_acceleration.x = 0.0f;
			m_velocity.x = 0.0f;
			Debug::Log("hit x");
		}
	} else {
		m_velocity.x = currentVel.x;
	}

	m_owner->GetTransform().position = currentPos;


	//次のフレームのy座標を計算し、衝突するか確認
	auto currentAcc = m_acceleration;
	currentVel = m_velocity;
	currentPos = m_owner->GetTransform().position;

	if(m_enableGravity) {
		m_acceleration.y -= m_gravityScale;
	}
	m_velocity.y += m_acceleration.y;
	m_owner->GetTransform().position.y += m_velocity.y * deltaTime;
	
	//衝突を確認
	col = m_owner->GetComponent<Collider2D>();
	if(col != nullptr) {
		if(col->GetIsHit()) {
			m_acceleration.y = 0.0f;
			m_velocity.y = 0.0f;
		}
	} else {
		m_acceleration.y = currentAcc.y;
		m_velocity.y = currentVel.y;
	}

	m_owner->GetTransform().position = currentPos;
}


Rigidbody2D::~Rigidbody2D() {

}