#pragma once
#include "UlmaEngine.h"

using namespace UlmaEngine;

namespace SampleGame {
	class MovableTower : public Actor {
	public:
		MovableTower(SceneManagement::Scene& scene, float moveSpeed = 100.0f);
		~MovableTower() override;

		void UpdateActor(float deltaTime) override;

		inline bool GetMove() const { return m_move; }
		inline void SetMove(bool value) { m_move = value; }
	
	private:
		float m_moveSpeed;
		bool m_move;
	};
}
