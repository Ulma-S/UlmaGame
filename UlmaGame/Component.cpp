#include "Component.h"
#include "Actor.h"

Game::Component::Component(Actor& owner, int updateOrder)
	: m_owner(&owner)
	, m_updateOrder(updateOrder)
{}


Game::Component::~Component(){
	m_owner->RemoveComponent(*this);
}


void Game::Component::Update(float deltaTime) {

}