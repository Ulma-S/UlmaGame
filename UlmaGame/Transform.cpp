#include "Transform.h"
#include "Debug.h"

using namespace UlmaEngine;


Transform::Transform()
	: scale(Math::Vector3(1.0f, 1.0f, 1.0f))
	, rotation(Math::Vector3(0.0f, 0.0f, 0.0f))
	, position(Math::Vector3(0.0f, 0.0f, 0.0f))
	, localScale(Math::Vector3(1.0f, 1.0f, 1.0f))
	, localRotation(Math::Vector3(0.0f, 0.0f, 0.0f))
	, localPosition(Math::Vector3(0.0f, 0.0f, 0.0f))
	, m_parent(nullptr)
	, m_worldTransform(Math::Matrix4::Identity)
	, m_size(Math::Vector3(300.0f, 300.0f, 100.0f))
{}


Transform::~Transform(){}


void Transform::ComputeWorldTransform() {
	if (m_parent != nullptr) {
		position = localPosition + m_parent->position;
		rotation = localRotation + m_parent->rotation;
		scale = Math::Vector3(localScale.x * m_parent->scale.x, localScale.y * m_parent->scale.y, localScale.z * m_parent->scale.z);
	}
	m_worldTransform = Math::Matrix4::Identity;
	m_worldTransform *= Math::Matrix4::CreateRotationZ(rotation.z);
	m_worldTransform *= Math::Matrix4::CreateTranslation(position);
}
