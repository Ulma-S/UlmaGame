#include "Player.h"
#include "Debug.h"

Game::Player::Player(System::SceneManagement::Scene& scene) 
	: Game::Actor::Actor(scene)
{}


Game::Player::~Player(){}


void Game::Player::Initialize(){
	System::Debug::Log("player initialized");
}


void Game::Player::UpdateActor(float deltaTime){
	//System::Debug::Log(deltaTime);
}