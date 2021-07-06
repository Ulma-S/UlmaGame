#pragma once
#include "Component.h"
#include "Vector.h"

namespace UlmaEngine {
	class Actor;

	class Rigidbody2D : public Component {
	public:
		Rigidbody2D(Actor& owner);
		Rigidbody2D(Actor& owner, float gravityScale);

		~Rigidbody2D() override;

		void Update(float deltaTime) override;

		inline void AddVelocity(const Math::Vector2& value) { m_velocity += value; }
		inline void AddVelocityX(float value) { m_velocity.x += value; }
		inline void AddVelocityY(float value) { m_velocity.y += value; }

		inline void AddAcceleration(const Math::Vector2& value) { m_acceleration += value; }
		inline void AddAccelerationX(float value) { m_acceleration.x += value; }
		inline void AddAccelerationY(float value) { m_acceleration.y += value; }
		
		inline void SetVelocityX(float value) { m_velocity.x = value; }
		inline void SetVelocityY(float value) { m_velocity.y = value; }
		inline Math::Vector2 GetVelocity() const { return m_velocity; }
		inline void SetVelocity(const Math::Vector2& velocity) { m_velocity = velocity; }

		inline void SetAccelerationX(float value) { m_acceleration.x = value; }
		inline void SetAccelerationY(float value) { m_acceleration.y = value; }
		inline Math::Vector2 GetAcceleration() const { return m_acceleration; }
		inline void SetAcceleration(const Math::Vector2& acceleration) { m_acceleration = acceleration; }
		
		inline float GetGravityScale() const { return m_gravityScale; }
		inline void SetGravityScale(float value) { m_gravityScale = value; }

		inline bool GetEnableGravity() const { return m_enableGravity; }
		inline void SetEnableGravity(bool value) { m_enableGravity = value; }

	private:
		Math::Vector2 m_velocity;
		Math::Vector2 m_acceleration;
		float m_gravityScale;
		bool m_enableGravity;
	};
};