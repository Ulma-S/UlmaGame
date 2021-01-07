#pragma once
#include "Actor.h"

namespace SampleGame {
	class Player : public Game::Core::Actor {
	public:
		Player(System::SceneManagement::Scene& scene);
		~Player();

		void Initialize() override;
		void UpdateActor(float deltaTime) override;

	private:
	};
};