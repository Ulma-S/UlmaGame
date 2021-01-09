#pragma once
#include "UlmaEngine.h"

namespace SampleGame {
	class Bullet : public Game::Core::Actor {
	public:
		Bullet(System::SceneManagement::Scene& scene);
		~Bullet();

		void Initialize() override;
		void UpdateActor(float deltaTime) override;
	};
}