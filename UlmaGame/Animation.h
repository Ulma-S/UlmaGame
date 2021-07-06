#pragma once
#include <string>
#include <vector>
#include "Component.h"

namespace UlmaEngine {
	class Actor;
	class SpriteComponent;
	
	class Animation : public Component {
	public:
		Animation(Actor& owner, float duration, const char* animationName);
		Animation(Actor& owner, const char* animationName, float duration);
		~Animation() override;

		void Update(float deltaTime) override;

		const std::string& GetName() const { return m_animationName; }

		void RegisterSprite(SpriteComponent* sprites[]);

		void Initialize();

	private:
		float m_duration;
		float m_currentTime;
		int m_spriteIdx;
		std::vector<SpriteComponent*> m_sprites;
		std::string m_animationName;
	};
}
