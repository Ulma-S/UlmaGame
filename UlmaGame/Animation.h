#pragma once
#include <string>
#include <vector>
#include "Component.h"

namespace UlmaEngine {
	class Actor;
	class SpriteComponent;
	class Animator;
	
	class Animation : public Component {
	public:
		Animation(Actor& owner, Animator& animator, float duration = 0.1f, const char* animationName = "animation", bool loop = true);
		Animation(Actor& owner, Animator& animator, const char* animationName = "animation", float duration = 0.1f, bool loop = true);
		~Animation() override;

		void Update(float deltaTime) override;

		const std::string& GetName() const { return m_animationName; }

		void RegisterSprite(std::vector<SpriteComponent*>& sprites);

		void Activate();
		void Inactivate();

		inline bool GetLoop() const { return m_loop; }
		inline void SetLoop(bool value) { m_loop = value; }

	private:
		Animator* m_animator;
		float m_duration;
		float m_currentTime;
		int m_spriteIdx;
		std::vector<SpriteComponent*> m_sprites;
		std::string m_animationName;
		bool m_loop;
	};
}
