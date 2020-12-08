#pragma once
#include "Vector.h"

namespace Game {
	namespace Core {
		class Transform {
		public:
			Transform();
			~Transform();

			void Rotate(float angle);
			void Translate(Math::Vector2& dir);

			inline Transform& GetParent() const { return *m_parent; }
			inline void SetParent(Transform& parent) { m_parent = &parent; }

			Math::Vector2 GetWorldPosition() const;
			float GetWorldRotation() const;
			Math::Vector2 GetWorldScale() const;

			Math::Vector2 localPosition;
			float localRotation;
			Math::Vector2 localScale;

		private:
			Transform* m_parent;
		};
	}
}