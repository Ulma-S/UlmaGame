#include "Component.h"
#include "Actor.h"

Component::Component(Actor& owner, int updateOrder)
	: m_owner(&owner)
	, m_updateOrder(updateOrder)
{}


Component::~Component(){}


void Component::Update(float deltaTime) {

}