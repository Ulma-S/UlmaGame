#include "Bullet.h"

using namespace UlmaEngine;
using namespace SampleGame;

Bullet::Bullet(UlmaEngine::SceneManagement::Scene& _scene)
	: Actor(_scene)
	, m_moveDir(Math::Vector3(1.0f, 0.0f, 0.0f))
	, m_moveSpeed(100.0f)
{
	new SpriteComponent(*this, Circle, 100);
	new CircleCollider(*this, Math::Vector3(0.0f, 0.0f, 0.0f), 15.0f);
	GetTransform().position = Math::Vector3(0.0f, 0.0f, 0.0f);
	GetTransform().scale = Math::Vector3(0.1f, 0.075f, 1.0f);
	this->name = "Bullet";
}


Bullet::Bullet(UlmaEngine::SceneManagement::Scene& _scene, const Math::Vector3& _position, const Math::Vector3& _moveDir) 
	: Actor(_scene)
	, m_moveDir(_moveDir)
	, m_moveSpeed(300.0f)
{
	new SpriteComponent(*this, Circle, 80);
	new CircleCollider(*this, _position, 15.0f);
	GetTransform().position = _position;
	GetTransform().scale = Math::Vector3(0.1f, 0.075f, 1.0f);
	this->name = "Bullet";
}


Bullet::~Bullet() {

}


void Bullet::Initialize() {
	Debug::Log("start");
	state = EActorState::Inactive;
}


void Bullet::UpdateActor(float _deltaTime) {
	GetTransform().position += m_moveDir * m_moveSpeed * _deltaTime;
}


void Bullet::Initialize(const Math::Vector3& _position, const Math::Vector3& _moveDir) {
	this->GetTransform().position = _position;
	this->m_moveDir = _moveDir;
}
