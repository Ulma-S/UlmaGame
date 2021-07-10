#pragma once
#include "UlmaEngine.h"

using namespace UlmaEngine;

namespace SampleGame {
	class GameClearManager : public Actor {
	public:
		GameClearManager(SceneManagement::Scene& owner);
		~GameClearManager() override;

		void UpdateActor(float deltaTime) override;

	private:
		InputSystem::IInputProvider* m_input;
	};
}
