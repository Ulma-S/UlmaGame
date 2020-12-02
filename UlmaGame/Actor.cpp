#include "Actor.h"
#include "IApplicationCore.h"
#include "Component.h"
#include "Scene.h"

Game::Actor::Actor(System::SceneManagement::Scene& scene)
	: m_scene(&scene) 
	, m_state(Active)
{
	m_scene->AddActor(*this);
}


Game::Actor::~Actor(){
	m_scene->RemoveActor(*this);

	std::vector<Component*>().swap(m_components);
}


void Game::Actor::Initialize(){}


void Game::Actor::Update(float deltaTime) {
	if (m_state == Active) {
		UpdateComponents(deltaTime);
		UpdateActor(deltaTime);
	}
}


void Game::Actor::UpdateActor(float deltaTime) {}


void Game::Actor::UpdateComponents(float deltaTime) {
	for (auto component : m_components) {
		component->Update(deltaTime);
	}
}


void Game::Actor::AddComponent(Component& component) {
	//既に追加されていたらreturn
	auto it = std::find(m_components.begin(), m_components.end(), &component);
	if (it == m_components.end()) return;
	
	for (; it != m_components.end(); ++it) {
		if (component.GetUpdateOrder() < (*it)->GetUpdateOrder()) {
			break;
		}
	}
	m_components.insert(it, &component);
}


void Game::Actor::RemoveComponent(Component& component) {
	//コンポーネントが存在しなければreturn
	auto it = std::find(m_components.begin(), m_components.end(), &component);
	if (it == m_components.end()) return;
	m_components.erase(it);
}