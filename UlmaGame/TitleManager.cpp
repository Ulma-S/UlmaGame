#include "TitleManager.h"

using namespace SampleGame;

TitleManager::TitleManager(SceneManagement::Scene& scene)
	: Actor(scene)
	, m_input(ServiceLocator::Resolve<InputSystem::IInputManager>())
{
	new SpriteComponent(*this, "title", ESpriteType::Rectangle);
}


TitleManager::~TitleManager() {}


void TitleManager::Initialize() {
	
}


void TitleManager::UpdateActor(float deltaTime) {
	if(m_input->GetKeyDown(InputSystem::EKeyCode::Space)) {
		SceneManagement::SceneManager::GetInstance().LoadScene("gameOver");
	}
}


