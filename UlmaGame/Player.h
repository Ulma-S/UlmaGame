#pragma once
#include "UlmaEngine.h"
#include "IInputManager.h"

using namespace UlmaEngine;

namespace SampleGame {
	class Bullet;

	class Player : public Actor {
	public:
		Player(SceneManagement::Scene& scene);
		~Player() override;

		void Initialize() override;
		void UpdateActor(float deltaTime) override;

	private:
		InputSystem::IInputManager* m_inputManager;
		std::vector<Bullet*> m_bullets;
	};
};