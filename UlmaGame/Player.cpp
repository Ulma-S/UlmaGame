#include "Player.h"
#include "Debug.h"
#include "InputManagerOpenGL.h"
#include "Math.h"
#include "SpriteComponent.h"
#include "Collider.h"
#include "Collision.h"

using namespace System::Core::InputSystem;

SampleGame::Player::Player(System::SceneManagement::Scene& scene) 
	: Game::Core::Actor::Actor(scene)
{
	new Game::Core::SpriteComponent(*this, Game::Core::Circle);
	new Game::Core::CircleCollider(*this, Math::Vector3(), 150.0f);
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

	auto num = this->GetComponent<Game::Core::Collider2D>()->hitData.size();
	System::Debug::Log(num);
}