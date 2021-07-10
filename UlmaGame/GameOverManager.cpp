#include "GameOverManager.h"

SampleGame::GameOverManager::GameOverManager(SceneManagement::Scene& scene)
	: Actor(scene)
	, m_input(ServiceLocator::Resolve<InputSystem::IInputManager>()) {
	new SpriteComponent(*this, "gameOver", ESpriteType::Rectangle);
}


SampleGame::GameOverManager::~GameOverManager() {}


void SampleGame::GameOverManager::UpdateActor(float deltaTime) {
	if(m_input->GetKeyDown(InputSystem::Space)) {
		SceneManagement::SceneManager::GetInstance().LoadScene("title");
	}
}
