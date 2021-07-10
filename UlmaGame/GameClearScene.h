#pragma once
#include "UlmaEngine.h"

using namespace UlmaEngine;
using namespace SceneManagement;

namespace SampleGame {
	class GameClearScene : public Scene {
	public:
		GameClearScene(ISceneManager& sceneManager, const std::string& sceneName);
		~GameClearScene() override;
	};
}