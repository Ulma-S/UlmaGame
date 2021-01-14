#pragma once
#include <string>

namespace UlmaEngine {
	namespace Core {
		class ShaderLoaderOpenGL;
	}

	namespace SceneManagement {
		class ISceneManager {
		public:
			virtual ~ISceneManager() = default;

			virtual void UpdateScene(float _deltaTime) = 0;
			virtual void GenerateOutput(UlmaEngine::Core::ShaderLoaderOpenGL& _shader) = 0;
			virtual void LoadScene(const std::string& _sceneName) = 0;

			virtual void AddScene(const std::string& _sceneName, class Scene& _scene) = 0;
			virtual void RemoveScene(const std::string& _sceneName) = 0;
		};
	}
}