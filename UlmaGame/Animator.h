#pragma once
#include <string>
#include <unordered_map>
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

	private:
		Animation* m_currentAnimation;
		std::unordered_map<std::string, Animation*> m_animations;
	};
}
