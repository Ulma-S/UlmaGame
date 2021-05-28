#include "Player.h"
#include "Bullet.h"

using namespace UlmaEngine::InputSystem;

SampleGame::Player::Player(SceneManagement::Scene& scene)
	: Actor::Actor(scene)
	, m_moveSpeed(150.0f)
	, m_bulletCount(0) {
	new SpriteComponent(*this, "blue", ESpriteType::Rectangle, 90);
	new BoxCollider2D(*this, Math::Vector3::zero, 300.0, 300.0, 0.0);
	GetTransform().position = Math::Vector3(300.0, 100.0, 0.0);
	GetTransform().scale = Math::Vector3(1.0f, 1.0f, 1.0f);
	GetTransform().rotation.z = 0.0f;
	this->name = "Player";
}


SampleGame::Player::~Player() {
}


void SampleGame::Player::Initialize() {
}


void SampleGame::Player::UpdateActor(float _deltaTime) {
	GetTransform().rotation.z -= InputManagerOpenGL::GetInstance().GetAxis(EAxisType::Horizontal) * m_moveSpeed * _deltaTime;
	GetTransform().position += InputManagerOpenGL::GetInstance().GetAxis(EAxisType::Vertical) * GetTransform().GetUp() * m_moveSpeed * _deltaTime;
	//GetTransform().position += InputManagerOpenGL::GetInstance().GetAxis(EAxisType::Vertical) * GetTransform().GetUp()
	//	+ InputManagerOpenGL::GetInstance().GetAxis(EAxisType::Horizontal) * GetTransform().GetRight();

	//if (InputManagerOpenGL::GetInstance().GetKeyDown(EKeyCode::Space)) {
	//	m_bullets[m_bulletCount]->Initialize(this->GetTransform().position, this->GetTransform().GetUp());
	//	m_bullets[m_bulletCount]->state = EActorState::Active;
	//	m_bulletCount++;
	//	if (m_bulletCount >= m_bullets.size()) {
	//		m_bulletCount = 0;
	//	}
	//}

	//for (int i = 0; i < m_bullets.size(); ++i) {
	//	auto col = m_bullets[i]->GetComponent<Collider2D>();
	//	if (col->hitData.size() >= 1) {
	//		for (int j = 0; j < col->hitData.size(); ++j) {
	//			auto name = m_bullets[i]->GetComponent<Collider2D>()->hitData[j].actor->GetName();
	//			if (name != "Bullet" && name != "Player") {
	//				Debug::Log(name);
	//				
	//				m_bullets[i]->GetComponent<Collider2D>()->hitData[j].actor->state = EActorState::Inactive;	//Enemy‚ð”ñactive‚É
	//				m_bullets[i]->state = EActorState::Inactive;
	//			}
	//		}
	//	}
	//}
	
	auto col = this->GetComponent<Collider2D>();
	if(col != nullptr){
		if (col->GetIsHit()) {
			Debug::Log(col->hitData[0].actor->GetName());
		}
		else {
			Debug::Log("NotHit");
		}
	}
}
