#define _USE_MATH_DEFINES
#include <cmath>
#include "Transform.h"
#include "Debug.h"

using namespace UlmaEngine;


Transform::Transform()
	: scale(Math::Vector3(1.0f, 1.0f, 1.0f))
	, rotation(Math::Vector3(0.0f, 0.0f, 0.0f))
	, position(Math::Vector3(0.0f, 0.0f, 0.0f))
	, m_parent(nullptr)
	, m_worldTransform(Math::Matrix4::Identity)
	, m_size(Math::Vector3(300.0f, 300.0f, 100.0f))
{}


Transform::~Transform(){}


void Transform::ComputeWorldTransform() {
	m_worldTransform = Math::Matrix4::Identity;
	m_worldTransform *= Math::Matrix4::CreateRotationZ(rotation.z);
	m_worldTransform *= Math::Matrix4::CreateTranslation(position);
}
