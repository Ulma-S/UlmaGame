#pragma once
#include "Actor.h"

namespace Game {
	class Player : public Actor {
	public:
		Player(System::SceneManagement::Scene& scene);
		~Player();

		void Initialize() override;
		void UpdateActor(float deltaTime) override;

	private:
		int programId;
	};
};