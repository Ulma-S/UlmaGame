#pragma once
#include "UlmaEngine.h"

using namespace UlmaEngine;

namespace SampleGame {
	class Shooter : public Actor {
	public:
		Shooter(SceneManagement::Scene& scene);
		~Shooter() override;

		void UpdateActor(float deltaTime) override;
	};
}
