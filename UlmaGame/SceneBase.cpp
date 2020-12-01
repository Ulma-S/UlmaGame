#include "SceneBase.h"
#include "SceneManager.h"

System::SceneManagement::SceneBase::SceneBase(SceneManager& sceneManager, Game::ESceneType sceneType)
	: m_sceneManager(&sceneManager)
	, m_sceneType(sceneType)
{
	m_sceneManager->AddScene(sceneType, *this);
}


void System::SceneManagement::SceneBase::AddActor(Game::Actor& actor) {
	//Šù‚É’Ç‰Á‚µ‚Ä‚¢‚½‚çreturn
	auto it = std::find(m_sceneActors.begin(), m_sceneActors.end(), &actor);
	if (it != m_sceneActors.end()) return;
	m_sceneActors.emplace_back(&actor);
}


void System::SceneManagement::SceneBase::RemoveActor(Game::Actor& actor) {
	auto it = std::find(m_sceneActors.begin(), m_sceneActors.end(), &actor);
	if (it != m_sceneActors.end()) {
		m_sceneActors.erase(it);
	}
}