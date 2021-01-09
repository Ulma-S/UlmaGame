#pragma once
#include "SceneList.h"

namespace UlmaEngine {
	namespace Core {
		class ShaderLoaderOpenGL;
	}

	namespace SceneManagement {
		class ISceneManager {
		public:
			virtual ~ISceneManager() = default;

			virtual void UpdateScene(float deltaTime) = 0;
			virtual void GenerateOutput(UlmaEngine::Core::ShaderLoaderOpenGL& shader) = 0;
			virtual void LoadScene(ESceneType sceneType) = 0;

			virtual void AddScene(ESceneType type, class Scene& scene) = 0;
			virtual void RemoveScene(ESceneType type) = 0;
		};
	}
}