#include "Animation.h"
#include "Animator.h"
#include "SpriteComponent.h"
#include "Debug.h"

using namespace UlmaEngine;

Animation::Animation(Actor& owner, Animator& animator, float duration = 0.1f, const char* animationName = "animation")
	: Component(owner)
	, m_animator(&animator)
	, m_duration(duration)
	, m_currentTime(0.0f)
	, m_spriteIdx(0)
	, m_animationName(animationName)
{}


Animation::Animation(Actor& owner, Animator& animator, const char* animationName = "animation", float duration = 0.1f)
	: Component(owner)
	, m_animator(&animator)
	, m_duration(duration)
	, m_currentTime(0.0f)
	, m_spriteIdx(0)
	, m_animationName(animationName)
{}


Animation::~Animation() {
	std::vector<SpriteComponent*>().swap(m_sprites);
}


void Animation::Update(float deltaTime) {
	if(&(m_animator->GetCurrentAnimation()) != this) {
		Inactivate();
		return;
	}
	
	for(int i=0; i < m_sprites.size(); ++i) {
		if(i == m_spriteIdx) {
			m_sprites[i]->enable = true;
		}else {
			m_sprites[i]->enable = false;
		}
	}
	
	m_currentTime += deltaTime;
	if(m_currentTime > m_duration) {
		m_currentTime = 0.0f;

		if(m_spriteIdx == m_sprites.size() - 1) {
			m_spriteIdx = 0;
		}else {
			m_spriteIdx++;
		}
	}
}


void Animation::RegisterSprite(std::vector<SpriteComponent*>& sprites) {
	auto size = sprites.size();
	
	if(size <= 0) {
		return;
	}

	for(int i=0; i < size; ++i) {
		if (sprites[i] == nullptr) continue;
		m_sprites.emplace_back(sprites[i]);
	}
}


void Animation::Activate() {
	m_spriteIdx = 0;
	m_currentTime = 0.0f;
}


void Animation::Inactivate() {
	for (auto sprite : m_sprites) {
		sprite->enable = false;
	}
}
