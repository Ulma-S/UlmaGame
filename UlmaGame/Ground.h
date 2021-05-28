#pragma once
#include "UlmaEngine.h"

using namespace UlmaEngine;

namespace SampleGame {
	class Ground : public Actor {
	public:
		Ground(SceneManagement::Scene& _scene);
		~Ground();

		void Initialize() override;
		void UpdateActor(float deltaTime) override;

	private:

	};
};