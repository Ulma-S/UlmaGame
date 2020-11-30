#include "SceneBase.h"
#include "SceneManager.h"

System::SceneManagement::SceneBase::SceneBase(SceneManager& sceneManager, ESceneType sceneType)
	: m_sceneManager(&sceneManager)
	, m_sceneType(sceneType)
{
	m_sceneManager->AddScene(sceneType, *this);
}


void System::SceneManagement::SceneBase::AddActor(class Actor& actor) {
	m_sceneActors.emplace_back(&actor);
}


void System::SceneManagement::SceneBase::RemoveActor(class Actor& actor) {
	for (auto it = m_sceneActors.begin(); it != m_sceneActors.end(); ++it) {
		if (*it == &actor) {
			m_sceneActors.erase(it);
			break;
		}
	}
}