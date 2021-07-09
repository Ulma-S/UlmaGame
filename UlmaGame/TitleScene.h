#pragma once
#include "UlmaEngine.h"

using namespace UlmaEngine;
using namespace SceneManagement;

namespace SampleGame {
	class TitleScene : public Scene {
	public:
		TitleScene(ISceneManager& sceneManager, const std::string& sceneName);
		~TitleScene() override;
	};
}
