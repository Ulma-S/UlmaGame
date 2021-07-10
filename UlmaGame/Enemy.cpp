#include "Enemy.h"

SampleGame::Enemy::Enemy(SceneManagement::Scene& _scene)
	: Actor::Actor(_scene)
{
	new SpriteComponent(*this, "brown", ESpriteType::Rectangle, 110);
	new BoxCollider2D(*this, Math::Vector3(0, -300, 0), 300.0, 300.0, 0.0);
	GetTransform().position = Math::Vector3(300.0, -50.0, 0.0);
	GetTransform().scale = Math::Vector3(1.0f, 1.0f, 1.0f);
	name = "Enemy";
}


SampleGame::Enemy::~Enemy(){}


void SampleGame::Enemy::Initialize(){}


void SampleGame::Enemy::UpdateActor(float deltaTime) {
}
