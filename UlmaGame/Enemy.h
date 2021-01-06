#pragma once
#include "Actor.h"

namespace Game {
	class Enemy : public Core::Actor {
	public:
		Enemy(System::SceneManagement::Scene& scene);
		~Enemy();

		void Initialize() override;
		void UpdateActor(float deltaTime) override;

	private:
	};
};