#pragma once
#include "UlmaEngine.h"

using namespace UlmaEngine;
using namespace SceneManagement;

namespace SampleGame {
	class Stage01Scene : public Scene {
	public:
		Stage01Scene(ISceneManager& sceneManager, const std::string& sceneName);
		~Stage01Scene() override;
	};
}