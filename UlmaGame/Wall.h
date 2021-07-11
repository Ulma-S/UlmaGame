#pragma once
#include "UlmaEngine.h"

using namespace UlmaEngine;

namespace SampleGame {
	class Wall : public Actor {
	public:
		Wall(SceneManagement::Scene& scene, const Math::Vector2& position = Math::Vector2::zero);

		~Wall() override;
	};
}
