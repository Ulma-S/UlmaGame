#include "Animator.h"
#include "Animation.h"

using namespace UlmaEngine;

Animator::Animator(Actor& owner)
	: Component(owner)
	, m_currentAnimation(nullptr)
{
	
}


Animator::~Animator() {
	std::unordered_map<std::string, Animation*>().swap(m_animations);
}


void Animator::RegisterAnimation(Animation& animation) {
	auto name = animation.GetName();
	auto it = m_animations.find(name);
	//既に登録されているなら何もしない.
	if(it != m_animations.end()) {
		return;
	}
	m_animations[name] = &animation;
	animation.enable = false;
}


void Animator::SetAnimation(const std::string& animationName) {
	auto it = m_animations.find(animationName);

	if(it != m_animations.end()) {
		if (m_currentAnimation != nullptr) {
			m_currentAnimation->enable = false;
		}
		m_currentAnimation = m_animations[animationName];
		m_currentAnimation->enable = true;
		m_currentAnimation->Initialize();
	}
}
