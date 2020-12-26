#define _USE_MATH_DEFINES
#include <cmath>
#include "Transform.h"
#include "Debug.h"

using namespace Game::Core;


Transform::Transform()
	: m_parent(nullptr)
	, m_worldTransform(Math::Matrix4::Identity)
	, m_scale(Math::Vector3(1.0f, 1.0f, 1.0f))
	, m_rotation(Math::Vector3(0.0f, 0.0f, 0.0f))
	, m_position(Math::Vector3(0.0f, 0.0f, 0.0f))
{}


Transform::~Transform(){}


void Transform::ComputeWorldTransform() {
	m_worldTransform = Math::Matrix4::CreateScale(m_scale);
	m_worldTransform *= Math::Matrix4::CreateRotationZ(m_rotation.z);
	m_worldTransform *= Math::Matrix4::CreateRotationX(m_rotation.x);
	m_worldTransform *= Math::Matrix4::CreateRotationY(m_rotation.y);
	m_worldTransform *= Math::Matrix4::CreateTranslation(m_position);
}
