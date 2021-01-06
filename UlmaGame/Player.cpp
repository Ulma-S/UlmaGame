#include "Player.h"
#include "Debug.h"
#include "InputManagerOpenGL.h"
#include "Math.h"
#include "SpriteComponent.h"
#include "Collider.h"

using namespace System::Core::InputSystem;

Game::Player::Player(System::SceneManagement::Scene& scene) 
	: Game::Core::Actor::Actor(scene)
{
	new Game::Core::SpriteComponent(*this, Game::Core::Circle);
	new Game::Core::CircleCollider(*this, Math::Vector3(), 150.0f);
	GetTransform().scale = Math::Vector3(1.0f, 0.75f, 1.0f);
}


Game::Player::~Player(){
}


void Game::Player::Initialize(){
	
}


void Game::Player::UpdateActor(float deltaTime) {
	GetTransform().rotation.z -= InputManagerOpenGL::GetInstance().GetAxis(Horizontal);
	GetTransform().position += InputManagerOpenGL::GetInstance().GetAxis(Vertical) * GetTransform().GetUp();
}