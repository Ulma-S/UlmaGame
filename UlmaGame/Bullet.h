#pragma once
#include "UlmaEngine.h"

namespace SampleGame {
	class Bullet : public UlmaEngine::Actor {
	public:
		Bullet(UlmaEngine::SceneManagement::Scene& scene);
		Bullet(UlmaEngine::SceneManagement::Scene& scene, const Math::Vector3& position, const Math::Vector3& moveDir);
		~Bullet() override;

		void Initialize() override;
		void UpdateActor(float deltaTime) override;

		void Initialize(const Math::Vector3& position, const Math::Vector3& moveDir);

		inline void SetMoveDir(const Math::Vector3& moveDir) { m_moveDir = moveDir; }
		inline void SetMoveSpeed(float value) { m_moveSpeed = value; }

	private:
		Math::Vector3 m_moveDir;
		float m_moveSpeed;
	};
}