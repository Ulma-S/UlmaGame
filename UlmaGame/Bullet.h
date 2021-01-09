#pragma once
#include "UlmaEngine.h"

namespace SampleGame {
	class Bullet : public UlmaEngine::Actor {
	public:
		Bullet(UlmaEngine::SceneManagement::Scene& scene);
		~Bullet();

		void Initialize() override;
		void UpdateActor(float deltaTime) override;
	};
}