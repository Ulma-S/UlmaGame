#include "Animation.h"
#include "SpriteComponent.h"
#include "Debug.h"

using namespace UlmaEngine;

Animation::Animation(Actor& owner, float duration = 0.1f, const char* animationName = "animation")
	: Component(owner)
	, m_duration(duration)
	, m_currentTime(0.0f)
	, m_spriteIdx(0)
	, m_animationName(animationName)
{}


Animation::Animation(Actor& owner, const char* animationName = "animation", float duration = 0.1f)
	: Component(owner)
	, m_duration(duration)
	, m_currentTime(0.0f)
	, m_spriteIdx(0)
	, m_animationName(animationName)
{}

Animation::~Animation() {
	std::vector <SpriteComponent*>().swap(m_sprites);
}


void Animation::Update(float deltaTime) {	
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


void Animation::RegisterSprite(SpriteComponent* sprites[]) {
	auto size = static_cast<int>(sizeof(**sprites) / sizeof(sprites));
	
	if(size <= 0) {
		return;
	}

	for(int i=0; i < size; ++i) {
		m_sprites.emplace_back(sprites[i]);
	}
}


void Animation::Initialize() {
	m_spriteIdx = 0;
	m_currentTime = 0.0f;
}
