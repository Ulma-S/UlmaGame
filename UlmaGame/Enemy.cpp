#include "Enemy.h"

SampleGame::Enemy::Enemy(SceneManagement::Scene& scene)
	: Actor::Actor(scene)
{
	new BoxCollider2D(*this, Math::Vector3::zero, 80.0, 120.0, 0.0);

	//Animationèâä˙âª
	auto animator = new Animator(*this);

	auto downAnimation = new Animation(*this, *animator, "down", 0.1f);
	std::vector<SpriteComponent*> downSprites;
	for (int i = 1; i <= 5; ++i) {
		auto name = "sara_down" + std::to_string(i);
		downSprites.emplace_back(new SpriteComponent(*this, name.c_str(), ESpriteType::Rectangle, 90));
	}
	downAnimation->RegisterSprite(downSprites);
	animator->RegisterAnimation(*downAnimation);

	downSprites.clear();
	downSprites.shrink_to_fit();

	auto hangAnimation = new Animation(*this, *animator, "hang", 0.1f);
	std::vector<SpriteComponent*> hangSprites;
	for (int i = 1; i <= 5; ++i) {
		auto name = "sara_hang" + std::to_string(i);
		hangSprites.emplace_back(new SpriteComponent(*this, name.c_str(), ESpriteType::Rectangle, 90));
	}
	hangAnimation->RegisterSprite(hangSprites);
	animator->RegisterAnimation(*hangAnimation);

	hangSprites.clear();
	hangSprites.shrink_to_fit();
	
	auto idleAnimation = new Animation(*this, *animator, "idle", 0.1f);
	std::vector<SpriteComponent*> idleSprites;
	for (int i = 1; i <= 6; ++i) {
		auto name = "sara_idle" + std::to_string(i);
		idleSprites.emplace_back(new SpriteComponent(*this, name.c_str(), ESpriteType::Rectangle, 90));
	}
	idleAnimation->RegisterSprite(idleSprites);
	animator->RegisterAnimation(*idleAnimation);

	idleSprites.clear();
	idleSprites.shrink_to_fit();

	auto orderAnimation = new Animation(*this, *animator, "order", 0.1f);
	std::vector<SpriteComponent*> orderSprites;
	for (int i = 1; i <= 6; ++i) {
		auto name = "sara_order" + std::to_string(i);
		orderSprites.emplace_back(new SpriteComponent(*this, name.c_str(), ESpriteType::Rectangle, 90));
	}
	orderAnimation->RegisterSprite(orderSprites);
	animator->RegisterAnimation(*orderAnimation);

	orderSprites.clear();
	orderSprites.shrink_to_fit();

	animator->SetAnimation("idle");
	
	GetTransform().position = Math::Vector3(300.0, -190.0, 0.0);
	GetTransform().scale = Math::Vector3(1.f/1.9f, 1.f/1.9f, 1.f/2.f);
	name = "Enemy";
}


SampleGame::Enemy::~Enemy(){}


void SampleGame::Enemy::Initialize(){}


void SampleGame::Enemy::UpdateActor(float deltaTime) {
}
