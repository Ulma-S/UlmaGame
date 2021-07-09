#pragma once
#include "UlmaEngine.h"

using namespace UlmaEngine;

namespace SampleGame {
	class GameOverManager : public Actor{
	public:
		GameOverManager(SceneManagement::Scene& scene);
		~GameOverManager() override;

		void UpdateActor(float deltaTime) override;

	private:
		InputSystem::IInputManager* m_input;
	};
}
