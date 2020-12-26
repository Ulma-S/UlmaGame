#define _USE_MATH_DEFINES
#include <cmath>
#include "Transform.h"
#include "Debug.h"

using namespace Game::Core;


Transform::Transform()
	: m_parent(nullptr)
	, m_worldTransform(Math::Matrix4::Identity)
	, scale(Math::Vector3(1.0f, 1.0f, 1.0f))
	, rotation(Math::Vector3(0.0f, 0.0f, 0.0f))
	, position(Math::Vector3(0.0f, 0.0f, 0.0f))
{}


Transform::~Transform(){}


void Transform::ComputeWorldTransform() {
	m_worldTransform = Math::Matrix4::CreateScale(scale);
	m_worldTransform *= Math::Matrix4::CreateRotationZ(rotation.z);
	m_worldTransform *= Math::Matrix4::CreateTranslation(position);
}
