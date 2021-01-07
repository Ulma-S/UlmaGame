#pragma once
#include "Actor.h"

namespace SampleGame {
	class Enemy : public Game::Core::Actor {
	public:
		Enemy(System::SceneManagement::Scene& scene);
		~Enemy();

		void Initialize() override;
		void UpdateActor(float deltaTime) override;

	private:
	};
};