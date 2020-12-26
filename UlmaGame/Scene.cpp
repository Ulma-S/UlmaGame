#include "Scene.h"
#include "ISceneManager.h"
#include "ShaderLoaderOpenGL.h"
#include "SpriteComponent.h"
#include "Actor.h"

using namespace Game::Core;

System::SceneManagement::Scene::Scene(ISceneManager& sceneManager, Game::ESceneType sceneType)
	: m_sceneManager(&sceneManager)
	, m_sceneType(sceneType)
	, m_isUpdating(false)
{
	m_sceneManager->AddScene(sceneType, *this);
}


System::SceneManagement::Scene::~Scene() {
	m_sceneManager->RemoveScene(m_sceneType);

	std::vector<Game::Core::Actor*>().swap(m_sceneActors);
	std::vector<Game::Core::Actor*>().swap(m_pendingActors);
	std::vector<Game::Core::SpriteComponent*>().swap(m_sprites);
}


void System::SceneManagement::Scene::OnEnter(){
	for (auto actor : m_sceneActors) {
		actor->Initialize();
	}
}


void System::SceneManagement::Scene::Update(float deltaTime) {
	m_isUpdating = true;
	for (auto actor : m_sceneActors) {
		actor->Update(deltaTime);
	}
	m_isUpdating = false;

	for (auto actor : m_pendingActors) {
		m_sceneActors.emplace_back(actor);
	}
	m_pendingActors.clear();
}


void System::SceneManagement::Scene::GenerateOutput(System::Core::ShaderLoaderOpenGL& shader) {
	auto it = m_sprites.begin();

	for (; it != m_sprites.end(); ++it) {
		(*it)->Draw(shader);
	}
}


void System::SceneManagement::Scene::OnExit() {
	std::vector<Game::Core::Actor*>().swap(m_sceneActors);
	std::vector<Game::Core::Actor*>().swap(m_pendingActors);
}


void System::SceneManagement::Scene::AddActor(Actor& actor) {
	//Šù‚É’Ç‰Á‚µ‚Ä‚¢‚½‚çreturn
	auto it = std::find(m_sceneActors.begin(), m_sceneActors.end(), &actor);
	if (it != m_sceneActors.end()) return;

	if (m_isUpdating) {
		m_pendingActors.emplace_back(&actor);
	}
	else {
		m_sceneActors.emplace_back(&actor);
	}
}


void System::SceneManagement::Scene::RemoveActor(Actor& actor) {
	auto it = std::find(m_sceneActors.begin(), m_sceneActors.end(), &actor);
	if (it != m_sceneActors.end()) {
		m_sceneActors.erase(it);
	}
}


void System::SceneManagement::Scene::AddSprite(Game::Core::SpriteComponent& sprite) {
	int drawOrder = sprite.GetDrawOrder();
	auto it = m_sprites.begin();
	for (; it != m_sprites.end(); ++it) {
		if (drawOrder > (*it)->GetDrawOrder()) break;
	}
	m_sprites.insert(it, &sprite);
}