#pragma once
#include "UlmaEngine.h"

using namespace UlmaEngine;
using namespace SceneManagement;

namespace SampleGame {
	class GameOverScene : public Scene {
	public:
		GameOverScene(ISceneManager& sceneManager, const std::string& sceneName);
		~GameOverScene() override;
	};
}