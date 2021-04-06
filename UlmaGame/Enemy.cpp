#include "Enemy.h"

SampleGame::Enemy::Enemy(SceneManagement::Scene& _scene)
	: Actor::Actor(_scene) 
{
	new SpriteComponent(*this, ESpriteType::Rectangle, 110);
	//new CircleCollider(*this, Math::Vector3(), 150.0f);
	new BoxCollider2D(*this, Math::Vector3::zero, 300.0, 300.0, 0.0);
	GetTransform().position = Math::Vector3(-300.0, 0.0, 0.0);
	GetTransform().scale = Math::Vector3(1.0f, 0.75f, 1.0f);
	name = "Enemy";
}


SampleGame::Enemy::~Enemy(){}


void SampleGame::Enemy::Initialize(){}


void SampleGame::Enemy::UpdateActor(float _deltaTime){}