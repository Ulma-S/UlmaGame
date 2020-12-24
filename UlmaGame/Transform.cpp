#define _USE_MATH_DEFINES
#include <cmath>
#include "Transform.h"

using namespace Game::Core;
using namespace Math;


Transform::Transform()
	: localPosition(0.0f, 0.0f)
	, localRotation(0.0f)
	, localScale(1.0f, 1.0f)
	, m_parent(nullptr)
{}


Transform::~Transform(){}


void Transform::CalcWorldTransform() {
	m_worldTransform = Math::Matrix4::CreateScale(m_scale);
	m_worldTransform *= Math::Matrix4::CreateRotationZ(m_rotation.z);
	m_worldTransform *= Math::Matrix4::CreateRotationX(m_rotation.x);
	m_worldTransform *= Math::Matrix4::CreateRotationY(m_rotation.y);
	m_worldTransform *= Math::Matrix4::CreateTranslation(m_position);
}


Vector2 Transform::GetWorldPosition() const{
	Vector2 vec;
	vec = localPosition;
	Transform* parent = m_parent;
	while (true) {
		if (parent == nullptr) break;
		vec += parent->localPosition;
		parent = parent->m_parent;
	}
	delete parent;
	return vec;
}


float Transform::GetWorldRotation() const{
	float worldRot = localRotation;
	Transform* parent = m_parent;
	while (true) {
		if (parent == nullptr) break;
		worldRot += parent->localRotation;
		parent = parent->m_parent;
	}
	delete parent;
	return worldRot;
}


Vector2 Transform::GetWorldScale() const{
	Vector2 worldScale;
	worldScale = localScale;
	Transform* parent = m_parent;
	while (true) {
		if (parent == nullptr) break;
		worldScale.Dot(parent->localScale);
		parent = parent->m_parent;
	}
	delete parent;
	return worldScale;
}


void Transform::Rotate(float angle) {
	localRotation += angle;
}


void Transform::Translate(Vector2& dir) {
	localPosition.x += dir.x;
	localPosition.y += dir.y;
}