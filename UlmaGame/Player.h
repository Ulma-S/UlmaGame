#pragma once
#include "Actor.h"

namespace System {
	namespace Core {
		class ShaderLoaderOpenGL;
	}
};

namespace Game {
	class Player : public Core::Actor {
	public:
		Player(System::SceneManagement::Scene& scene);
		~Player();

		void Initialize() override;
		void UpdateActor(float deltaTime) override;

	private:
		System::Core::ShaderLoaderOpenGL* m_shader;
	};
};