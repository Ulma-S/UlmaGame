#pragma once
#include <string>
#include <unordered_map>

#include "Animation.h"
#include "Component.h"


namespace UlmaEngine {
	class Actor;
	class Animation;
	
	class Animator : public Component {
	public:
		Animator(Actor& owner);
		~Animator() override;

		void RegisterAnimation(Animation& animation);

		void SetAnimation(const std::string& animationName);

		inline Animation& GetCurrentAnimation() const { return *m_currentAnimation; }

		inline std::string GetCurrentAnimationName() const {
			if(m_currentAnimation != nullptr) {
				return m_currentAnimation->GetName();
			}
			return "";
		}
		
		inline bool IsEnd() const {
			if(m_currentAnimation != nullptr) {
				return m_currentAnimation->IsEnd();
			}
			return false;
		}

	private:
		Animation* m_currentAnimation;
		std::unordered_map<std::string, Animation*> m_animations;
	};
}
