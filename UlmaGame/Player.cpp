#include "Player.h"
#include "Debug.h"
#include "InputManagerOpenGL.h"
#include "Math.h"
#include "SpriteComponent.h"

using namespace System::Core::InputSystem;

Game::Player::Player(System::SceneManagement::Scene& scene) 
	: Game::Core::Actor::Actor(scene)
{
	new Game::Core::SpriteComponent(*this);
}


Game::Player::~Player(){
}


void Game::Player::Initialize(){
	
}


void Game::Player::UpdateActor(float deltaTime){
	GetTransform().rotation.z -= InputManagerOpenGL::GetInstance().GetAxis(Horizontal);
	GetTransform().position += InputManagerOpenGL::GetInstance().GetAxis(Vertical) * GetTransform().GetUp();
}