#include "Player.h"
#include "Bullet.h"

using namespace UlmaEngine::InputSystem;

SampleGame::Player::Player(SceneManagement::Scene& scene)
	: Actor::Actor(scene)
	, m_moveSpeed(150.0f)
	, m_bulletCount(0) {
	new SpriteComponent(*this, Circle, 90);
	new CircleCollider(*this, Math::Vector3(), 150.0f);
	GetTransform().position = Math::Vector3(300.0, 100.0, 0.0);
	GetTransform().scale = Math::Vector3(1.0f, 0.75f, 1.0f);
	this->name = "Player";
}


SampleGame::Player::~Player() {
}


void SampleGame::Player::Initialize() {
	auto ts = this->GetTransform();
	for (int i = 0; i < 10; ++i) {
		m_bullets.emplace_back(new Bullet(this->GetScene(), ts.position, ts.GetUpVec()));
		m_bullets[i]->SetMoveSpeed(500.0f);
	}
}


void SampleGame::Player::UpdateActor(float _deltaTime) {
	GetTransform().rotation.z -= InputManagerOpenGL::GetInstance().GetAxis(EAxisType::Horizontal) * m_moveSpeed * _deltaTime;
	GetTransform().position += InputManagerOpenGL::GetInstance().GetAxis(EAxisType::Vertical) * GetTransform().GetUpVec() * m_moveSpeed * _deltaTime;

	if (InputManagerOpenGL::GetInstance().GetKeyDown(EKeyCode::Space)) {
		m_bullets[m_bulletCount]->Initialize(this->GetTransform().position, this->GetTransform().GetUpVec());
		m_bullets[m_bulletCount]->Activate();
		m_bulletCount++;
		if (m_bulletCount >= m_bullets.size()) {
			m_bulletCount = 0;
		}
	}

	for (int i = 0; i < m_bullets.size(); ++i) {
		auto col = m_bullets[i]->GetComponent<Collider2D>();
		if (col->hitData.size() >= 1) {
			for (int j = 0; j < col->hitData.size(); ++j) {
				auto name = m_bullets[i]->GetComponent<Collider2D>()->hitData[j].actor->GetName();
				if (name != "Bullet" && name != "Player") {
					Debug::Log(name);
					m_bullets[i]->state =  EActorState::Inactive;
					m_bullets[i]->GetComponent<Collider2D>()->hitData[j].actor->state = EActorState::Inactive;
				}
			}
		}
	}
}
