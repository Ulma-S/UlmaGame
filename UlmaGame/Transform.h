#pragma once
#include "Math.h"

namespace Game {
	namespace Core {
		class Transform {
		public:
			Transform();
			~Transform();

			void Rotate(float angle);
			void Translate(Math::Vector2& dir);

			void ComputeWorldTransform();

			inline Transform& GetParent() const { return *m_parent; }
			inline void SetParent(Transform& parent) { m_parent = &parent; }

			inline Math::Matrix4& GetWorldTransform() { return m_worldTransform; }
			inline Math::Vector3& GetPosition() { return m_position; }

		private:
			Transform* m_parent;
			Math::Matrix4 m_worldTransform;
			Math::Vector3 m_scale;
			Math::Vector3 m_rotation;
			Math::Vector3 m_position;
		};
	}
}