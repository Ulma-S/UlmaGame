#pragma once
#include "UlmaEngine.h"

using namespace UlmaEngine;

namespace SampleGame {
	class Bullet;

	class Player : public Actor {
	public:
		Player(SceneManagement::Scene& scene);
		~Player();

		void Initialize() override;
		void UpdateActor(float deltaTime) override;

	private:
		std::vector<Bullet*> m_bullets;
		float m_moveSpeed;
		int m_bulletCount;
	};
};