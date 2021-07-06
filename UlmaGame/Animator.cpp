#include "Animator.h"
#include "Animation.h"
#include "Debug.h"

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
	//Šù‚É“o˜^‚³‚ê‚Ä‚¢‚é‚È‚ç‰½‚à‚µ‚È‚¢.
	if(it != m_animations.end()) {
		return;
	}
	m_animations[name] = &animation;
	animation.enable = false;
}


void Animator::SetAnimation(const std::string& animationName) {
	auto it = m_animations.find(animationName);

	if(it != m_animations.end()) {
		for (auto& animation : m_animations) {
			animation.second->enable = false;
			animation.second->Inactivate();
		}

		m_currentAnimation = m_animations[animationName];
		m_currentAnimation->enable = true;
		m_currentAnimation->Activate();
	}
}
