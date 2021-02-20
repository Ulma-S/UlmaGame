#include "Actor.h"
#include "Transform.h"
#include "Component.h"
#include "Scene.h"
#include "Debug.h"

using namespace UlmaEngine;

Actor::Actor(SceneManagement::Scene& _scene)
	: layer(0)
	, state(Active)
	, m_scene(&_scene)
	, name("Actor")
	, m_transform(new Transform())
{
	m_scene->AddActor(*this);
}


Actor::~Actor(){
	delete m_transform;

	m_scene->RemoveActor(*this);
	std::vector<Component*>().swap(m_components);
}


void Actor::Initialize(){}


void Actor::Update(float _deltaTime) {
	if (state == EActorState::Active) {
		for (auto comp : m_components) {
			comp->enable = true;
		}
		m_transform->ComputeWorldTransform();
		UpdateComponents(_deltaTime);
		UpdateActor(_deltaTime);
		m_transform->ComputeWorldTransform();
	}
	else {
		for (auto comp : m_components) {
			comp->enable = false;
		}
	}
}


void Actor::UpdateActor(float _deltaTime) {}


void Actor::UpdateComponents(float _deltaTime) {
	for (auto component : m_components) {
		component->Update(_deltaTime);
	}
}


void Actor::AddComponent(Component& _component) {
	//既に追加されていたらreturn
	auto it = std::find(m_components.begin(), m_components.end(), &_component);
	if (it != m_components.end()) return;
	
	for (; it != m_components.end(); ++it) {
		if (_component.GetUpdateOrder() < (*it)->GetUpdateOrder()) {
			break;
		}
	}
	m_components.insert(it, &_component);
}


void Actor::RemoveComponent(Component& _component) {
	//コンポーネントが存在しなければreturn
	auto it = std::find(m_components.begin(), m_components.end(), &_component);
	if (it == m_components.end()) return;
	m_components.erase(it);
}

