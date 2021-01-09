#include "Player.h"

using namespace UlmaEngine::InputSystem;

SampleGame::Player::Player(SceneManagement::Scene& scene) 
	: Actor::Actor(scene)
{
	new SpriteComponent(*this, Circle);
	new CircleCollider(*this, Math::Vector3(), 150.0f);
	GetTransform().position = Math::Vector3(300.0, 300.0, 0.0);
	GetTransform().scale = Math::Vector3(1.0f, 0.75f, 1.0f);
}


SampleGame::Player::~Player(){
}


void SampleGame::Player::Initialize(){
	
}


void SampleGame::Player::UpdateActor(float deltaTime) {
	GetTransform().rotation.z -= InputManagerOpenGL::GetInstance().GetAxis(Horizontal);
	GetTransform().position += InputManagerOpenGL::GetInstance().GetAxis(Vertical) * GetTransform().GetUp();

	auto num = this->GetComponent<Collider2D>()->hitData.size();
	Debug::Log(num);
}
