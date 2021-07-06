#include "Player.h"
#include "Bullet.h"

using namespace UlmaEngine::InputSystem;

SampleGame::Player::Player(SceneManagement::Scene& scene)
	: Actor::Actor(scene)
	, m_inputManager(ServiceLocator::Resolve<InputSystem::IInputManager>())
 {
	new BoxCollider2D(*this, Math::Vector3::zero, 120.0, 120.0, 0.0);
	//new Rigidbody2D(*this);

	//Animationèâä˙âª
	auto animator = new Animator(*this);
	
	auto idleAnimation = new Animation(*this, *animator, "idle", 0.1f);
	std::vector<SpriteComponent*> idleSprites;
	for(int i=1; i <= 5; ++i) {
		auto name = "idle" + std::to_string(i);
		idleSprites.emplace_back(new SpriteComponent(*this, name.c_str(), ESpriteType::Rectangle, 90));
	}
	idleAnimation->RegisterSprite(idleSprites);
	animator->RegisterAnimation(*idleAnimation);

	
	auto runAnimation = new Animation(*this, *animator, "run", 0.1f);
	std::vector<SpriteComponent*> runSprites;
	for(int i=1; i <= 10; ++i) {
		auto name = "run" + std::to_string(i);
		runSprites.emplace_back(new SpriteComponent(*this, name.c_str(), ESpriteType::Rectangle, 90));
	}
	runAnimation->RegisterSprite(runSprites);
	animator->RegisterAnimation(*runAnimation);
	
	animator->SetAnimation("idle");
	
	
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

	if(m_inputManager->GetKeyDown(EKeyCode::Space)) {
		this->GetComponent<Animator>()->SetAnimation("run");
	}
}
