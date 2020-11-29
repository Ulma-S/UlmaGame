#include "Actor.h"
#include "ApplicationCoreBase.h"
#include "Component.h"

Actor::Actor(class IApplicationCore& appCore) 
	: m_appCore(&appCore) 
	, m_state(Active)
{
	m_appCore->AddActor(*this);
}


Actor::~Actor(){
	m_appCore->RemoveActor(*this);
}


void Actor::Initialize(){}


void Actor::Update(float deltaTime) {
	if (m_state == Active) {
		UpdateComponents(deltaTime);
		UpdateActor(deltaTime);
	}
}


void Actor::UpdateActor(float deltaTime) {

}


void Actor::UpdateComponents(float deltaTime) {

}


void Actor::AddComponent(Component& component) {
	m_components.emplace_back(&component);
}


void Actor::RemoveComponent(Component& component) {

}