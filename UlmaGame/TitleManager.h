#pragma once
#include "UlmaEngine.h"

using namespace UlmaEngine;

namespace SampleGame {
	class TitleManager : public Actor {
	public:
		TitleManager(SceneManagement::Scene& scene);
		~TitleManager() override;

		void Initialize() override;
		void UpdateActor(float deltaTime) override;

	private:
		InputSystem::IInputProvider* m_input;
	};
}
