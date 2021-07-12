#include "Shooter.h"

using namespace SampleGame;

Shooter::Shooter(SceneManagement::Scene& scene)
	: Actor(scene)
{
	new BoxCollider2D(*this, Math::Vector3::zero, 80.0, 120.0, 0.0);

	//Animationèâä˙âª
	auto animator = new Animator(*this);

	auto readyAnimation = new Animation(*this, *animator, "shooter_ready", 0.1f);
	std::vector<SpriteComponent*> readySprites;
	for (int i = 1; i <= 5; ++i) {
		auto name = "shooter_ready" + std::to_string(i);
		readySprites.emplace_back(new SpriteComponent(*this, name.c_str(), ESpriteType::Rectangle, 90));
	}
	readyAnimation->RegisterSprite(readySprites);
	animator->RegisterAnimation(*readyAnimation);

	readySprites.clear();
	readySprites.shrink_to_fit();

	auto shotAnimation = new Animation(*this, *animator, "shooter_shot", 0.1f);
	std::vector<SpriteComponent*> runSprites;
	for (int i = 1; i <= 3; ++i) {
		auto name = "shooter_shot" + std::to_string(i);
		runSprites.emplace_back(new SpriteComponent(*this, name.c_str(), ESpriteType::Rectangle, 90));
	}
	shotAnimation->RegisterSprite(runSprites);
	animator->RegisterAnimation(*shotAnimation);

	runSprites.clear();
	runSprites.shrink_to_fit();

	animator->SetAnimation("shooter_shot");

	GetTransform().position = Math::Vector3(150.0, -190.0, 0.0);
	GetTransform().scale = Math::Vector3(1.f / 1.9f, 1.f / 1.9f, 1.f / 2.f);

	this->name = "Shooter";
}


Shooter::~Shooter() {}


void Shooter::UpdateActor(float deltaTime) {
	
}

