#include "Enemy.h"
#include "SpriteComponent.h"
#include "Collider.h"
#include "Math.h"
#include "Debug.h"

SampleGame::Enemy::Enemy(SceneManagement::Scene& scene)
	: Actor::Actor(scene) 
{
	new SpriteComponent(*this, Circle);
	new CircleCollider(*this, Math::Vector3(), 150.0f);
	GetTransform().position = Math::Vector3(0.0, 0.0, 0.0);
	GetTransform().scale = Math::Vector3(1.0f, 0.75f, 1.0f);
}


SampleGame::Enemy::~Enemy(){}


void SampleGame::Enemy::Initialize(){}


void SampleGame::Enemy::UpdateActor(float deltaTime){}