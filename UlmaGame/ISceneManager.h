#pragma once
#include "SceneList.h"

namespace System {
	namespace SceneManagement {
		class ISceneManager {
		public:
			virtual ~ISceneManager() = default;

			virtual void UpdateScene(float deltaTime) = 0;
			virtual void LoadScene(Game::ESceneType sceneType) = 0;

			virtual void AddScene(Game::ESceneType type, class SceneBase& scene) = 0;
			virtual void RemoveScene(Game::ESceneType type) = 0;
		};
	}
}