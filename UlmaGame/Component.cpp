#include "Component.h"
#include "Actor.h"

Game::Component::Component(Actor& owner, int updateOrder)
	: m_owner(&owner)
	, m_updateOrder(updateOrder)
{}


Game::Component::~Component(){}


void Game::Component::Update(float deltaTime) {

}