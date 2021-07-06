#include "Ground.h"

SampleGame::Ground::Ground(SceneManagement::Scene& _scene)
	: Actor::Actor(_scene)
{
	GetTransform().position = Math::Vector3(0.0, -700.0, 0.0);
	GetTransform().scale = Math::Vector3(4.0, 3.0, 1.0);

	new SpriteComponent(*this, "brown", ESpriteType::Rectangle, 10);
	new BoxCollider2D(*this, Math::Vector3::zero, 1200.0, 900.0, 0.0);
	this->name = "Ground";
}


SampleGame::Ground::~Ground() {

}


void SampleGame::Ground::Initialize() {

}


void SampleGame::Ground::UpdateActor(float deltaTime) {

}