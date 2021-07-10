#include "GameClearManager.h"

using namespace SampleGame;

GameClearManager::GameClearManager(SceneManagement::Scene& owner)
	: Actor(owner)
	, m_input(ServiceLocator::Resolve<InputSystem::IInputProvider>())
{
	new SpriteComponent(*this, "gameClear", ESpriteType::Rectangle);
}


GameClearManager::~GameClearManager() {}


void GameClearManager::UpdateActor(float deltaTime) {
	if(m_input->GetKeyDown(InputSystem::EKeyCode::Space)) {
		SceneManagement::SceneManager::GetInstance().LoadScene("title");
	}
}
