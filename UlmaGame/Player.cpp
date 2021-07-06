#include "Player.h"
#include "Bullet.h"

using namespace UlmaEngine::InputSystem;

SampleGame::Player::Player(SceneManagement::Scene& scene)
	: Actor::Actor(scene)
	, m_inputManager(ServiceLocator::Resolve<InputSystem::IInputManager>())
 {
	new SpriteComponent(*this, "blue", ESpriteType::Rectangle, 90);
	new BoxCollider2D(*this, Math::Vector3::zero, 100.0, 100.0, 0.0);
	new Rigidbody2D(*this);
	
	GetTransform().position = Math::Vector3(-300.0f, 500.0f, 0.0f);
	GetTransform().scale = Math::Vector3(1.0f/3.0f, 1.0f/3.0f, 1.0f/3.0f);
	GetTransform().rotation.z = 0.0f;
	this->name = "Player";
}


SampleGame::Player::~Player() {
}


void SampleGame::Player::Initialize() {
	this->GetComponent<Rigidbody2D>()->SetVelocityX(50.0f);
}


void SampleGame::Player::UpdateActor(float deltaTime) {
	this->GetComponent<Rigidbody2D>()->SetVelocityX(50.0f);

	GetTransform().position += m_inputManager->GetAxis(EAxisType::Vertical) * GetTransform().GetUp()
		+ m_inputManager->GetAxis(EAxisType::Horizontal) * GetTransform().GetRight();
	
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
}
