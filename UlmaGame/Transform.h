#pragma once
#include "Math.h"

namespace UlmaEngine {
	class Transform {
	public:
		Transform();
		~Transform();

		void ComputeWorldTransform();

		inline Transform& GetParent() const { return *m_parent; }
		inline void SetParent(Transform& parent) { m_parent = &parent; }

		inline Math::Matrix4& GetWorldTransform() { return m_worldTransform; }

		inline Math::Vector3 GetRight() { return Math::Vector3(Math::Cos(rotation.z), Math::Sin(rotation.z), 0.0f); }
		inline Math::Vector3 GetUp() { return Math::Vector3(-Math::Sin(rotation.z), Math::Cos(rotation.z), 0.0f); }

		inline Math::Vector3 GetSize() { return m_size; }

		//ワールド座標
		Math::Vector3 scale;
		Math::Vector3 rotation;
		Math::Vector3 position;

		//ローカル座標
		Math::Vector3 localScale;
		Math::Vector3 localRotation;
		Math::Vector3 localPosition;

	private:
		Transform* m_parent;
		Math::Matrix4 m_worldTransform;
		Math::Vector3 m_size;	//ピクセル数
	};
}