#pragma once
#include <string>
#include <functional>

namespace UlmaEngine {
	namespace Core {
		class ShaderLoaderOpenGL;
	}

	namespace SceneManagement {
		class Scene;
		
		class ISceneManager {
		public:
			virtual ~ISceneManager() = default;

			virtual void UpdateScene(float _deltaTime) = 0;
			virtual void GenerateOutput(UlmaEngine::Core::ShaderLoaderOpenGL& _shader) = 0;
			virtual bool LoadScene(const std::string& _sceneName) = 0;

			virtual void AddScene(const std::string& _sceneName, class Scene& _scene) = 0;
			virtual void RemoveScene(const std::string& _sceneName) = 0;

			virtual void BindScenes(const std::function<Scene*(const std::string& sceneName)>& func) = 0;
		};
	}
}