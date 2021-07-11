#pragma once
#include "UlmaEngine.h"

using namespace UlmaEngine;

namespace SampleGame {
	class Background : public Actor {
	public:
		Background(SceneManagement::Scene& scene);

		~Background();

		void UpdateActor(float deltaTime) override;
	};
}
