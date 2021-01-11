#include "Actor.h"
#include "IApplicationCore.h"
#include "Transform.h"
#include "Component.h"
#include "Scene.h"
#include "Debug.h"

using namespace UlmaEngine;

Actor::Actor(SceneManagement::Scene& scene)
	: layer(0)
	, state(Active)
	, m_scene(&scene)
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


void Actor::Update(float deltaTime) {
	m_transform->ComputeWorldTransform();
	UpdateComponents(deltaTime);
	if (state == Active) {
		for (auto comp : m_components) {
			comp->enable = true;
		}
		UpdateActor(deltaTime);
		m_transform->ComputeWorldTransform();
	}
	else {
		for (auto comp : m_components) {
			comp->enable = false;
		}
	}
}


void Actor::UpdateActor(float deltaTime) {}


void Actor::UpdateComponents(float deltaTime) {
	for (auto component : m_components) {
		component->Update(deltaTime);
	}
}


void Actor::AddComponent(Component& component) {
	//既に追加されていたらreturn
	auto it = std::find(m_components.begin(), m_components.end(), &component);
	if (it != m_components.end()) return;
	
	for (; it != m_components.end(); ++it) {
		if (component.GetUpdateOrder() < (*it)->GetUpdateOrder()) {
			break;
		}
	}
	m_components.insert(it, &component);
}


void Actor::RemoveComponent(Component& component) {
	//コンポーネントが存在しなければreturn
	auto it = std::find(m_components.begin(), m_components.end(), &component);
	if (it == m_components.end()) return;
	m_components.erase(it);
}

