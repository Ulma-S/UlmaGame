#include "Player.h"
#include "Bullet.h"

using namespace UlmaEngine::InputSystem;

SampleGame::Player::Player(SceneManagement::Scene& scene)
	: Actor::Actor(scene)
	, m_moveSpeed(150.0f)
	, m_bulletCount(0) {
	new SpriteComponent(*this, "blue", ESpriteType::Rectangle, 90);
	new BoxCollider2D(*this, Math::Vector3::zero, 100.0, 100.0, 0.0);
	new Rigidbody2D(*this);
	
	GetTransform().position = Math::Vector3(-300.0f, -100.0f, 0.0f);
	GetTransform().scale = Math::Vector3(1.0f/3.0f, 1.0f/3.0f, 1.0f/3.0f);
	GetTransform().rotation.z = 0.0f;
	this->name = "Player";
}


SampleGame::Player::~Player() {
}


void SampleGame::Player::Initialize() {
	this->GetComponent<Rigidbody2D>()->SetVelocity(Math::Vector2(1.0f, 0.0f));
}


void SampleGame::Player::UpdateActor(float _deltaTime) {
	//GetTransform().rotation.z -= InputManagerOpenGL::GetInstance().GetAxis(EAxisType::Horizontal) * m_moveSpeed * _deltaTime;
	//GetTransform().position += InputManagerOpenGL::GetInstance().GetAxis(EAxisType::Vertical) * GetTransform().GetUp() * m_moveSpeed * _deltaTime;
	GetTransform().position += InputManagerOpenGL::GetInstance().GetAxis(EAxisType::Vertical) * GetTransform().GetUp()
		+ InputManagerOpenGL::GetInstance().GetAxis(EAxisType::Horizontal) * GetTransform().GetRight();

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
			for (auto element : col->hitData) {
				//Debug::Log(element.actor->GetName());
			}
		}
		else {
			//Debug::Log("NotHit");
		}
	}

	if(InputManagerOpenGL::GetInstance().GetKeyDown(EKeyCode::Space)) {
		this->GetComponent<Rigidbody2D>()->SetAcceleration(Math::Vector2(0.0f, 1.0f));
	}

	//Debug::Log(this->GetComponent<Rigidbody2D>()->GetVelocity());
}
