#include <cmath>
#include "Player.h"
#include "Bullet.h"

using namespace UlmaEngine::InputSystem;

SampleGame::Player::Player(SceneManagement::Scene& scene)
	: Actor::Actor(scene)
	, m_inputManager(ServiceLocator::Resolve<InputSystem::IInputProvider>())
{
	new BoxCollider2D(*this, Math::Vector3::zero, 80.0, 120.0, 0.0);
	new Rigidbody2D(*this);

	//Animation初期化
	auto animator = new Animator(*this);

	auto idleAnimation = new Animation(*this, *animator, "idle", 0.1f);
	std::vector<SpriteComponent*> idleSprites;
	for (int i = 1; i <= 5; ++i) {
		auto name = "yu_idle" + std::to_string(i);
		idleSprites.emplace_back(new SpriteComponent(*this, name.c_str(), ESpriteType::Rectangle, 90));
	}
	idleAnimation->RegisterSprite(idleSprites);
	animator->RegisterAnimation(*idleAnimation);

	idleSprites.clear();
	idleSprites.shrink_to_fit();

	auto runAnimation = new Animation(*this, *animator, "run", 0.1f);
	std::vector<SpriteComponent*> runSprites;
	for (int i = 1; i <= 10; ++i) {
		auto name = "yu_run" + std::to_string(i);
		runSprites.emplace_back(new SpriteComponent(*this, name.c_str(), ESpriteType::Rectangle, 90));
	}
	runAnimation->RegisterSprite(runSprites);
	animator->RegisterAnimation(*runAnimation);

	runSprites.clear();
	runSprites.shrink_to_fit();

	auto weakAttackAnimation = new Animation(*this, *animator, "weakAttack", 0.1f);
	std::vector<SpriteComponent*> weakAttackSprites;
	for (int i = 1; i <= 10; ++i) {
		auto name = "yu_weakAttack" + std::to_string(i);
		weakAttackSprites.emplace_back(new SpriteComponent(*this, name.c_str(), ESpriteType::Rectangle, 90));
	}
	weakAttackAnimation->RegisterSprite(weakAttackSprites);
	animator->RegisterAnimation(*weakAttackAnimation);

	runSprites.clear();
	runSprites.shrink_to_fit();
	
	animator->SetAnimation("idle");

	GetTransform().position = Math::Vector3(-300.0f, 100.0f, 0.0f);
	GetTransform().scale = Math::Vector3(1.0f / 3.0f, 1.0f / 3.0f, 1.0f / 3.0f);
	GetTransform().rotation.z = 0.0f;
	this->name = "Player";
}


SampleGame::Player::~Player() {
}


void SampleGame::Player::Initialize() {
}


void SampleGame::Player::UpdateActor(float deltaTime) {
	//移動
	GetTransform().position += m_inputManager->GetAxis(EAxisType::Vertical) * GetTransform().GetUp() * deltaTime
		+ m_inputManager->GetAxis(EAxisType::Horizontal) * GetTransform().GetRight() * deltaTime * 120.0f;

	//重力
	auto col = this->GetComponent<Collider2D>();
	auto currPos = this->GetTransform().position;
	//this->GetTransform().position.y -= 800.0f * deltaTime;
	if (col != nullptr) {
		if (col->IsHit()) {
			for (const auto& hit : col->hitData) {
				//Debug::Log(hit.actor->GetName());
			}
			this->GetTransform().position.y = currPos.y;
		}
	}

	if(m_inputManager->GetKeyDown(EKeyCode::W)) {
		Debug::Log("jump");
		GetComponent<Rigidbody2D>()->AddAccelerationY(10.f);
	}

	if(m_inputManager->GetKeyDown(EKeyCode::W)) {
		Debug::Log("W");
	}

	//Spriteの向き
	if (GetTransform().scale.x > 0) {
		if (m_inputManager->GetKey(EKeyCode::A)) {
			GetTransform().scale.x = -std::abs(GetTransform().scale.x);
		}
	}
	else if (GetTransform().scale.x < 0) {
		if (m_inputManager->GetKey(EKeyCode::D)) {
			GetTransform().scale.x = std::abs(GetTransform().scale.x);
		}
	}

	//アニメーション再生
	if (m_inputManager->GetKeyDown(EKeyCode::F)) {
		this->GetComponent<Animator>()->SetAnimation("weakAttack");
	}
	else {
		if (GetComponent<Animator>()->GetCurrentAnimationName() == "weakAttack") {
			if (GetComponent<Animator>()->IsEnd()) {
				if (m_inputManager->GetKey(EKeyCode::A) || m_inputManager->GetKey(EKeyCode::D)) {
					this->GetComponent<Animator>()->SetAnimation("run");

				}
				else {
					this->GetComponent<Animator>()->SetAnimation("idle");
				}
			}
		}
		else {
			if (m_inputManager->GetKey(EKeyCode::A) || m_inputManager->GetKey(EKeyCode::D)) {
				this->GetComponent<Animator>()->SetAnimation("run");
			}
			else {
				this->GetComponent<Animator>()->SetAnimation("idle");	
			}
		}
	}

	Debug::Log(GetComponent<Animator>()->IsEnd());

	//シーン遷移
	if (this->GetComponent<Collider2D>()->IsHit("wall")) {
		SceneManagement::SceneManager::GetInstance().LoadScene("gameOver");
	}

	if (m_inputManager->GetKeyDown(EKeyCode::Q)) {
		SceneManagement::SceneManager::GetInstance().LoadScene("gameClear");
	}
}
