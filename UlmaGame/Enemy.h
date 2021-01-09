#pragma once
#include "UlmaEngine.h"

using namespace UlmaEngine;

namespace SampleGame {
	class Enemy : public Actor {
	public:
		Enemy(SceneManagement::Scene& scene);
		~Enemy();

		void Initialize() override;
		void UpdateActor(float deltaTime) override;

	private:
	};
};