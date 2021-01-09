#pragma once
#include "Actor.h"

using namespace UlmaEngine;

namespace SampleGame {
	class Player : public Actor {
	public:
		Player(SceneManagement::Scene& scene);
		~Player();

		void Initialize() override;
		void UpdateActor(float deltaTime) override;

	private:
	};
};