#include "Player.h"
#include "Bullet.h"

using namespace UlmaEngine::InputSystem;

SampleGame::Player::Player(SceneManagement::Scene& scene)
	: Actor::Actor(scene)
	, m_inputManager(ServiceLocator::Resolve<InputSystem::IInputManager>())
 {
	new BoxCollider2D(*this, Math::Vector3::zero, 120.0, 120.0, 0.0);
	//new Rigidbody2D(*this);
	
	auto animator = new Animator(*this);
	auto animation = new Animation(*this, "run", 0.1f);
	SpriteComponent* sprites[10];
	for(int i=1; i <= 10; ++i) {
		auto name = "run" + std::to_string(i);
		sprites[i-1] = new SpriteComponent(*this, name.c_str(), ESpriteType::Rectangle, 90);
	}
	animation->RegisterSprite(sprites);
	animator->RegisterAnimation(*animation);
	animator->SetAnimation("run");
	
	GetTransform().position = Math::Vector3(-300.0f, 100.0f, 0.0f);
	GetTransform().scale = Math::Vector3(1.0f/3.0f, 1.0f/3.0f, 1.0f/3.0f);
	GetTransform().rotation.z = 0.0f;
	this->name = "Player";
}


SampleGame::Player::~Player() {
}


void SampleGame::Player::Initialize() {
}


void SampleGame::Player::UpdateActor(float deltaTime) {
	GetTransform().position += m_inputManager->GetAxis(EAxisType::Vertical) * GetTransform().GetUp()
		+ m_inputManager->GetAxis(EAxisType::Horizontal) * GetTransform().GetRight();
	
	auto col = this->GetComponent<Collider2D>();
	auto currPos = this->GetTransform().position;
	this->GetTransform().position.y -= 800.0f * deltaTime;
	if(col != nullptr) {
		if(col->GetIsHit()) {
			this->GetTransform().position.y = currPos.y;
		}
	}
}
