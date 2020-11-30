#include "Actor.h"
#include "ApplicationCoreBase.h"
#include "Component.h"

Game::Actor::Actor(System::SceneManagement::SceneBase& scene)
	: m_scene(&scene) 
	, m_state(Active)
{
}


Game::Actor::~Actor(){
}


void Game::Actor::Initialize(){}


void Game::Actor::Update(float deltaTime) {
	if (m_state == Active) {
		UpdateComponents(deltaTime);
		UpdateActor(deltaTime);
	}
}


void Game::Actor::UpdateActor(float deltaTime) {

}


void Game::Actor::UpdateComponents(float deltaTime) {

}


void Game::Actor::AddComponent(Component& component) {
	m_components.emplace_back(&component);
}


void Game::Actor::RemoveComponent(Component& component) {

}