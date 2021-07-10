#include "Component.h"
#include "Actor.h"

using namespace UlmaEngine;

Component::Component(Actor& owner, int updateOrder)
	: enable(true)
	, m_owner(&owner)
	, m_updateOrder(updateOrder)
{
	m_owner->AddComponent(*this);
}


Component::~Component(){
	m_owner->RemoveComponent(*this);
}


void Component::Update(float deltaTime) {}
