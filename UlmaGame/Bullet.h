#pragma once
#include "UlmaEngine.h"

namespace SampleGame {
	class Bullet : public UlmaEngine::Actor {
	public:
		Bullet(UlmaEngine::SceneManagement::Scene& _scene);
		Bullet(UlmaEngine::SceneManagement::Scene& _scene, const Math::Vector3& _position, const Math::Vector3& _moveDir);
		~Bullet();

		void Initialize() override;
		void UpdateActor(float _deltaTime) override;

		void Initialize(const Math::Vector3& _position, const Math::Vector3& _moveDir);

		inline void SetMoveDir(const Math::Vector3& _moveDir) { m_moveDir = _moveDir; }
		inline void SetMoveSpeed(float _value) { m_moveSpeed = _value; }

	private:
		Math::Vector3 m_moveDir;
		float m_moveSpeed;
	};
}