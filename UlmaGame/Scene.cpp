#include "Scene.h"
#include "ISceneManager.h"
#include "ShaderLoaderOpenGL.h"
#include "SpriteComponent.h"
#include "Actor.h"
#include "Collision.h"
#include "Collider.h"
#include "Debug.h"

using namespace UlmaEngine;

SceneManagement::Scene::Scene(ISceneManager& sceneManager, const std::string& sceneName)
	: m_sceneManager(&sceneManager)
	, m_sceneName(sceneName)
	, m_isUpdating(false)
{
	m_sceneManager->AddScene(sceneName, *this);
}


SceneManagement::Scene::~Scene() {
	m_sceneManager->RemoveScene(m_sceneName);

	std::vector<Actor*>().swap(m_sceneActors);
	std::vector<Actor*>().swap(m_pendingActors);
	std::vector<SpriteComponent*>().swap(m_sprites);
}


void SceneManagement::Scene::OnEnter() {
	m_isUpdating = true;
	for (auto actor : m_sceneActors) {
		actor->Initialize();
	}
	for (auto actor : m_pendingActors) {
		actor->Initialize();
	}
}


void SceneManagement::Scene::Update(float deltaTime) {
	m_isUpdating = true;
	for (auto actor : m_sceneActors) {
		actor->Update(deltaTime);
	}
	DetectCollision();
	m_isUpdating = false;

	for (auto actor : m_pendingActors) {
		m_sceneActors.emplace_back(actor);
	}
	m_pendingActors.clear();
}


void SceneManagement::Scene::GenerateOutput(Core::ShaderLoaderOpenGL& shader) {
	auto it = m_sprites.begin();

	for (; it != m_sprites.end(); ++it) {
		(*it)->Draw(shader);
 	}
}


void SceneManagement::Scene::OnExit() {
	std::vector<Actor*>().swap(m_sceneActors);
	std::vector<Actor*>().swap(m_pendingActors);
}


void SceneManagement::Scene::DetectCollision() {
	auto length = m_sceneActors.size();

	for (int i = 0; i < length; ++i) {
		for (int j = i+1; j < length; ++j) {
			Collision::ComputeIntersection(*m_sceneActors[i], *m_sceneActors[j]);
		}
	}
}


void SceneManagement::Scene::AddActor(Actor& actor) {
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


void SceneManagement::Scene::RemoveActor(Actor& actor) {
	auto it = std::find(m_sceneActors.begin(), m_sceneActors.end(), &actor);
	if (it != m_sceneActors.end()) {
		m_sceneActors.erase(it);
	}
}


void SceneManagement::Scene::AddSprite(SpriteComponent& sprite) {
	int drawOrder = sprite.GetDrawOrder();
	auto it = m_sprites.begin();
	for (; it != m_sprites.end(); ++it) {
		if (drawOrder > (*it)->GetDrawOrder()) break;
	}
	m_sprites.insert(it, &sprite);
}


void SceneManagement::Scene::RemoveSprite(SpriteComponent& sprite) {
	auto it = m_sprites.begin();
	for (; it != m_sprites.end(); ++it) {
		if ((*it) == &sprite) break;
	}
	if (it == m_sprites.end()) return;
	
	m_sprites.erase(it);
}


template<class T>
T SceneManagement::Scene::Instantiate(T _t) {
	return nullptr;
}
